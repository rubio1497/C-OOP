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
	PlaySound("1.wav", NULL, SND_ASYNC); //�ݭק���|
}

void Game::sound_effect1()
{
	PlaySound("2.wav", NULL, SND_ASYNC); //�ݭק���|
}

void Game::sound_effect2()
{
	PlaySound("3.wav", NULL, SND_ASYNC); //�ݭק���|
}

void Game::sound_effect3()
{
	PlaySound("4.wav", NULL, SND_ASYNC); //�ݭק���|
}

void Game::sound_effect4()
{
	PlaySound("5.wav", NULL, SND_ASYNC); //�ݭק���|
}

void Game::drama()
{
	sound_effect();
	Sleep(600);
	cout << "�g�L";
	Sleep(200); 
	cout << "�h�~��";
	Sleep(200);
	cout << "�V�O�A";
	Sleep(200);
	cout << "�p���ש�";
	Sleep(400);
	cout << "�Ҩ즨�j����C" << endl;
	Sleep(2000);
	sound_effect();
	cout << "����";
	Sleep(300);
	cout << "���o�u";
	Sleep(300);
	cout << "�O�շ�";
	Sleep(300); 
	cout << "���}�l";
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
	cout << "�п�J���a�m�W: " ;
	getline(cin, player_name, '\n');
	k = new Otaku(player_name);
	system("cls");
	b.SetName(" Grade 1 ");
	cout << "�w��Ө�:" << b.getMapName()  << endl;
	b.display();
	sound_effect2();

	while (!(b.getMapSymbol(b.getCurrentPositionX(), b.getCurrentPositionY()) == STOP) && k[0].getEnergy() > 0)
	{
		cout << "(w) �W��" << endl << "(a) ����" << endl << "(s) �U��" << endl << "(d) �k��" << endl << "(f) �I�]" << endl << "(e) ���]" << endl;
		choice = _getche();
		system("cls");
		if (choice == 'f')
		{
			int choose;
			k[0].displaybackpack();
			cout << endl;
			cout << "�O�_�ϥιD��?" << endl << "(1) �O" << endl << "(2) �_" << endl;
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
					cout << "�S�F��L�k�Ĩ��ʧ@" << endl;
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
			cout << "�i�J�ǰe��!" << endl;
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
			cout << "�w����{ myshop�A�аݭn�ƻ�A��?" << endl << endl;
			cout << "(1) �ɥR Energy " << endl << "(2) �ʶR�ӫ~" << endl << "(3) ��¾(p.s. �Ǥ��n�D)" << endl;
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
	cout << "�w��Ө�:" << q.getMapName() << endl;
	q.display();
	sound_effect2();

	while (!(q.getMapSymbol(q.getCurrentPositionX(), q.getCurrentPositionY()) == STOP) && k[0].getEnergy() > 0)
	{
		cout << "(w) �W��" << endl << "(a) ����" << endl << "(s) �U��" << endl << "(d) �k��" << endl << "(f) �I�]" << endl << "(e) ���]" << endl;
		choice = _getche();
		system("cls");
		if (choice == 'f')
		{
			int choose;
			k[0].displaybackpack();
			cout << endl;
			cout << "�O�_�ϥιD��?" << endl << "(1) �O" << endl << "(2) �_" << endl;
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
					cout << "�S�F��L�k�Ĩ��ʧ@" << endl;
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
			cout << "�w����{ myshop�A�аݭn�ƻ�A��?" << endl << endl;
			cout << "(1) �ɥR Energy " << endl << "(2) �ʶR�ӫ~" << endl << "(3) ��¾(p.s. �Ǥ��n�D)" << endl;
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
		cout << " �C�������A�A��F������~~" << endl;
		Sleep(5000);
	}
	else
	{
		cout << " �C�������A���ߧAĹ�F! " << endl;
		Sleep(5000);
	}
}