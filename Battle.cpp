#include "Battle.h"
#include <iostream>
#include <Windows.h>
#include <iomanip>
#include "loadingsmall.h"
#include "loadingbig.h"
#include "FJJ.h"
#include <conio.h>
using namespace std;

Battle::Battle(Otaku* a, int b)//產生小怪
{
	n_turn = 0;
	n_mon = b;
	ActionList = new Character[n_mon + 1];
	ActionList[0].type = 'p';
	ActionList[0].instance = &a[0]; //指向角色的指標
	if (static_cast<Otaku*>(ActionList[0].instance)->getEnergy() > 0)
		ActionList[0].alive = true;

	for (int i = 1; i < n_mon + 1; i++)
	{
		type_mon = rand() % 2;
		ActionList[i].type = 'm';    //後面是怪物
		ActionList[i].alive = true;   //先讓全部怪物預設活著
		if (type_mon)
			ActionList[i].instance = new loadingsmall(); //指向角色的指標
		else
			ActionList[i].instance = new loadingbig(); //指向角色的指標
	}

}

Battle::Battle(Otaku* a)//產生大魔王
{
	n_turn = 0;
	n_mon = 1;
	type_mon = 0;
	ActionList = new Character[2];
	ActionList[0].instance = &a[0]; //指向角色的指標
	ActionList[0].type = 'p';
	if (static_cast<Otaku*>(ActionList[0].instance)->getEnergy() > 0)
		ActionList[0].alive = true;
	
	ActionList[1].instance = new FJJ(); //指向角色的指標
	ActionList[1].type = 'm';    //後面是怪物
	ActionList[1].alive = true;   //先讓全部怪物預設活著

}

Battle::~Battle()
{
	delete[]ActionList;
}

bool Battle::nextActor(void)
{
	int i = n_turn % (1 + n_mon);
	if (ActionList[i].alive)
		return true;
	else
		return false;
}

int Battle::getTurnCount(void) const
{
	return n_turn;
}

int Battle::getPlayerCount(void) const
{
	if (ActionList[0].alive)
		return 1;
	else
		return 0;
}

int Battle::getMonsterCount(void) const
{
	int j = 0;
	for (int i = 0; i < n_mon + 1; i++)
	{
		if (ActionList[i].alive)
			j++;
	}
	return j;
}


void Battle::LetBattle()
{
	bool condition = 1;
	int cal = 0; //計算幾隻怪物死忙
	char choice = '0';
	int choice1;
	while (condition)
	{
		display();
		if (nextActor())
		{
			if (ActionList[n_turn % (n_mon + 1)].type == 'p') //是玩家
			{
				//戰鬥中的部分
				cout << static_cast<Otaku*>(ActionList[0].instance)->getName() << "進攻" << endl;
				cout << "(g)普通攻擊" << endl << "(h)特殊技能" << endl << "(j)查看背包" << endl ;
				choice = _getche();
				cout << endl;
				if (choice == 'g')
				{
					for (int i = 1; i < n_mon + 1; i++)
					{
						if (ActionList[i].alive)
						{
							cout << "(" << i << ")" << static_cast<course*>(ActionList[i].instance)->name << endl;
						}
					}
					cin >> choice1;

					if (static_cast<Otaku*>(ActionList[0].instance)->getAttack() > static_cast<course*>(ActionList[choice1].instance)->defense)
						static_cast<course*>(ActionList[choice1].instance)->setTime(static_cast<course*>(ActionList[choice1].instance)->getTime() - 15);
					else
						static_cast<course*>(ActionList[choice1].instance)->setTime(static_cast<course*>(ActionList[choice1].instance)->getTime() - 5);

					
					//打完看看是否能有經驗值之類物品
					if (static_cast<course*>(ActionList[choice1].instance)->getTime() <= 0)
					{
						ActionList[choice1].alive = false;
						cout << static_cast<course*>(ActionList[choice1].instance)->name << " pass!" << endl;
						static_cast<Otaku*>(ActionList[0].instance)->setCredits(static_cast<Otaku*>(ActionList[0].instance)->getCredits() + static_cast<course*>(ActionList[choice1].instance)->credits);
						cout << "獲得 " << static_cast<course*>(ActionList[choice1].instance)->credits << " 學分 " << endl;
						static_cast<Otaku*>(ActionList[0].instance)->setMoney(static_cast<Otaku*>(ActionList[0].instance)->getMoney() + static_cast<course*>(ActionList[choice1].instance)->money);
						cout << "零用錢 " << static_cast<course*>(ActionList[choice1].instance)->money << " 元 " << endl;
					}
				}
				else if (choice == 'h')
					static_cast<Otaku*>(ActionList[0].instance)->specialSkill();
				else
				{
					static_cast<Otaku*>(ActionList[0].instance)->displaybackpack();
					if (static_cast<Otaku*>(ActionList[0].instance)->getbackpack_slot())
					{
						cout << "選擇道具: ";
						cin >> choice1;
						cout << endl;
						static_cast<Otaku*>(ActionList[0].instance)->takeItem(choice1);
					}
				}
			}
			else
			{
				cout << static_cast<course*>(ActionList[n_turn % (n_mon + 1)].instance)->name << "攻擊" << endl;
				if (static_cast<course*>(ActionList[n_turn % (n_mon + 1)].instance)->attack > static_cast<Otaku*>(ActionList[0].instance)->getConfidence())
					static_cast<Otaku*>(ActionList[0].instance)->setEnergy(static_cast<Otaku*>(ActionList[0].instance)->getEnergy() - 15);
				else
					static_cast<Otaku*>(ActionList[0].instance)->setEnergy(static_cast<Otaku*>(ActionList[0].instance)->getEnergy() - 5);

				if (static_cast<Otaku*>(ActionList[0].instance)->getEnergy() <= 0)
				{
					static_cast<Otaku*>(ActionList[0].instance)->setEnergy(0);
					ActionList[choice].alive = false;
					cout << static_cast<Otaku*>(ActionList[0].instance)->getName() << "戰敗 !" << endl;
				}
			}
		}
		++n_turn;

		for (int i = 1; i < n_mon + 1; i++)  //查看戰鬥是否結束(怪物死光)
		{
			if (ActionList[i].alive == 0)
				cal++;
		}

		if (cal != n_mon)  //在這才做判斷
			cal = 0;

		if (cal == n_mon || static_cast<Otaku*>(ActionList[0].instance)->getEnergy() <= 0)  //如果戰鬥結束條件成立，跳出迴圈
			condition = 0;
		else
			condition = 1;
			
		Sleep(500);
		system("cls");
	}

	cout << "戰鬥結束" << endl;
	Sleep(500);
	system("cls");
}

void Battle::SetColor(int color = 7) const //網路查到的印出有顏色的正方形程式碼
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

void Battle::display() const
{
	int temp, temp1;
	//製作玩家的部分
	cout << "************************************" << endl;
	cout << "Player Name: " << static_cast<Otaku*>(ActionList[0].instance)->getName() << endl;
	temp = static_cast<Otaku*>(ActionList[0].instance)->getMaxenergy() / 10;
	temp1 = static_cast<Otaku*>(ActionList[0].instance)->getEnergy() / temp;
	cout << "Energy: ";
	for (int j = 0; j < temp1; j++)
	{
		SetColor(153);
		cout << "■";
		SetColor(7);
	}
	cout << setw(1) << static_cast<Otaku*>(ActionList[0].instance)->getEnergy() << "/" << static_cast<Otaku*>(ActionList[0].instance)->getMaxenergy() << endl;
	//製作怪物的部分
	for (int i = 0; i < n_mon; i++)
		cout << "************************************";
	cout << endl;
	
	for (int i = 1; i < n_mon + 1; i++)
		if(ActionList[i].alive)
			cout << "Monster Name: " << static_cast<course*>(ActionList[i].instance)->name << setw(14) << "    ";
	cout << endl;

	for (int i = 1; i < n_mon + 1; i++)
	{
		if (ActionList[i].alive)
		{
			temp = static_cast<course*>(ActionList[i].instance)->max_Time / 10;
			temp1 = static_cast<course*>(ActionList[i].instance)->getTime() / temp;
			cout << "Time: ";
			for (int j = 0; j < temp1; j++)
			{
				SetColor(153);
				cout << "■";
				SetColor(7);
			}
			cout << setw(2) << static_cast<course*>(ActionList[i].instance)->getTime() << "/" << static_cast<course*>(ActionList[i].instance)->max_Time << setw(3) << "  ";
		}
	}

	cout << endl;
}