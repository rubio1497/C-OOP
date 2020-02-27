#pragma once
#ifndef BATTLE_H
#define BATTLE_H
#include "Otaku.h"
#include "course.h"

struct Character
{
	char type; //monster or player
	bool alive;//alive or dead
	void* instance;//pointer to instance 指向腳色
};

class Battle: public Otaku, course
{
public:
	Battle(Otaku*, int);//產生小怪
	Battle(Otaku*);//產生大魔王
	~Battle();
	bool nextActor(void);   //換哪個腳色進攻
	int getTurnCount(void) const;   //計算換誰進攻
	int getPlayerCount(void) const;  
	int getMonsterCount(void) const;
	
	void LetBattle();   //打架
	void SetColor(int) const;  //遊戲血條數量顏色
	void display() const;  //展示玩家怪物血條
private:
	Character* ActionList;    
	int n_mon;
	int type_mon;
	int n_turn;
};
#endif // !BATTLE_H
