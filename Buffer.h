#ifndef BUFFER_ARRAY_H
#define BUFFER_ARRAY_H

#include <glad/glad.h>

class Buffer
{
public:

	unsigned int ID;

	Buffer(float* vertices, GLsizeiptr size)
	{
		glGenBuffers(1, &ID);
		glBindBuffer(GL_ARRAY_BUFFER, ID);
		glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
	}

	// Binds the VBO
	void Bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, ID);
	}

	// Unbinds the VBO
	void Unbind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	// Deletes the VBO
	void Delete()
	{
		glDeleteBuffers(1, &ID);
	}
};
#endif // !BUFFER_ARRAY_H
