#include "Creature.h"

#include <iostream>

using namespace std;

Creature::Creature(int age, int moved)
	:Age(age), Moved(moved)
{
}

Creature::~Creature(){
//	cout<<"CD";
}

int Creature::getAge() const{
	return Age;
}

void Creature::growOld(){
	Age++;
}

void Creature::oneRound(){
}

void Creature::print(){
	cout<<" ";
}

int Creature::judge(){
	return -1;
}

void Creature::moved(){
	Moved = 1;
}

void Creature::resetMoved(){
	Moved = 0;
}

int Creature::whetherMoved(){
	return Moved;
}
