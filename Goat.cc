#include "Goat.h"

#include <iostream>

//class World;

using namespace std;

//Goat::Goat(int moved, World &that)
//	: Creature(0,moved), world(that)
Goat::Goat(World& that, int moved, int row, int column)
	:Creature(0,moved), world(that)
{
	food = 20;
	Row = row;
	Column = column;
}

Goat::~Goat(){
}

int Goat::getFood() const {
	return food;
}

/*void Goat::growOld(){
	Creature::growOld();	
}*/

void Goat::oneRound(){
	food--;
	growOld();
	if(getAge()>=70||food == 0){
		goatDie();
		return;
	}
	if(getAge()>=50&&getAge()<=55){
		bornAGoat();
	}
	else{
		goatMove();
	}
}

void Goat::print(){
	cout<<"X";
//	cout<<food;
//	cout<<"("<<Row<<","<<Column<<")";
//	world.test();
}

int Goat::judge(){
	return 1;
}

void Goat::goatDie(){
	delete world.creature[Row][Column];
	world.creature[Row][Column] = NULL;
}

void Goat::goatMove(){
	int dir = world.randomNum.getRandomNum(0,3);

	if(dir == 0){ //to East, column++
		if(Column+1<35){
			if(world.creature[Row][Column+1] == NULL){			
				world.creature[Row][Column+1] = world.creature[Row][Column];
				world.creature[Row][Column] = NULL;
				Column = Column+1 ;
			}
			else if(world.creature[Row][Column+1]->judge() == 0){
				delete world.creature[Row][Column+1];
				world.creature[Row][Column+1] = NULL;
				food+=5;

				world.creature[Row][Column+1] = world.creature[Row][Column];
				world.creature[Row][Column] = NULL;
				Column = Column+1 ;
			}
		}
	}	

	else if(dir == 1){ //to South, row++
		if(Row+1<20){
			if(world.creature[Row+1][Column] == NULL){
				world.creature[Row+1][Column] = world.creature[Row][Column];
				world.creature[Row][Column] = NULL;
				Row = Row+1 ;
			}
			else if(world.creature[Row+1][Column]->judge() == 0){
				delete world.creature[Row+1][Column];
				world.creature[Row+1][Column] = NULL;
				food+=5;

				world.creature[Row+1][Column] = world.creature[Row][Column];
				world.creature[Row][Column] = NULL;
				Row = Row+1 ;
			}
		}
	}

	else if(dir == 2){ //to West, column--
		if(Column-1>=0){
			if(world.creature[Row][Column-1] == NULL){
				world.creature[Row][Column-1] = world.creature[Row][Column];
				world.creature[Row][Column] = NULL;
				Column = Column-1 ;
			}
			else if(world.creature[Row][Column-1]->judge() == 0){
				delete world.creature[Row][Column-1];
				world.creature[Row][Column-1] = NULL;
				food+=5;

				world.creature[Row][Column-1] = world.creature[Row][Column];
				world.creature[Row][Column] = NULL;
				Column = Column-1 ;
			}
		}
	}

	else{ //to North, row--
		if(Row-1>=0){
			if(world.creature[Row-1][Column] == NULL){
				world.creature[Row-1][Column] = world.creature[Row][Column];
				world.creature[Row][Column] = NULL;
				Row = Row-1 ;
			}
			else if(world.creature[Row-1][Column]->judge() == 0){
				delete world.creature[Row-1][Column];
				world.creature[Row-1][Column] = NULL;
				food+=5;

				world.creature[Row-1][Column] = world.creature[Row][Column];
				world.creature[Row][Column] = NULL;
				Row = Row-1 ;
			}
		}
	}
	moved();
}

void Goat::bornAGoat(){
	int dir = world.randomNum.getRandomNum(0,3);

	if(dir == 0){ //to East, column++
		if(Column+1<35){
			if(world.creature[Row][Column+1] == NULL){			
				Goat *babyGoat;
				babyGoat = new Goat(world,1,Row,Column+1);
				world.creature[Row][Column+1] = babyGoat;
			}
			else if(world.creature[Row][Column+1]->judge() == 0){
				delete world.creature[Row][Column+1];
				world.creature[Row][Column+1] = NULL;
				food+=5;
				
				Goat *babyGoat;
				babyGoat = new Goat(world,1,Row,Column+1);
				world.creature[Row][Column+1] = babyGoat;
			}
		}
	}	

	else if(dir == 1){ //to South, row++
		if(Row+1<20){
			if(world.creature[Row+1][Column] == NULL){
				Goat *babyGoat;
				babyGoat = new Goat(world,1,Row+1,Column);
				world.creature[Row+1][Column] = babyGoat;
			}
			else if(world.creature[Row+1][Column]->judge() == 0){
				delete world.creature[Row+1][Column];
				world.creature[Row+1][Column] = NULL;
				food+=5;

				Goat *babyGoat;
				babyGoat = new Goat(world,1,Row+1,Column);
				world.creature[Row+1][Column] = babyGoat;
			}
		}
	}

	else if(dir == 2){ //to West, column--
		if(Column-1>=0){
			if(world.creature[Row][Column-1] == NULL){
				Goat *babyGoat;
				babyGoat = new Goat(world,1,Row,Column-1);
				world.creature[Row][Column-1] = babyGoat;
			}
			else if(world.creature[Row][Column-1]->judge() == 0){
				delete world.creature[Row][Column-1];
				world.creature[Row][Column-1] = NULL;
				food+=5;

				Goat *babyGoat;
				babyGoat = new Goat(world,1,Row,Column-1);
				world.creature[Row][Column-1] = babyGoat;
			}
		}
	}

	else{ //to North, row--
		if(Row-1>=0){
			if(world.creature[Row-1][Column] == NULL){
				Goat *babyGoat;
				babyGoat = new Goat(world,1,Row-1,Column);
				world.creature[Row-1][Column] = babyGoat;
			}
			else if(world.creature[Row-1][Column]->judge() == 0){
				delete world.creature[Row-1][Column];
				world.creature[Row-1][Column] = NULL;
				food+=5;

				Goat *babyGoat;
				babyGoat = new Goat(world,1,Row-1,Column);
				world.creature[Row-1][Column] = babyGoat;
			}
		}
	}
	moved();
}
