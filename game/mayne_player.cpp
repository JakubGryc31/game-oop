#include "mayne_player.h"
#include <iostream>

extern int how_many_mayne_player;
	
	//constructor
	mayne_player::mayne_player() : mayne()
{
	how_many_mayne_player += 1;
}

	//destructor
	mayne_player::~mayne_player()
	{
		how_many_mayne_player -= 1;
	}

	void mayne_player::remove()
	{
		delete this;
	}