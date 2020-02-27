#pragma once
#ifndef  OTAKU_H
#define OTAKU_H
#include <string>
#include <vector>
#include "items\armorItem.h"
#include "items\weaponItem.h"
using namespace std;

class Otaku
{
public:
	Otaku();   //建構子
	Otaku(string); 
	Otaku(const Otaku&);
	Otaku& operator=(const Otaku&);
	~Otaku();
	void setName(string);   //一些setfunction
	string getName(void) const;
	void setEnergy(int);    //能量(血條)
	int getEnergy() const;
	void setCredits(int);   //學分數
	int getCredits() const;
	void setMoney(int);
	int getMoney() const;   //零用錢
	void setAttack(int);
	int getAttack() const;
	void setConfidence(int);  //信心(防禦用)
	int getConfidence() const;
	void setMaxenergy(int);
	int getMaxenergy() const;

	//有關於背包
	void Setbackpack_weight(int);   //設定背包重量
	void Setbackpack_weight_limit(int);  //不同等級有背包重量限制
	void Setbackpack_slot_limit(int);  //以及背包內物品數量限制
	void Setbackpack_slot(int);
	int getbackpack_weight() const;
	int getbackpack_weight_limit() const;
	int getbackpack_slot_limit() const;
	int getbackpack_slot() const;

	
	bool equipWeapon(weaponItem*);  //看玩家是否有配帶武器
	bool equipArmor(armorItem*);    //看玩家是否有配戴防禦裝備
	void useConsumable(int); //給選項看是使用food 還是 drink
	bool putItem(Item*);    //將物品搬進背包
	void takeItem(int);    //拿取背包物品
	void displaybackpack();  //展示背包
	void removeItem(int);  //移除背包物品

	weaponItem* getWeapon()const;   //未來方便換武器用
	armorItem* getArmor()const;
	Item* getBackpack(int)const;

	void setWeapon(weaponItem*);  //換武器時使用
	void setArmor(armorItem*);
	void setBackpack(Item*);
	
	
	//錢包
	void displaypocket();


	virtual void specialSkill();  //特殊攻擊
	virtual string serialize();   //存檔



private:
	string name; // 玩家名稱
	int energy; // 目前血量
	int credits; // 學分數
			
	int attack; // 玩家攻擊力
	int confidence; // 玩家防禦力
	int max_energy; // 最大血量
	int money; // 錢

	vector<Item*> backpack;  //背包
	weaponItem* weapon; // weapon item you use now
	armorItem* armor; // armor item you use now
	int backpack_weight; // current weight of player’s backpack
	int backpack_weight_limit; // limit on weight of backpack
	int backpack_slot_limit; // limit on number of backpack’s slots
	int backpack_slot;
};
#endif // ! OTAKU_H
