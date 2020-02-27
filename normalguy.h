#pragma once
#ifndef NORMALGUY_H
#define NORMALGUY_H
#include "Otaku.h"

class normalguy:public Otaku
{
public:
	normalguy();
	normalguy(const normalguy&);
	void setFriends(int);
	int getFriends()const;
	virtual void specialSkill();
	virtual string serialize();
private:
	int friends;
};
#endif // !NORMALGUY_H
