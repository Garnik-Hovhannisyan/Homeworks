#include <iostream>

#include "TV_Controller.h"

TV_Controller::TV_Controller() : m_volume(5), m_channel(1), m_isOn(false), m_isMenuON(false) {}

void TV_Controller::powerOn()
{
	if (!m_isOn)
	{
		m_isOn = true;
		std::cout << "TV is ON" << std::endl;
	}
}

void TV_Controller::powerOff()
{
	if (m_isOn)
	{
		std::cout << "TV is OFF" << std::endl;
		m_isOn = false;
	}
}

void TV_Controller::menu()
{
	if (m_isOn && !m_isMenuON)
	{
		m_isMenuON = true;
		std::cout << "Menu opened" << std::endl;
	}
}

void TV_Controller::exitMenu()
{
	if (m_isOn && m_isMenuON)
	{
		std::cout << "Menu closed" << std::endl;
		m_isMenuON = false;
	}
}

void TV_Controller::volumeUp()
{
	if (m_isOn && m_volume < m_MAXVOLUME)
	{
		std::cout << "Volume - " << ++m_volume << std::endl;
	}
}

void TV_Controller::volumeDown()
{
	if (m_isOn && m_volume > m_MINVOLUME)
	{
		std::cout << "Volume - " << --m_volume << std::endl;
	}
}

void TV_Controller::mute()
{
	if (m_isOn)
	{
		m_volume = 0;
		std::cout << "Volume - " << m_volume << std::endl;
	}
}

void TV_Controller::channelNext()
{
	if (m_isOn && m_channel < m_MAXCHANNEL)
	{
		std::cout << "Channel - " << ++m_channel << std::endl;
	}
}

void TV_Controller::channelPrev()
{
	if (m_isOn && m_channel > m_MINCHANNEL)
	{
		std::cout << "Channel - " << --m_channel << std::endl;
	}
}