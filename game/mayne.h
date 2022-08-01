#pragma once
#include<iostream>
class mayne
{
	float life = 100;
	int fire_power = 20;
	int shield = 10;
	int experience = 0;

public:

	mayne();

	~mayne();

	virtual void remove();

	//get and set hp
	float gethp();
	void sethp(float h);

	//get shield
	int getshield();

	//get and set experience
	int getexperience();
	void setexperience(int d);

	//get fire power
	int fire();
};
