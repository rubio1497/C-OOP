#pragma once
#ifndef COURSE_H
#define COURSE_H
#include <string>
using namespace std;
class course
{
public:
	course();
	course(string, int, int, int, int, int);
	const string name; // Name of the monster
	const int attack; // Attack of the monster
	const int defense; // Defense of the monster 
	const int credits; // Experience earned by players after beating this monster
	const int money; // Amount of money dropped after beating this monster
	const int max_Time; // The monster¡¦s maximum HP
	void setTime(int);
	int getTime() const;
	static int getInstanceCount(void);
//	virtual string serialize();
private:
	int Time;
	static int count;
};
#endif // !COURSE_H
