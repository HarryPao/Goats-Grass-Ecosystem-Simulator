#ifndef _WORLD_H_
#define _WORLD_H_

//#include "Creature.h"
#include "RandomNum.h"
#include "Goat.h"
#include "Grass.h"

class World {
	
	public:
		// Constructor
		World(int numPasses = 0,int seed = 0);

		// accessors
		void mainLoop(int displayInterval);
		void print()const;
		void test()const;
		//void creatureDie(int,int);

		Creature *creature[20][35];
		RandomNum randomNum;

	private:
		int NumPasses;
		//int Seed;
		//Creature *creature[20][35];
		//RandomNum randomNum;
};

#endif // _WORLD_H_
