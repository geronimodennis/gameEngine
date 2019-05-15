#include "EGanesis.h"


EGanesis::EGanesis()
{
	isRunning = true;
}

void EGanesis::gameLoop()
{

	glfwInit();

	GLFWwindow* window = glfwCreateWindow(1000, 1000, "gameEngine", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
	}
	glfwMakeContextCurrent(window);

	while (!(isRunning = glfwWindowShouldClose(window)))
	{
		
		std::cout << "Running\n";
		glfwSwapBuffers(window);

		glfwPollEvents();

	}
}




EGanesis::~EGanesis()
{
}
