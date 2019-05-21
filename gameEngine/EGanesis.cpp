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

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}

void initGlad() {
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress));
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
	}
}

GLFWwindow* EGanesis::setupWindow()
{

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(1000, 1000, "gameEngine", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
	}

	glfwMakeContextCurrent(window);
	//glfwGetFramebufferSize(window, &width, &height);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	return window;
}


EGanesis::EGanesis()
{
	isRunning = true;
}




void EGanesis::gameLoop()
{
	glfwInit();
	GLFWwindow* window = setupWindow();
	initGlad();
	TriangleMesh* tri = new TriangleMesh();

	while (!(isRunning = glfwWindowShouldClose(window)))
	{

		//glViewport(0, 0, width, height);
		glClearColor(ENGINE_CLEAR_COLOR[0], ENGINE_CLEAR_COLOR[1], ENGINE_CLEAR_COLOR[2],1.0f);
		//glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
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

