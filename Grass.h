#ifndef _GRASS_H_
#define _GRASS_H_

//#include "Creature.h"
#include "World.h"

class World; //forward declaration

class Grass : public Creature {
	
	public:
		// Constructor
		Grass(World&, int moved, int row, int column);

		//Destructure
		~Grass();

		//accessors
//		void growOld();
		virtual void oneRound();		
		virtual void print();
		virtual int judge();
		void grassDie();
		void bornAGrass();		

	private:
		int Row, Column;
		World &world;
};

#endif // _GRASS_H_
