#pragma once
#ifndef PENCILLEAD_H
#define PENCILLEAD_H
#include "items\armorItem.h"

class pencillead: public armorItem
{
public:
	pencillead()
	{
		setItemMoneyreq(80);
		setItemName("Pencil lead");
		setItemEffect("the power of defense incressing 40");
		setItemWeight(120);
		setItemType('p');
		Setdefense_increment(40);
	}
};
#endif // ! PENCILLEAD_H
