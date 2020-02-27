#pragma once
#ifndef SHOP_H
#define SHOP_H
#include <iostream>
#include "pencil.h"
#include "calculator.h"
#include "drink.h"
#include "eraser.h"
#include "food.h"
#include "pencillead.h"
#include "Otaku.h"
#include "normalguy.h"
#include "wholepack.h"
using namespace std;

class Shop
{
public:
	Shop();
	void ShopInformation(Otaku*);
	void rest(Otaku*);  //¸É Energy
	Otaku* turnWork(Otaku*);
};
#endif // !SHOP_H
