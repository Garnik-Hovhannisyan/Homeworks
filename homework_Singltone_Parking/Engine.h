#ifndef ENGINE_H
#define ENGINE_H

class Engine
{
private:
	bool m_status;

public:
	Engine();
	Engine(const Engine& other) = delete;
	Engine& operator=(const Engine& other) = delete;
	~Engine() = default;

public:
	void start();
	void stop();
	bool engineStatus() const;
};

#endif // ENGINE