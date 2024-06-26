#ifndef ARRAY_H
#define ARRAY_H

#include <glad/glad.h>
#include "Buffer.h"

class Array
{
	unsigned int ID;

	public:
		Array()
		{
			glGenVertexArrays(1, &ID);
		}

		void linkVBO(Buffer& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset)
		{
			VBO.Bind();
			glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
			glEnableVertexAttribArray(layout);
			VBO.Unbind();
		}

		void Bind()
		{
			glBindVertexArray(ID);
		}

		// Unbinds the VAO
		void Unbind()
		{
			glBindVertexArray(0);
		}

		// Deletes the VAO
		void Delete()
		{
			glDeleteVertexArrays(1, &ID);
		}
};

#endif // !ARRAY_H
