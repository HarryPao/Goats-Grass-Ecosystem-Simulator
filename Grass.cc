#include "Grass.h"
//#include "RandomNum.h"

#include <iostream>

using namespace std;

Grass::Grass(World& that, int moved, int row, int column)
	: Creature(0,moved), world(that)
{
	Row = row;
	Column = column;
}

Grass::~Grass(){
//	cout<<"gd";
}

/*void Grass::growOld(){
	Creature::growOld();
}*/

void Grass::oneRound(){
	growOld();
	if(getAge()>=6){
//		cout<<"("<<Row<<","<<Column<<")"<<getAge()<<" ";
		grassDie();
		return;
	}
	
	if(getAge()>=3&&getAge()<=5){
		bornAGrass();				
	}
}

void Grass::print(){
	cout<<"I";
//	cout<<getAge();
//	cout<<"("<<Row<<","<<Column<<")";
}

int Grass::judge(){
	return 0;
}

void Grass::grassDie(){
	delete world.creature[Row][Column];
	world.creature[Row][Column] = NULL;
}

void Grass::bornAGrass(){
	int dir = world.randomNum.getRandomNum(0,3);

	if(dir == 0){  //to East, column++
		
		if(Column+1<35){
			if(world.creature[Row][Column+1] == NULL){
				Grass *grass;
				grass = new Grass(world,1,Row,Column+1);
				world.creature[Row][Column+1] = grass;
			}			
		}
	}

	else if(dir == 1){ //to South, row++
		
		if(Row+1<20){
			if(world.creature[Row+1][Column] == NULL){
				Grass *grass;
				grass = new Grass(world,1,Row+1,Column);
				world.creature[Row+1][Column] = grass;
			}				
		}
	}

	else if(dir == 2){ //to West, column--

		if(Column-1>=0){
			if(world.creature[Row][Column-1] == NULL){
				Grass *grass;
				grass = new Grass(world,1,Row,Column-1);
				world.creature[Row][Column-1] = grass;
			}				
		}
	}

	else{ //to North, row--
	
		if(Row-1>=0){
			if(world.creature[Row-1][Column] == NULL){
				Grass *grass;
				grass = new Grass(world,1,Row-1,Column);
				world.creature[Row-1][Column] = grass;
			}				
		}
	}
}
