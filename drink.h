#pragma once
#ifndef DRINK_H
#define DRINK_H
#include "items\consumableItem.h"

class drink: public consumableItem
{
public:
	drink()
	{
		setItemMoneyreq(30);
		setItemName("energy drink");
		setItemEffect("energy restoring 5");
		setItemWeight(50);
		setItemType('D');
		setnumber(0);
	}
};
#endif // !DRINK_H
