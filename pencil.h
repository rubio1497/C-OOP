#pragma once
#ifndef PENCIL_H
#define PENCIL_H
#include "items\weaponItem.h"
class pencil: public weaponItem
{
public:
	pencil()
	{
		setItemMoneyreq(80);
		setItemName("pencil");
		setItemEffect("the power of attack incressing 20");
		setItemWeight(100);
		setItemType('P');
		Setattack_increment(20);
	}
};
#endif // !PENCIL_H
