#ifndef _GOAT_H_
#define _GOAT_H_

#include "Creature.h"
#include "World.h"
class World;

class Goat : public Creature{
	
	public:
		// Constructor
		Goat(World&, int moved = 0, int row = 0, int column = 0);

		//Destructure
		 ~Goat();

		// accessors
		int getFood() const;
//		void growOld();
		virtual void oneRound();
		virtual void print();
		virtual int judge();
		void goatDie();
		void goatMove();
		void bornAGoat();

	private:
		int food;
		int Row, Column;
		World &world;
};

#endif // _GOAT_H_
