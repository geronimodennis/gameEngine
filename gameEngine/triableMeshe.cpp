#include <glad/glad.h>

class triableMeshe
{
public:
	unsigned int tri_vbo_id;
	float tri_verties[9] = {
	0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f,
	};

	void draw();
	triableMeshe();
	~triableMeshe();
};



void triableMeshe::draw()
{
	glBindBuffer(GL_ARRAY_BUFFER, tri_vbo_id);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 3);
}

triableMeshe::triableMeshe()
{
	glGenBuffers(1, &tri_vbo_id);
	glBindBuffer(GL_ARRAY_BUFFER, tri_vbo_id);
	glBufferData(GL_ARRAY_BUFFER, sizeof(tri_verties), tri_verties, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(tri_verties), tri_verties);
}


triableMeshe::~triableMeshe()
{
	glDeleteBuffers(1, &tri_vbo_id);
}
