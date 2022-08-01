#include "mayne_computer.h"
#include <iostream>

extern int how_many_mayne_computer;

mayne_computer::mayne_computer() : mayne()
{
	how_many_mayne_computer += 1;
}

mayne_computer::~mayne_computer()
{
	how_many_mayne_computer -= 1;
}

void mayne_computer::remove()
{
	delete this;
}
