#pragma once
#ifndef CALCULATOR_H
#define CALCULATOR_H
#include "items\weaponItem.h"

class calculator: public weaponItem
{
public:
	calculator()
	{
		setItemMoneyreq(700);
		setItemName("calculaor");
		setItemEffect("the power of attack incressing 100");
		setItemWeight(300);
		setItemType('P');
		Setattack_increment(100);
	}
};
#endif // !CALCULATOR_H
