#include <glad/glad.h>


class TriangleMesh
{
public:
	const char* vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}\0";
	const char* fragmentShaderSource = "#version 330 core\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
		"}\n\0";
	int fragmentShader, shaderProgram;

	unsigned int tri_vbo_id, tri_vao_id, tri_ebo_id;
	float tri_verties[12] = {
		 0.5f,  0.5f, 0.0f,  // top right
		 0.5f, -0.5f, 0.0f,  // bottom right
		-0.5f, -0.5f, 0.0f,  // bottom left
		-0.5f,  0.5f, 0.0f   // top left 
	};

	float tri_indices[6] = {
		0, 1, 3,  // first Triangle
		1, 2, 3   // second Triangle
	};

	void draw();
	int buildShader();
	TriangleMesh();
	~TriangleMesh();
};

int TriangleMesh::buildShader() {
	// build and compile our shader program
// ------------------------------------
// vertex shader
	int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);
	// check for shader compile errors
	int success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	// fragment shader
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	// check for shader compile errors
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	// link shaders
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	// check for linking errors
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	return 0;
}

void TriangleMesh::draw()
{
	glUseProgram(shaderProgram);
	glBindVertexArray(tri_vao_id); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
	 //glDrawArrays(GL_TRIANGLES, 0, 6);
	//glDrawArrays(GL_TRIANGLES, 0, 3);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
}

TriangleMesh::TriangleMesh()
{
	/*glGenBuffers(1, &tri_vbo_id);
	glBindBuffer(GL_ARRAY_BUFFER, tri_vbo_id);
	glBufferData(GL_ARRAY_BUFFER, sizeof(tri_verties), tri_verties, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(tri_verties), tri_verties);*/
	glGenVertexArrays(1, &tri_vao_id);
	glGenBuffers(1, &tri_vbo_id);
	glGenBuffers(1, &tri_ebo_id);

	glBindVertexArray(tri_vao_id);

	glBindBuffer(GL_ARRAY_BUFFER, tri_vbo_id);
	glBufferData(GL_ARRAY_BUFFER, sizeof(tri_verties), tri_verties, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, tri_ebo_id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(tri_indices), tri_indices, GL_STATIC_DRAW);


	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	buildShader();

}


TriangleMesh::~TriangleMesh()
{
	glDeleteBuffers(1, &tri_vbo_id);
}
