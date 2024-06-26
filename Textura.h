#ifndef TEXTURA_H
#define TEXTURA_H

#define VARIABLE_NAME_TO_STRING(x) #x
#include <stb/stb_image.h>
#include<glad/glad.h>
#include<iostream>
#include "shaderClass.h"

class Textura
{
public:
    unsigned int ID;
	int width;
	int height;
	int nrChannels;

	Textura(const char* rutaTextura, Shader shader)
	{
        glGenTextures(1, &ID);
        glBindTexture(GL_TEXTURE_2D, ID);
        // set the texture wrapping parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        // set texture filtering parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        // load image, create texture and generate mipmaps
        stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
        unsigned char* data = stbi_load(rutaTextura, &width, &height, &nrChannels, 0);
        if (data)
        {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
        }
        else
        {
            std::cout << "Failed to load texture" << std::endl;
        }
        stbi_image_free(data);
	}

    void getLocation(Shader shader, int order)
    {
        shader.setInt(VARIABLE_NAME_TO_STRING(ID), order);
    }

    void BindText(GLenum position)
    {
        glActiveTexture(position);
        glBindTexture(GL_TEXTURE_2D, ID);
    }

};
#endif // !TEXTURA_H