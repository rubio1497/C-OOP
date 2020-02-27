#pragma once
#ifndef ERASER_H
#define ERASER_H
#include "items\armorItem.h"

class eraser: public armorItem
{
public:
	eraser()
	{
		setItemMoneyreq(50);
		setItemName("eraser");
		setItemEffect("the power of defensw incressing 20");
		setItemWeight(100);
		setItemType('E');
		Setdefense_increment(20);
	}
};
#endif // !ERASER_H
