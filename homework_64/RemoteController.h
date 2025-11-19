#ifndef REMOTECONTROLLER_H
#define REMOTECONTROLLER_H

class RemoteController
{
public:
	virtual ~RemoteController() = 0;

	virtual void powerOn() = 0;
	virtual void powerOff() = 0;

	virtual void menu() = 0;
	virtual void exitMenu() = 0;

	virtual void volumeUp() = 0;
	virtual void volumeDown() = 0;
	virtual void mute() = 0;

	virtual void channelNext() = 0;
	virtual void channelPrev() = 0;
};

#endif // REMOTECONTROLLER