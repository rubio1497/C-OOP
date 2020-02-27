#include "wholepack.h"
#include <fstream>
#include <iostream>
#include <ctime>
using namespace std;

wholepack::wholepack()
{
	girlfriend = 1;
	setName("normalguy");
	setEnergy(140);
	setCredits(60);
	setAttack(70);
	setConfidence(70);
	setMoney(100);
	setMaxenergy(140);
	setFriends(5);

	Setbackpack_weight(0);
	Setbackpack_weight_limit(600);
	Setbackpack_slot_limit(8);
	Setbackpack_slot(0);

	setArmor(nullptr);
	setWeapon(nullptr);
}

wholepack::wholepack(const wholepack& a)
{
	setAffection(a.getAffection());
	setName(a.getName());
	setEnergy(a.getEnergy());
	setCredits(a.getCredits());
	setAttack(a.getAttack());
	setConfidence(a.getConfidence());
	setMoney(a.getMoney());
	setMaxenergy(a.getMaxenergy());
	setFriends(a.getFriends());

	Setbackpack_weight(a.getbackpack_weight());
	Setbackpack_weight_limit(a.getbackpack_weight_limit());
	Setbackpack_slot_limit(a.getbackpack_slot_limit());
	Setbackpack_slot(a.getbackpack_slot());

	setArmor(a.getArmor());
	setWeapon(a.getWeapon());
}

void wholepack::specialSkill()
{
	cout << "吃女友的手作餅乾看看能不能補充能量" << endl;
	int bonus = rand() % 2;
	if (bonus)
	{
		cout << "不好吃qq，拉肚子扣損能量" << endl;
		setEnergy(getEnergy() - 20);

	}
	else
	{
		cout << "太好吃啦，有精神了" << endl;
		setEnergy(getEnergy() + 20);
	}
}

void wholepack::setAffection(bool a)
{
	girlfriend = a;
}

bool wholepack::getAffection()const
{
	return girlfriend;
}

string wholepack::serialize()
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

