#include <iostream>

#include "TV_Controller.h"

int main()
{
	RemoteController* c_tv1 = new TV_Controller();

	c_tv1->powerOn();

	c_tv1->menu();
	c_tv1->exitMenu();

	c_tv1->volumeUp();
	c_tv1->volumeDown();
	c_tv1->mute();

	c_tv1->channelNext();
	c_tv1->channelPrev();

	c_tv1->powerOff();

	delete c_tv1;
	return 0;
}