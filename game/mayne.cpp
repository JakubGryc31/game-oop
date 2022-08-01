#include "mayne.h"
#include <iostream>


extern int how_many_mayne;

//constructor-definition
mayne::mayne()
{
	how_many_mayne += 1;

}

//destructor-definition
mayne::~mayne()
{
	how_many_mayne -= 1;
}

//virtual method-definition
void mayne::remove()
{

}

//rest methods-definition
float mayne::gethp()
{
	return life;
}

void mayne::sethp(float h)
{
	life = h;
}

int mayne::getshield()
{
	return shield;
}

void mayne::setexperience(int d)
{
	experience=d;
}

int mayne::getexperience()
{
	return experience;
}

int mayne::fire()
{
	return fire_power;
}

