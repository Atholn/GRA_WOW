#include "Random.h"
#include<iostream>
#include<ctime>
#include<cstdlib>

int generateRandom(int max)
{
	int randomNumber = rand();
	float random = (randomNumber % max) + 1;
	int myRandom = random;
	return myRandom;
}