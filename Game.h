#pragma once
#ifndef GAME_H
#define GAME_H
#include <conio.h>
#include <windows.h>
#include "fields/Field.h"
#include "Battle.h"
#include "Shop.h"
#include "Otaku.h"
class Game
{
public:
	Game();
	void play();
	void drama();
	void sound_effect();
	void sound_effect1();
	void sound_effect2();
	void sound_effect3();
	void sound_effect4();
};
#endif // !GAME_H
