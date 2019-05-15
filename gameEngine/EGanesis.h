

#ifndef iostream
#include <iostream>
#endif

#include <glad/glad.h>
#include <GLFW/glfw3.h>


class EGanesis
{
private: 
	bool isRunning;
public:
	EGanesis();
	void gameLoop();
	~EGanesis();
};

