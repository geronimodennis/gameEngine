

#ifndef iostream
#include <iostream>
#endif

#include <glad/glad.h>
#include <GLFW/glfw3.h>


class EGanesis
{
private: 
	bool isRunning;
	GLFWwindow* setupWindow();
public:
	float  ENGINE_CLEAR_COLOR[3] = { 30.0f / 255.0f, 144.0f / 255.0f, 255.0f / 255.0f }; //{ 30f / 255f, 144f / 255f, 255f / 255f };
	EGanesis();

	void gameLoop();
	~EGanesis();
};

