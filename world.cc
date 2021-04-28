#include <iostream>

#include "World.h"

using namespace std;

World::World(int numPasses,int seed) 
	: NumPasses(numPasses), randomNum(seed)
{
	for(int x=0;x<20;x++){
		for(int y=0;y<35;y++){
			creature[x][y] = NULL;
		}
	}
	
	int i = 0, j = 0;
	
	while(i < 5){
		
		int column = 0, row = 0;
		column = randomNum.getRandomNum(0,34);
		row = randomNum.getRandomNum(0,19);
		
		if(creature[row][column] == NULL){
			Goat *goat;
			goat = new Goat(*this,0,row,column);
			creature[row][column] = goat;
			i++;
		}
	}
	//cout<<i<<endl;

	while(j < 10){
	
		int column = 0, row = 0;
		column = randomNum.getRandomNum(0,34);
		row = randomNum.getRandomNum(0,19);

		if(creature[row][column] == NULL){
			Grass *grass;
			grass = new Grass(*this,0,row,column);
			creature[row][column] = grass;
			j++;
		}
	}
	//cout<<j<<endl;
}

void World::mainLoop(int displayInterval){
	
	//print();	//Round 0;
	for(int x=0;x<NumPasses;){
		
		for(int i=0;i<20;i++){
			for(int j=0;j<35;j++){
				if(creature[i][j]!=NULL){
					if(creature[i][j]->whetherMoved() == 0){ //to see if the creature has moved
							creature[i][j]->oneRound(); 
					}
				}
			}
		}
		x++;

		for(int i=0;i<20;i++){
			for(int j=0;j<35;j++){
				if(creature[i][j]!=NULL){
					creature[i][j]->resetMoved();
				}
			}
		}

		if( x % displayInterval == 0)
			print();
	}

}

void World::print() const{
	
	cout<<" ";
	for(int i=0;i<35;i++){
		cout<<" "<<i%10;
	}
	cout<<endl;

	for(int j=0;j<20;j++){
		cout<<j%10;
		for(int k=0;k<35;k++){
			cout<<" ";
			if(creature[j][k] == NULL)
				cout<<" ";
			else
				creature[j][k]->print();
		}
		cout<<endl;
	}
	cout<<"-------------------------------------------------------------------------"<<endl;
}

void World::test() const{
	cout<<"Test Successes!"<<endl;
}

/*void World::creatureDie(int r,int c){
	delete creature[r][c];
}*/
