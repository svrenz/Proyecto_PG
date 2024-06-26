#ifndef METODOS_H
#define	METODOS_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <sstream>

#include "shaderClass.h"
#include "Textura.h"
#include "Camera.h"
#include "Array.h"
#include "Buffer.h"


//settings
static const unsigned int SCR_WIDTH = 800;
static const unsigned int SCR_HEIGHT = 600;

// timing
static float deltaTime = 0.0f;	// time between current frame and last frame
static float lastFrame = 0.0f;

// camera
Camera camera(glm::vec3(5.0f, 1.0f, 3.0f));
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;

float vertices[] = {
-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
};


class Metodos
{

public:

    static void Make_Floor(Array vao)
    {
        vao.Bind();
        Buffer vbo(vertices, sizeof(vertices));
        vao.linkVBO(vbo, 0, 3, GL_FLOAT, 5 * sizeof(float), (void*)0);
        vao.linkVBO(vbo, 1, 2, GL_FLOAT, 5 * sizeof(float), (void*)(3 * sizeof(float)));
        vao.Unbind();
        vbo.Unbind();
    }

	static void Draw_Floor(Shader ourShader)
	{
        for (float i = 0; i < 16; i++)
        {
            for (float j = 0; j < 16; j++)
            {
                glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
                model = glm::translate(model, glm::vec3(i, 0.0f, j));
                ourShader.setMat4("model", model);
                glDrawArrays(GL_TRIANGLES, 0, 36);
            }
        }
	}

    static void Make_Wall(Array vao)
    {
        vao.Bind();
        Buffer vbo(vertices, sizeof(vertices));
        vao.linkVBO(vbo, 0, 3, GL_FLOAT, 5 * sizeof(float), (void*)0);
        vao.linkVBO(vbo, 1, 2, GL_FLOAT, 5 * sizeof(float), (void*)(3 * sizeof(float)));
        vao.Unbind();
        vbo.Unbind();
    }

    static void Draw_Wall(Shader ourShader)
    {
        for (float i = 0; i < 4; i++)
        {
            //wall one
            for (float j = 0; j < 16; j++)
            {
                glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
                model = glm::translate(model, glm::vec3(0.0f, i, j));
                ourShader.setMat4("model", model);
                glDrawArrays(GL_TRIANGLES, 0, 36);
            }
            //wall two
            for (float j = 0; j < 16; j++)
            {
                glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
                model = glm::translate(model, glm::vec3(j, i, 0.0f));
                ourShader.setMat4("model", model);
                glDrawArrays(GL_TRIANGLES, 0, 36);
            }
            //wall three
            for (float j = 0; j < 16; j++)
            {
                glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
                model = glm::translate(model, glm::vec3(15.0f, i, j));
                ourShader.setMat4("model", model);
                glDrawArrays(GL_TRIANGLES, 0, 36);
            }
            //wall four
            for (float j = 0; j < 7; j++)
            {
                glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
                model = glm::translate(model, glm::vec3(j, i, 15.0f));
                ourShader.setMat4("model", model);
                glDrawArrays(GL_TRIANGLES, 0, 36);
            }
            for (float j = 9; j < 16; j++)
            {
                glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
                model = glm::translate(model, glm::vec3(j, i, 15.0f));
                ourShader.setMat4("model", model);
                glDrawArrays(GL_TRIANGLES, 0, 36);
            }
        }
    }

    static void framebuffer_size_callback(GLFWwindow* window, int width, int height)
    {
        glViewport(0, 0, width, height);
    }

    static void processInput(GLFWwindow* window)
    {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);

        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
            camera.ProcessKeyboard(FORWARD, deltaTime);
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
            camera.ProcessKeyboard(BACKWARD, deltaTime);
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
            camera.ProcessKeyboard(LEFT, deltaTime);
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
            camera.ProcessKeyboard(RIGHT, deltaTime);
    }

    static void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
    {
        float xpos = static_cast<float>(xposIn);
        float ypos = static_cast<float>(yposIn);

        if (firstMouse)
        {
            lastX = xpos;
            lastY = ypos;
            firstMouse = false;
        }

        float xoffset = xpos - lastX;
        float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

        lastX = xpos;
        lastY = ypos;

        camera.ProcessMouseMovement(xoffset, yoffset);
    }

    static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
    {
        camera.ProcessMouseScroll(static_cast<float>(yoffset));
    }

};

#endif // !METODOS_H
