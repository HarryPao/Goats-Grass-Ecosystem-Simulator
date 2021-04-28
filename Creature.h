#ifndef _CREATURE_H
#define _CREATURE_H_

class Creature {
	
	public:
		// Constructor
		Creature(int age = 0, int moved = 0);
		
		//Destructor
		virtual ~Creature();

		// accessors
		int getAge() const;
		void growOld();
		virtual void oneRound();
		virtual void print();
		virtual int judge();
		void moved();
		void resetMoved();
		int whetherMoved();

	private:
		int Age;
		int Moved;
};

#endif // _CREATURE_H_
