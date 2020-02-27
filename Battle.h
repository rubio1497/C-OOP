#pragma once
#ifndef BATTLE_H
#define BATTLE_H
#include "Otaku.h"
#include "course.h"

struct Character
{
	char type; //monster or player
	bool alive;//alive or dead
	void* instance;//pointer to instance ���V�}��
};

class Battle: public Otaku, course
{
public:
	Battle(Otaku*, int);//���ͤp��
	Battle(Otaku*);//���ͤj�]��
	~Battle();
	bool nextActor(void);   //�����Ӹ}��i��
	int getTurnCount(void) const;   //�p�⴫�ֶi��
	int getPlayerCount(void) const;  
	int getMonsterCount(void) const;
	
	void LetBattle();   //���[
	void SetColor(int) const;  //�C������ƶq�C��
	void display() const;  //�i�ܪ��a�Ǫ����
private:
	Character* ActionList;    
	int n_mon;
	int type_mon;
	int n_turn;
};
#endif // !BATTLE_H
