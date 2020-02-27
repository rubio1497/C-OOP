#pragma once
#ifndef WHOLEPACK_H
#define WHOLEPACK_H
#include "normalguy.h"
class wholepack:public normalguy
{
public:
	wholepack();
	wholepack(const wholepack&);
	void setAffection(bool);
	bool getAffection()const;
	virtual void specialSkill();
	virtual string serialize();
private:
	bool girlfriend;
};
#endif // !WHOLEPACK_H
