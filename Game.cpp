#include "Game.h"
#include <ctime>
#include <iostream>
#pragma comment(lib, "Winmm.lib")
using namespace std;
enum { ROAD = 0, WALL = 1, START = 200, STOP = 201, SHOP = 202, FINAL = 203};
Game::Game()
{
	
}

void Game::sound_effect()
{
	PlaySound("1.wav", NULL, SND_ASYNC); //需修改路徑
}

void Game::sound_effect1()
{
	PlaySound("2.wav", NULL, SND_ASYNC); //需修改路徑
}

void Game::sound_effect2()
{
	PlaySound("3.wav", NULL, SND_ASYNC); //需修改路徑
}

void Game::sound_effect3()
{
	PlaySound("4.wav", NULL, SND_ASYNC); //需修改路徑
}

void Game::sound_effect4()
{
	PlaySound("5.wav", NULL, SND_ASYNC); //需修改路徑
}

void Game::drama()
{
	sound_effect();
	Sleep(600);
	cout << "經過";
	Sleep(200); 
	cout << "多年的";
	Sleep(200);
	cout << "努力，";
	Sleep(200);
	cout << "小明終於";
	Sleep(400);
	cout << "考到成大機械。" << endl;
	Sleep(2000);
	sound_effect();
	cout << "但殊不";
	Sleep(300);
	cout << "知這只";
	Sleep(300);
	cout << "是試煉";
	Sleep(300); 
	cout << "的開始";
	Sleep(500);
	for (int i = 0; i < 6; i++)
	{
		cout << ".";
		Sleep(500);
	}
	system("cls");
}

void Game::play()
{
	srand(time(NULL));
	int shopping;
	char choice;
	string player_name;
	Shop m;
	Battle* x;
	drama();
	Otaku* k;

	const char* v = "maze1.txt";
	Field b(v, 1, 1, 5, 5);
	cout << "請輸入玩家姓名: " ;
	getline(cin, player_name, '\n');
	k = new Otaku(player_name);
	system("cls");
	b.SetName(" Grade 1 ");
	cout << "歡迎來到:" << b.getMapName()  << endl;
	b.display();
	sound_effect2();

	while (!(b.getMapSymbol(b.getCurrentPositionX(), b.getCurrentPositionY()) == STOP) && k[0].getEnergy() > 0)
	{
		cout << "(w) 上移" << endl << "(a) 左移" << endl << "(s) 下移" << endl << "(d) 右移" << endl << "(f) 背包" << endl << "(e) 錢包" << endl;
		choice = _getche();
		system("cls");
		if (choice == 'f')
		{
			int choose;
			k[0].displaybackpack();
			cout << endl;
			cout << "是否使用道具?" << endl << "(1) 是" << endl << "(2) 否" << endl;
			cin >> choose;
			if (choose == 1)
			{
				if (k[0].getbackpack_slot() > 0)
				{
					k[0].displaybackpack();
					cin >> choose;
					k[0].takeItem(choose);
				}
				else
					cout << "沒東西無法採取動作" << endl;
			}
			b.display();
		}
		else if (choice == 'e')
		{
			k[0].displaypocket();
			b.display();
		}
		else
		{
			b.move(choice);
			b.display();
		}


		if (b.getMapSymbol(b.getCurrentPositionX(), b.getCurrentPositionY()) == STOP)
		{
			PlaySound(NULL, NULL, SND_FILENAME);
			cout << "進入傳送門!" << endl;
			Sleep(1000);
			system("cls");
			cout << "Loading";
			for (int i = 0; i < 4; i++)
			{
				Sleep(1000);
				cout << ".";
			}
			break;
		}
		else if (b.getMapSymbol(b.getCurrentPositionX(), b.getCurrentPositionY()) == SHOP)
		{
			PlaySound(NULL, NULL, SND_FILENAME);
			sound_effect3();
			cout << "歡迎光臨 myshop，請問要甚麼服務?" << endl << endl;
			cout << "(1) 補充 Energy " << endl << "(2) 購買商品" << endl << "(3) 轉職(p.s. 學分要求)" << endl;
			cin >> shopping;
			if (shopping == 3)
				k = m.turnWork(&k[0]);
			else if (shopping == 1)
				m.rest(k);
			else
				m.ShopInformation(k);

			PlaySound(NULL, NULL, SND_FILENAME);
			b.display();
			sound_effect2();
		}
		else if (b.getMapSymbol(b.getCurrentPositionX(), b.getCurrentPositionY()) == ROAD && (rand()%8 == 1))
		{
			PlaySound(NULL, NULL, SND_FILENAME);
			Sleep(500);
			x = new Battle(k,rand() % 2 + 1);
			sound_effect1();
			x->LetBattle();
			PlaySound(NULL, NULL, SND_FILENAME);
			x = nullptr;
			b.display();
			sound_effect2();
		}
	
	}

	v = "maze2.txt";
	Field q(v, 1, 1, 5, 5);
	system("cls");
	q.SetName(" Grade 2 ");
	cout << "歡迎來到:" << q.getMapName() << endl;
	q.display();
	sound_effect2();

	while (!(q.getMapSymbol(q.getCurrentPositionX(), q.getCurrentPositionY()) == STOP) && k[0].getEnergy() > 0)
	{
		cout << "(w) 上移" << endl << "(a) 左移" << endl << "(s) 下移" << endl << "(d) 右移" << endl << "(f) 背包" << endl << "(e) 錢包" << endl;
		choice = _getche();
		system("cls");
		if (choice == 'f')
		{
			int choose;
			k[0].displaybackpack();
			cout << endl;
			cout << "是否使用道具?" << endl << "(1) 是" << endl << "(2) 否" << endl;
			cin >> choose;
			if (choose == 1)
			{
				if (k[0].getbackpack_slot() > 0)
				{
					k[0].displaybackpack();
					cin >> choose;
					k[0].takeItem(choose);
				}
				else
					cout << "沒東西無法採取動作" << endl;
			}
			q.display();
		}
		else if (choice == 'e')
		{
			k[0].displaypocket();
			q.display();
		}
		else
		{
			q.move(choice);
			q.display();
		}

		if (q.getMapSymbol(b.getCurrentPositionX(), q.getCurrentPositionY()) == SHOP)
		{
			PlaySound(NULL, NULL, SND_FILENAME);
			sound_effect3();
			cout << "歡迎光臨 myshop，請問要甚麼服務?" << endl << endl;
			cout << "(1) 補充 Energy " << endl << "(2) 購買商品" << endl << "(3) 轉職(p.s. 學分要求)" << endl;
			cin >> shopping;
			if (shopping == 3)
				k = m.turnWork(&k[0]);
			else if (shopping == 1)
				m.rest(k);
			else
				m.ShopInformation(k);

			PlaySound(NULL, NULL, SND_FILENAME);
			q.display();
			sound_effect2();
		}
		else if (q.getMapSymbol(q.getCurrentPositionX(), q.getCurrentPositionY()) == ROAD && (rand() % 8 == 1))
		{
			PlaySound(NULL, NULL, SND_FILENAME);
			Sleep(500);
			x = new Battle(k, rand() % 2 + 1);
			sound_effect1();
			x->LetBattle();
			PlaySound(NULL, NULL, SND_FILENAME);
			x = nullptr;
			q.display();
			sound_effect2();
		}
		else if (q.getMapSymbol(q.getCurrentPositionX(), q.getCurrentPositionY()) == FINAL)
		{
			PlaySound(NULL, NULL, SND_FILENAME);
			Sleep(500);
			x = new Battle(k);
			sound_effect1();
			x->LetBattle();
			PlaySound(NULL, NULL, SND_FILENAME);
			x = nullptr;
			q.display();
			break;
		}
	}

	system("cls");
	if (k->getEnergy() <= 0)
	{
		sound_effect4();
		cout << " 遊戲結束，你輸了科科科科科~~" << endl;
		Sleep(5000);
	}
	else
	{
		cout << " 遊戲結束，恭喜你贏了! " << endl;
		Sleep(5000);
	}
}