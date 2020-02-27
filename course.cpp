#include "course.h"
int course::count = 0;

course::course()
	:name(""),attack(0),defense(0),credits(0),money(0),max_Time(0)
{
	setTime(max_Time);
	count++;
}

course::course(string a, int b, int c, int d, int e, int f)
	: name(a), attack(b), defense(c), credits(d), money(e), max_Time(f)
{
	setTime(max_Time);
	count++;
}


void course::setTime(int a)
{
	if (a <= max_Time)
		Time = a;
	else
		Time = max_Time;
}

int course::getTime() const
{
	return Time;
}


int course::getInstanceCount(void)
{
	return count;
}