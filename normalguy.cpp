#include "normalguy.h"
#include <iostream>
#include <fstream>
using namespace std;

normalguy::normalguy()
{
	friends = 1;
	setName("normalguy");
	setEnergy(70);
	setCredits(30);
	setAttack(60);
	setConfidence(60);
	setMoney(50);
	setMaxenergy(70);

	Setbackpack_weight(0);
	Setbackpack_weight_limit(300);
	Setbackpack_slot_limit(5);
	Setbackpack_slot(0);

	setArmor(nullptr);
	setWeapon(nullptr);
}

normalguy::normalguy(const normalguy& a)
{
	friends = a.getFriends();
	setName(a.getName());
	setEnergy(a.getEnergy());
	setCredits(a.getCredits());
	setAttack(a.getAttack());
	setConfidence(a.getConfidence());
	setMoney(a.getMoney());
	setMaxenergy(a.getMaxenergy());

	Setbackpack_weight(a.getbackpack_weight());
	Setbackpack_weight_limit(a.getbackpack_weight_limit());
	Setbackpack_slot_limit(a.getbackpack_slot_limit());
	Setbackpack_slot(a.getbackpack_slot());

	setArmor(a.getArmor());
	setWeapon(a.getWeapon());
}

void normalguy::setFriends(int a)
{
	friends = a;
}

int normalguy::getFriends()const
{
	return friends;
}

void normalguy::specialSkill()
{
	cout << "朋友的鼓勵，能量回升" << endl;
	setEnergy(getEnergy() + getFriends()*5);
}

string normalguy::serialize()
{
	string a;
	cout << "enter your file name: " ;
	cin >> a;
	ofstream save(a);
	string s;
	s += getName() + ' ' + to_string(getEnergy()) + ' ' + to_string(getCredits()) + ' ' + to_string(getMoney()) + ' ' + to_string(getAttack()) + ' ' + to_string(getConfidence());
	save << s;
	return s;
}

