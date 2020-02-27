#pragma once
#ifndef  FOOD_H
#define FOOD_H
#include "items\consumableItem.h"

class food: public consumableItem
{
public:
	food()
	{
		setItemMoneyreq(100);
		setItemName("energy food");
		setItemEffect("energy restoring 15");
		setItemWeight(100);
		setItemType('F');
		setnumber(0);
	}
};
#endif // ! FOOD_H
