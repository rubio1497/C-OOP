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
	Otaku();   //�غc�l
	Otaku(string); 
	Otaku(const Otaku&);
	Otaku& operator=(const Otaku&);
	~Otaku();
	void setName(string);   //�@��setfunction
	string getName(void) const;
	void setEnergy(int);    //��q(���)
	int getEnergy() const;
	void setCredits(int);   //�Ǥ���
	int getCredits() const;
	void setMoney(int);
	int getMoney() const;   //�s�ο�
	void setAttack(int);
	int getAttack() const;
	void setConfidence(int);  //�H��(���m��)
	int getConfidence() const;
	void setMaxenergy(int);
	int getMaxenergy() const;

	//������I�]
	void Setbackpack_weight(int);   //�]�w�I�]���q
	void Setbackpack_weight_limit(int);  //���P���Ŧ��I�]���q����
	void Setbackpack_slot_limit(int);  //�H�έI�]�����~�ƶq����
	void Setbackpack_slot(int);
	int getbackpack_weight() const;
	int getbackpack_weight_limit() const;
	int getbackpack_slot_limit() const;
	int getbackpack_slot() const;

	
	bool equipWeapon(weaponItem*);  //�ݪ��a�O�_���t�a�Z��
	bool equipArmor(armorItem*);    //�ݪ��a�O�_���t�����m�˳�
	void useConsumable(int); //���ﶵ�ݬO�ϥ�food �٬O drink
	bool putItem(Item*);    //�N���~�h�i�I�]
	void takeItem(int);    //�����I�]���~
	void displaybackpack();  //�i�ܭI�]
	void removeItem(int);  //�����I�]���~

	weaponItem* getWeapon()const;   //���Ӥ�K���Z����
	armorItem* getArmor()const;
	Item* getBackpack(int)const;

	void setWeapon(weaponItem*);  //���Z���ɨϥ�
	void setArmor(armorItem*);
	void setBackpack(Item*);
	
	
	//���]
	void displaypocket();


	virtual void specialSkill();  //�S�����
	virtual string serialize();   //�s��



private:
	string name; // ���a�W��
	int energy; // �ثe��q
	int credits; // �Ǥ���
			
	int attack; // ���a�����O
	int confidence; // ���a���m�O
	int max_energy; // �̤j��q
	int money; // ��

	vector<Item*> backpack;  //�I�]
	weaponItem* weapon; // weapon item you use now
	armorItem* armor; // armor item you use now
	int backpack_weight; // current weight of player��s backpack
	int backpack_weight_limit; // limit on weight of backpack
	int backpack_slot_limit; // limit on number of backpack��s slots
	int backpack_slot;
};
#endif // ! OTAKU_H
