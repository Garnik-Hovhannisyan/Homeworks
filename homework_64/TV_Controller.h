#ifndef TV_CONTROLLER_H
#define TV_CONTROLLER_H

#include "RemoteController.h"

class TV_Controller : public RemoteController
{
private:
    int m_volume;
	const int m_MINVOLUME = 0;
    const int m_MAXVOLUME = 50;

	int m_channel = 1;
    const int m_MINCHANNEL = 1;
    const int m_MAXCHANNEL = 20;

    bool m_isOn = false;
    bool m_isMenuON = false;

public:
	TV_Controller();
    TV_Controller(const TV_Controller&) = default;
    TV_Controller& operator=(const TV_Controller&) = default;
    ~TV_Controller() override = default;

public:
    void powerOn() override;
    void powerOff() override;

    void menu() override;
    void exitMenu() override;

    void volumeUp() override;
    void volumeDown() override;
    void mute() override;

    void channelNext() override;
    void channelPrev() override;
};

#endif // TV_CONTROLLER