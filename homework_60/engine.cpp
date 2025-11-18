#include <iostream>

#include "Engine.h"

Engine::Engine() : m_status(false) {}

void Engine::start()
{
	m_status = true;
	std::cout << "Engine started." << std::endl;
}

void Engine::stop()
{
	m_status = false;
	std::cout << "Engine stopped." << std::endl;
}

bool Engine::engineStatus() const
{
	return m_status;
}