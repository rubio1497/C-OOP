#include "Shop.h"
#include <Windows.h>
#include <iostream>
using namespace std;

Shop::Shop()
{

}

void Shop::ShopInformation(Otaku* a)
{
	int choice1 = 1;
	int choice;
	Item* b;
	cout << "�аݭn�R�ƻ�?" << endl << endl;
	while (choice1 == 1)
	{
		cout << "(1) drink�A30����" << endl;
		cout << "(2) food�A100����" << endl;
		cout << "(3) eraser�A50����" << endl;
		cout << "(4) pencillead�A80����" << endl;
		cout << "(5) calculator�A700����" << endl;
		cout << "(6) pencil�A80����" << endl;
		cin >> choice;
		switch (choice)
		{
			case 1:
			{
				b = new drink();
				if (a->getMoney() >= 30)
				{
					if(a->putItem(b))
						a->setMoney(a->getMoney() - 30);
				}
				else
					cout << "���������L�k�ʶR!" << endl;
				break;
			}
			case 2:
			{
				b = new food();
				if (a->getMoney() >= 100)
				{
					if(a->putItem(b))
						a->setMoney(a->getMoney() - 100);
				}
				else
					cout << "���������L�k�ʶR!" << endl;

				break;
			}
			case 3:
			{
				b = new eraser();
				if (a->getMoney() >= 50)
				{
					if(a->putItem(b))
						a->setMoney(a->getMoney() - 50);
				}
				else
					cout << "���������L�k�ʶR!" << endl;

				break;
			}
			case 4:
			{
				b = new pencillead();
				if (a->getMoney() >= 80)
				{
					if(a->putItem(b))
						a->setMoney(a->getMoney() - 80);
				}
				else
					cout << "���������L�k�ʶR!" << endl;

				break;
			}
			case 5:
			{
				b = new calculator();
				if (a->getMoney() >= 700)
				{
					if(a->putItem(b));
						a->setMoney(a->getMoney() - 700);
				}
				else
					cout << "���������L�k�ʶR!" << endl;

				break;
			}
			case 6:
			{
				b = new pencil();
				if (a->getMoney() >= 80)
				{
					if(a->putItem(b))
						a->setMoney(a->getMoney() - 80);
				}
				else
					cout << "���������L�k�ʶR!" << endl;

				
				break;
			}

		}
		b = nullptr;
		cout << "�O�_�٭n�ʶR��L���~?" << endl << endl;
		cout << "(1) �O" << endl << "(2) �_" << endl;
		cin >> choice1;

		Sleep(100);
		system("cls");
	}
	
}

void Shop::rest(Otaku* a)
{
	cout << "����O�q��{~~~" << endl;
	a->setEnergy(a->getMaxenergy());
	cout << "Energy���ɺ��F�O" << endl;

	Sleep(500);
	system("cls");
}

Otaku* Shop::turnWork(Otaku* a)
{
	armorItem* c = nullptr;
	weaponItem* d = nullptr;
	Item** z = nullptr;
	string b;
	int p,q,r;
	cout << "�w��i��ɵ��A�d�ݧA���Ǥ��ƥH�ιs�ο��O�_��i��ɵ�" << endl;

	if (a->getCredits() >= 30 && a->getMoney() >= 100)
	{
		b = a->getName();
		p = a->getCredits();
		q = a->getMoney() - 100;
		r = a->getbackpack_slot();

		if (a->getArmor() != nullptr)
			c = new armorItem(*a[0].getArmor());

		if (a->getArmor() != nullptr)
			d = new weaponItem(*a[0].getWeapon());

		if (r > 0)
		{
			z = new Item*[r];
			for (int i = 0; i < r; i++)
				z[i] = new Item(*a[0].getBackpack(i));
		}

		a = nullptr;
		a = new normalguy[1];
		
		a->setName(b);
		a->setCredits(p);
		a->setMoney(q);

		if (c != nullptr)
			a->setArmor(c);
	
		if (d != nullptr)
			a->setWeapon(d);

		if (r > 0)
		{
			for (int i = 0; i < r; i++)
				a->putItem(z[i]);

		}

		cout << "�ɯŦ����q�H!" << endl << endl ;
	}
	else if (a->getCredits() >= 60 && a->getMoney() >= 300)
	{
		b = a->getName();
		p = a->getCredits();
		q = a->getMoney() - 100;
		r = a->getbackpack_slot();

		if (a->getArmor() != nullptr)
			c = new armorItem(*a[0].getArmor());

		if (a->getArmor() != nullptr)
			d = new weaponItem(*a[0].getWeapon());

		if (r > 0)
		{
			z = new Item*[r];
			for (int i = 0; i < r; i++)
				z[i] = new Item(*a->getBackpack(i));
		}

		a = nullptr;
		a = new wholepack[1];
		a->setName(b);
		a->setCredits(p);
		a->setMoney(q);

		if (c != nullptr)
			a->setArmor(c);

		if (d != nullptr)
			a->setWeapon(d);

		if (r > 0)
		{
			for (int i = 0; i < r; i++)
				a->putItem(z[i]);
		}

		cout << "�ɯŦ��ӧQ��!" << endl << endl;
	}
	else
	{
		cout << endl << "�s�ο��ξǤ�����! ����ɵ�!!!" << endl;
		Sleep(800);
		system("cls");
	}


	return a;
}