#include <iostream>
#include <fstream>
#include "Otaku.h"
#include "calculator.h"
#include "drink.h"
#include "eraser.h"
#include "food.h"
#include "pencillead.h"
#include "pencil.h"

using namespace std;

Otaku::Otaku()
{
	setName("Otaku");
	setEnergy(40);
	setCredits(0);
	setAttack(50);
	setConfidence(50);
	setMoney(50);
	setMaxenergy(40);

	Setbackpack_weight(0);
	Setbackpack_weight_limit(150);
	Setbackpack_slot_limit(3);
	Setbackpack_slot(0);
	
	weapon = nullptr;
	armor = nullptr;
	/*
	backpack = new Item*[getbackpack_slot_limit()];
	for (int i = 0; i < getbackpack_slot_limit(); i++)
		backpack[i] = nullptr;
	
	for (int i = 0; i < getbackpack_slot_limit() ; i++)
		backpack.push_back(nullptr);
		*/
}

Otaku::Otaku(string a) 
{
	setName(a);
	setEnergy(40);
	setCredits(50);
	setAttack(50);
	setConfidence(50);
	setMoney(950);
	setMaxenergy(40);

	Setbackpack_weight(0);
	Setbackpack_weight_limit(150);
	Setbackpack_slot_limit(3);
	Setbackpack_slot(0);
	
	weapon = nullptr;
	armor = nullptr;
	/*
	backpack = new Item*[getbackpack_slot_limit()];
	for (int i = 0; i < getbackpack_slot_limit(); i++)
		backpack[i] = nullptr;
	
	for (int i = 0; i < getbackpack_slot_limit(); i++)
		backpack.push_back(nullptr);
		*/
}

Otaku::Otaku(const Otaku& a)
{
	setName(a.getName());
	setEnergy(a.getEnergy());
	setCredits(a.getCredits());
	setAttack(a.getAttack());
	setConfidence(a.getConfidence());
	setMoney(a.getMoney());
	setMaxenergy(getMaxenergy());

	Setbackpack_weight(a.getbackpack_weight());
	Setbackpack_weight_limit(a.getbackpack_weight_limit());
	Setbackpack_slot_limit(a.getbackpack_slot_limit());
	Setbackpack_slot(a.getbackpack_slot());
	backpack.clear(); //clear vector
	backpack.insert(backpack.begin(),a.backpack.begin(), a.backpack.end());

	weapon = new weaponItem(*a.weapon);
	armor = new armorItem(*a.armor);
}

Otaku::~Otaku()
{
	delete[]weapon;
	delete[]armor;

	if (getbackpack_slot() > 0)
	{
		for (int i = 0; i < getbackpack_slot(); i++)
			backpack.erase(backpack.begin() + i);
	}
}


void Otaku::setName(string a)
{
	name = a;
}

string Otaku::getName(void) const
{
	return name;
}


void Otaku::setEnergy(int a)
{
	energy = a;
}

int Otaku::getEnergy() const
{
	return energy;
}


void Otaku::setCredits(int a)
{
	credits = a;
}

int Otaku::getCredits() const
{
	return credits;
}

void Otaku::setMoney(int a)
{
	money = a;
}

int Otaku::getMoney() const
{
	return money;
}

void Otaku::setAttack(int a)
{
	attack = a;
}

int Otaku::getAttack() const
{
	if (weapon == nullptr)
		return attack;
	else
		return attack + weapon->attack_increment;
}

void Otaku::setConfidence(int a)
{
	confidence = a;
}

int Otaku::getConfidence() const
{
	if (armor == nullptr)
		return confidence;
	else
		return confidence + armor->defense_increment;
}

void Otaku::setMaxenergy(int a)
{
	max_energy = a;
}

int Otaku::getMaxenergy() const
{
	return max_energy;
}

void Otaku::specialSkill()    //特殊攻擊
{
	cout << "宅男沒有特殊技能" << endl;
}

string Otaku::serialize()  //存檔
{
	string a;
	cout << "enter your file name: ";
	cin >> a;
	ofstream save(a);
	string s;
	s += getName() + ' ' + to_string(getEnergy()) + ' ' + to_string(getCredits()) + ' ' + to_string(getMoney()) + ' ' + to_string(getAttack()) + ' ' + to_string(getConfidence());
	save << s;
	return s;
}

void Otaku::Setbackpack_weight(int a)
{
	if (a >= backpack_weight_limit)
		backpack_weight = backpack_weight_limit;
	else if (a < 0)
		backpack_weight = 0;
	else
		backpack_weight = a;
}

void Otaku::Setbackpack_weight_limit(int a)
{
	backpack_weight_limit = a;
}

void Otaku::Setbackpack_slot_limit(int a)
{
	backpack_slot_limit = a;
}

void Otaku::Setbackpack_slot(int a)
{
	if (a >= backpack_slot_limit)
		backpack_slot = backpack_slot_limit;
	else if (a < 0)
		backpack_slot = 0;
	else
		backpack_slot = a;
}

int Otaku::getbackpack_weight() const
{
	return backpack_weight;
}

int Otaku::getbackpack_weight_limit() const
{
	return backpack_weight_limit;
}

int Otaku::getbackpack_slot_limit() const
{
	return backpack_slot_limit;
}

int Otaku::getbackpack_slot() const
{
	return backpack_slot;
}

void Otaku::displaypocket()
{
	cout << getName() << "的錢包: " << getMoney() << endl;
}

bool Otaku::equipWeapon(weaponItem* a)
{
	if (weapon[0].getItemType() == a->getItemType())
	{
		cout << "已裝備相同的道具" << endl;
		return false;
	}
	else
	{
		weapon = nullptr;
		weapon = new weaponItem(*a);
		return true;
	}
}

bool Otaku::equipArmor(armorItem* a)
{
	if (armor[0].getItemType() == a->getItemType())
	{
		cout << "已裝備相同的道具" << endl;
		return false;
	}
	else
	{
		armor = nullptr;
		armor = new armorItem(*a);
		return true;
	}
}

void Otaku::useConsumable(int a) //給選項
{
	int i = 0;
	if (a > backpack_slot)
	{
		cout << "無效選擇" << endl;
	}
	else
	{
		if (backpack[a - 1][0].getItemType() == 'D')
		{
			i = getEnergy();
			setEnergy(i + 5);
			removeItem(a);
		}
		else if (backpack[a - 1][0].getItemType() == 'F')
		{
			i = getEnergy();
			setEnergy(i + 15);
			removeItem(a);
		}
		else
			cout << "此選項不是能量補給品" << endl;
	}
}

bool Otaku::putItem(Item* a)
{
	int temp = 0;

	if (weapon == nullptr && armor == nullptr)
		temp = 0;
	else if (weapon == nullptr)
		temp = armor->getItemWeight();
	else if (armor == nullptr)
		temp = weapon->getItemWeight();
	else
		temp = weapon->getItemWeight() + armor->getItemWeight();

	if (a->getItemWeight() + getbackpack_weight() + temp > getbackpack_weight_limit())
	{
		cout << "背包過重，放不下" << endl;
		return false;
	}
	else if (getbackpack_slot() >= getbackpack_slot_limit())
	{
		cout << "超過背包能容納數量，放不下" << endl;
		return false;
	}
	else
	{
		Setbackpack_slot(getbackpack_slot() + 1);
		Setbackpack_weight(a->getItemWeight() + getbackpack_weight());

		if (a->getItemType() == 'D')
			backpack.push_back(new drink());
		else if (a->getItemType() == 'F')
			backpack.push_back(new food());
		else if (a->getItemType() == 'P')
			backpack.push_back(new pencil());
		else if (a->getItemType() == 'C')
			backpack.push_back(new calculator());
		else if (a->getItemType() == 'p')
			backpack.push_back(new pencillead());
		else
			backpack.push_back(new eraser());

		return true;
	}
	
}

void Otaku::takeItem(int a)
{
	if (a > getbackpack_slot() || a < 1 || backpack[a - 1] == nullptr)
		cout << "無效選擇" << endl;
	else if (backpack[a - 1]->getItemType() == 'D' || backpack[a - 1]->getItemType() == 'F')
		useConsumable(a);
	else if (backpack[a - 1]->getItemType() == 'C')
	{
		if (weapon != nullptr)
		{
			weaponItem* g = new weaponItem(*weapon);
			backpack.push_back(g);
			
		}
		weapon = nullptr;
		weapon = new calculator();
		backpack.erase(backpack.begin() + a - 1);
		Setbackpack_slot(getbackpack_slot() - 1);
	}
	else if (backpack[a - 1]->getItemType() == 'E')
	{
		if (armor != nullptr)
		{
			armorItem* g = new armorItem(*armor);
			backpack.push_back(g);
			
		}
		armor = nullptr;
		armor = new eraser();
		backpack.erase(backpack.begin() + a - 1);
		Setbackpack_slot(getbackpack_slot() - 1);
	}
	else if (backpack[a - 1]->getItemType() == 'P')
	{
		if (weapon != nullptr)
		{
			weaponItem* g = new weaponItem(*weapon);
			backpack.push_back(g);
			
		}
		weapon = nullptr;
		weapon = new pencil();
		backpack.erase(backpack.begin() + a - 1);
		Setbackpack_slot(getbackpack_slot() - 1);
	}
	else
	{
		if (armor != nullptr)
		{
			armorItem* g = new armorItem(*armor);
			backpack.push_back(g);
			
		}
		armor = nullptr;
		armor = new pencillead();
		backpack.erase(backpack.begin() + a - 1);
		Setbackpack_slot(getbackpack_slot() - 1);
	}
}

void Otaku::displaybackpack()
{
	cout << getName() << "的背包:" << endl;
	if (getbackpack_slot() > 0)
	{
		for (int i = 0; i < getbackpack_slot(); i++)
			cout << "(" << i + 1 << ") " << backpack[i]->getItemName() << endl;
	}
	else
		cout << "背包沒有東西" << endl;
}

void Otaku::removeItem(int a)
{
	if (a > getbackpack_slot() || a < 1 || backpack[a - 1] == nullptr)
		cout << "無效選擇" << endl;
	else
	{
		Setbackpack_slot(getbackpack_slot() - 1);
		Setbackpack_weight(getbackpack_weight() - backpack[a-1]->getItemWeight());
		backpack.erase(backpack.begin() + a - 1);
	}
}

weaponItem* Otaku::getWeapon()const
{
	if (weapon != nullptr)
		return weapon;
	else
		return nullptr;
}

armorItem* Otaku::getArmor()const
{
	if (armor != nullptr)
		return armor;
	else
		return nullptr;
}

Item* Otaku::getBackpack(int a)const
{
	if (backpack[a] != nullptr)
		return backpack[a];
	else
		return nullptr;
}

void Otaku::setWeapon(weaponItem* a)
{
	weapon = new weaponItem(*a);
}

void Otaku::setArmor(armorItem* a)
{
	armor = new armorItem(*a);
}

void Otaku::setBackpack(Item* a)
{
	backpack[getbackpack_slot()] = new Item(*a);
	Setbackpack_slot(getbackpack_slot() + 1);
}

Otaku& Otaku::operator=(const Otaku& a)
{
	if (this == &a)  //相同地址就回傳本身地址
		return *this;

	armor = new armorItem(*a.getArmor());
	weapon = new weaponItem(*a.getWeapon());

	setName(a.getName());
	setEnergy(a.getEnergy());
	setCredits(a.getCredits());
	setAttack(a.getAttack());
	setConfidence(a.getConfidence());
	setMoney(a.getMoney());
	setMaxenergy(getMaxenergy());

	Setbackpack_weight(a.getbackpack_weight());
	Setbackpack_weight_limit(a.getbackpack_weight_limit());
	Setbackpack_slot_limit(a.getbackpack_slot_limit());
	Setbackpack_slot(a.getbackpack_slot());
	
	backpack.clear(); //clear vector
	backpack.insert(backpack.begin(), a.backpack.begin(), a.backpack.end());

	return *this;
}