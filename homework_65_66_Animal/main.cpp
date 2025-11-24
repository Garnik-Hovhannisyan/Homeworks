#include <iostream>

#include "Derived.h"
#include "Zoo.h"

int main()
{
	Zoo zoo(7);

	Dog* dog1 = new Dog("Shun", "White", 2, 5.6, "Shih Tzu", true, true);
	Cat* cat1 = new Cat("Katu", "Black", 5, 1.5, "White", false, true);
	Horse* horse1 = new Horse("Dzi", "Brown", 9, 40.0, true, 100);
	Bird* bird1 = new Bird("Trchun", "White", 2, 0.5, "White", true);
	Bear* bear1 = new Bear("Arj", "Yellow", 8, 25.0, "Teddy", "Golden");
	Lion* lion1 = new Lion("Aryuts", "Brown", 15, 80.0, true, false);
	Frog* frog1 = new Frog("Gort", "Green", 1, 0.5, false);

	zoo.arr[0] = dog1;
	zoo.arr[1] = cat1;
	zoo.arr[2] = horse1;
	zoo.arr[3] = bird1;
	zoo.arr[4] = bear1;
	zoo.arr[5] = lion1;
	zoo.arr[6] = frog1;

	zoo.showInfo();
	zoo.showVoice();

	return 0;
}