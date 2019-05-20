#include "EGanesis.h"
#include "triableMeshe.cpp"


int width, height;


void _check_gl_error(const char* file, int line) {
	GLenum err(glGetError());

	while (err != GL_NO_ERROR) {
		std::string error;

		switch (err) {
		case GL_INVALID_OPERATION:      error = "INVALID_OPERATION";      break;
		case GL_INVALID_ENUM:           error = "INVALID_ENUM";           break;
		case GL_INVALID_VALUE:          error = "INVALID_VALUE";          break;
		case GL_OUT_OF_MEMORY:          error = "OUT_OF_MEMORY";          break;
		case GL_INVALID_FRAMEBUFFER_OPERATION:  error = "INVALID_FRAMEBUFFER_OPERATION";  break;
		}

		std::cerr << "GL_" << error.c_str() << " - " << file << ":" << line << std::endl;
		err = glGetError();
	}
}

GLFWwindow* EGanesis::setupWindow()
{
	GLFWwindow* window = glfwCreateWindow(1000, 1000, "gameEngine", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
	}
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);


	glfwMakeContextCurrent(window);
	glfwGetFramebufferSize(window, &width, &height);
	return window;
}


EGanesis::EGanesis()
{
	isRunning = true;
}






void EGanesis::gameLoop()
{
	glfwInit();
	triableMeshe* tri = new triableMeshe();

	GLFWwindow* window = setupWindow();
	gladLoadGL();
	while (!(isRunning = glfwWindowShouldClose(window)))
	{



		glViewport(0, 0, width, height);
		glClearColor(ENGINE_CLEAR_COLOR[0], ENGINE_CLEAR_COLOR[1], ENGINE_CLEAR_COLOR[2],1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		

		tri->draw();

		glfwSwapBuffers(window);
		glfwPollEvents();

		_check_gl_error(__FILE__, __LINE__);

	}
}




EGanesis::~EGanesis()
{
}

