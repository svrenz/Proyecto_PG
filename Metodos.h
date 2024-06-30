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
#include "Textura_J.h"
#include "Textura_P.h"
#include "Camera.h"
#include "Array.h"
#include "Buffer.h"

using namespace std;

//settings
static const unsigned int SCR_WIDTH = 800;
static const unsigned int SCR_HEIGHT = 600;

// timing
static float deltaTime = 0.0f;	// time between current frame and last frame
static float lastFrame = 0.0f;

// camera
Camera camera(glm::vec3(10.0f, 1.5f, 25.0f));
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

float skyboxVertices[] = {
     // positions          
     -1.0f,  1.0f, -1.0f,
     -1.0f, -1.0f, -1.0f,
      1.0f, -1.0f, -1.0f,
      1.0f, -1.0f, -1.0f,
      1.0f,  1.0f, -1.0f,
     -1.0f,  1.0f, -1.0f,
 
     -1.0f, -1.0f,  1.0f,
     -1.0f, -1.0f, -1.0f,
     -1.0f,  1.0f, -1.0f,
     -1.0f,  1.0f, -1.0f,
     -1.0f,  1.0f,  1.0f,
     -1.0f, -1.0f,  1.0f,
 
      1.0f, -1.0f, -1.0f,
      1.0f, -1.0f,  1.0f,
      1.0f,  1.0f,  1.0f,
      1.0f,  1.0f,  1.0f,
      1.0f,  1.0f, -1.0f,
      1.0f, -1.0f, -1.0f,
 
     -1.0f, -1.0f,  1.0f,
     -1.0f,  1.0f,  1.0f,
      1.0f,  1.0f,  1.0f,
      1.0f,  1.0f,  1.0f,
      1.0f, -1.0f,  1.0f,
     -1.0f, -1.0f,  1.0f,
 
     -1.0f,  1.0f, -1.0f,
      1.0f,  1.0f, -1.0f,
      1.0f,  1.0f,  1.0f,
      1.0f,  1.0f,  1.0f,
     -1.0f,  1.0f,  1.0f,
     -1.0f,  1.0f, -1.0f,
 
     -1.0f, -1.0f, -1.0f,
     -1.0f, -1.0f,  1.0f,
      1.0f, -1.0f, -1.0f,
      1.0f, -1.0f, -1.0f,
     -1.0f, -1.0f,  1.0f,
      1.0f, -1.0f,  1.0f
 };


float LogoVertices[] =
{ 
    // positions           / texture coords
        2.6f,  1.8f, 0.1f,   1.0f, 1.0f, // top right
        2.6f, -1.8f, 0.1f,   1.0f, 0.0f, // bottom right
       -2.6f, -1.8f, 0.1f,   0.0f, 0.0f, // bottom left
       -2.6f,  1.8f, 0.1f,   0.0f, 1.0f  // top left 
};

float CieloRazoVertices[] =
{
    -9.4f, 0.0f,  9.0f,		0.0f, 0.0f,
    -9.4f, 0.0f, -9.0f,		0.0f, 1.0f,
     9.4f, 0.0f, -9.0f,		1.0f, 1.0f,
     9.4f, 0.0f,  9.0f,		1.0f, 0.0f
};

unsigned int LogoIndices[] =
{
      0, 1, 3,
      1, 2, 3
};

unsigned int CieloIndices[] =
{
    0, 1, 2,
    0, 2, 3
};

float ContVertices[] = {
-0.5f, -0.5f, -1.0f,  0.0f, 0.0f,
 0.5f, -0.5f, -1.0f,  1.0f, 0.0f,
 0.5f,  0.5f, -1.0f,  1.0f, 1.0f,
 0.5f,  0.5f, -1.0f,  1.0f, 1.0f,
-0.5f,  0.5f, -1.0f,  0.0f, 1.0f,
-0.5f, -0.5f, -1.0f,  0.0f, 0.0f,
             
-0.5f, -0.5f,  1.0f,  0.0f, 0.0f,
 0.5f, -0.5f,  1.0f,  1.0f, 0.0f,
 0.5f,  0.5f,  1.0f,  1.0f, 1.0f,
 0.5f,  0.5f,  1.0f,  1.0f, 1.0f,
-0.5f,  0.5f,  1.0f,  0.0f, 1.0f,
-0.5f, -0.5f,  1.0f,  0.0f, 0.0f,
            
-0.5f,  0.5f,  1.0f,  1.0f, 0.0f,
-0.5f,  0.5f, -1.0f,  1.0f, 1.0f,
-0.5f, -0.5f, -1.0f,  0.0f, 1.0f,
-0.5f, -0.5f, -1.0f,  0.0f, 1.0f,
-0.5f, -0.5f,  1.0f,  0.0f, 0.0f,
-0.5f,  0.5f,  1.0f,  1.0f, 0.0f,
              
 0.5f,  0.5f,  1.0f,  1.0f, 0.0f,
 0.5f,  0.5f, -1.0f,  1.0f, 1.0f,
 0.5f, -0.5f, -1.0f,  0.0f, 1.0f,
 0.5f, -0.5f, -1.0f,  0.0f, 1.0f,
 0.5f, -0.5f,  1.0f,  0.0f, 0.0f,
 0.5f,  0.5f,  1.0f,  1.0f, 0.0f,
           
-0.5f, -0.5f, -1.0f,  0.0f, 1.0f,
 0.5f, -0.5f, -1.0f,  1.0f, 1.0f,
 0.5f, -0.5f,  1.0f,  1.0f, 0.0f,
 0.5f, -0.5f,  1.0f,  1.0f, 0.0f,
-0.5f, -0.5f,  1.0f,  0.0f, 0.0f,
-0.5f, -0.5f, -1.0f,  0.0f, 1.0f,
             
-0.5f,  0.5f, -1.0f,  0.0f, 1.0f,
 0.5f,  0.5f, -1.0f,  1.0f, 1.0f,
 0.5f,  0.5f,  1.0f,  1.0f, 0.0f,
 0.5f,  0.5f,  1.0f,  1.0f, 0.0f,
-0.5f,  0.5f,  1.0f,  0.0f, 0.0f,
-0.5f,  0.5f, -1.0f,  0.0f, 1.0f
};


class Metodos
{

public:

    /*--------------- metodos de graficacion -----------------*/
    static int Make_Skybox(Array vao, Shader skyboxShader)
    {
        vao.Bind();
        Buffer vbo(skyboxVertices, sizeof(skyboxVertices));
        vao.linkVBO(vbo, 0, 3, GL_FLOAT, 3 * sizeof(float), (void*)0);
        vao.Unbind();
        vbo.Unbind();

        vector<string> faces
        {
                "textures/Skybox/right.jpg",
                "textures/Skybox/left.jpg",
                "textures/Skybox/top.jpg",
                "textures/Skybox/bottom.jpg",
                "textures/Skybox/front.jpg",
                "textures/Skybox/back.jpg"
        };
        
        unsigned int textureID;
        glGenTextures(1, &textureID);
        glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);

        int width, height, nrChannels;
        for (unsigned int i = 0; i < faces.size(); i++)
        {
            unsigned char* data = stbi_load(faces[i].c_str(), &width, &height, &nrChannels, 0);
            if (data)
            {
                glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
                stbi_image_free(data);
            }
            else
            {
                std::cout << "Cubemap texture failed to load at path: " << faces[i] << std::endl;
                stbi_image_free(data);
            }
        }
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

        skyboxShader.use();
        skyboxShader.setInt("skybox", 0);

        return textureID;
    }

    static void Draw_Skybox(Array skyboxVAO, Shader skyboxShader, glm::mat4 view, glm::mat4 projection, unsigned int cubemapTexture)
    {
        // draw skybox as last
        glDepthFunc(GL_LEQUAL);  // change depth function so depth test passes when values are equal to depth buffer's content
        skyboxShader.use();
        view = glm::mat4(glm::mat3(camera.GetViewMatrix())); // remove translation from the view matrix
        skyboxShader.setMat4("view", view);
        skyboxShader.setMat4("projection", projection);
        // skybox cube
        //glBindVertexArray(skyboxVAO);
        skyboxVAO.Bind();
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapTexture);
        glDrawArrays(GL_TRIANGLES, 0, 36);
        //glBindVertexArray(0);
        skyboxVAO.Unbind();
        glDepthFunc(GL_LESS); // set depth function back to default
    }
    /*--------------------------------------------------------------------------------------------------------------*/
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
        for (float i = 0; i < 20; i++)
        {
            for (float j = 0; j < 20; j++)
            {
                glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
                model = glm::translate(model, glm::vec3(i, 0.0f, j));
                ourShader.setMat4("model", model);
                glDrawArrays(GL_TRIANGLES, 0, 36);
            }
        }
	}
    /*--------------------------------------------------------------------------------------------------------------*/
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
        for (float i = 0; i < 5; i++)
        {
            //wall one
            for (float j = 0; j < 20; j++)
            {
                glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
                model = glm::translate(model, glm::vec3(0.0f, i, j));
                ourShader.setMat4("model", model);
                glDrawArrays(GL_TRIANGLES, 0, 36);
            }
            //wall two
            for (float j = 0; j < 20; j++)
            {
                glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
                model = glm::translate(model, glm::vec3(j, i, 0.0f));
                ourShader.setMat4("model", model);
                glDrawArrays(GL_TRIANGLES, 0, 36);
            }
            //wall three
            for (float j = 0; j < 20; j++)
            {
                glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
                model = glm::translate(model, glm::vec3(19.0f, i, j));
                ourShader.setMat4("model", model);
                glDrawArrays(GL_TRIANGLES, 0, 36);
            }
            //wall four
            for (float j = 0; j < 8; j++)
            {
                glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
                model = glm::translate(model, glm::vec3(j, i, 19.0f));
                ourShader.setMat4("model", model);
                glDrawArrays(GL_TRIANGLES, 0, 36);
            }
            for (float j = 12; j < 20; j++)
            {
                glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
                model = glm::translate(model, glm::vec3(j, i, 19.0f));
                ourShader.setMat4("model", model);
                glDrawArrays(GL_TRIANGLES, 0, 36);
            }
        }
    }
    /*--------------------------------------------------------------------------------------------------------------*/
    static void Make_Roof(Array vao)
    {
        vao.Bind();
        Buffer vbo(vertices, sizeof(vertices));
        vao.linkVBO(vbo, 0, 3, GL_FLOAT, 5 * sizeof(float), (void*)0);
        vao.linkVBO(vbo, 1, 2, GL_FLOAT, 5 * sizeof(float), (void*)(3 * sizeof(float)));
        vao.Unbind();
        vbo.Unbind();
    }

    static void Draw_Roof(Shader ourShader)
    {
        for (float k = 5; k < 10; k++)
        {
            for (float i = 0; i < 20; i++)
            {
                for (float j = 0; j < 20; j++)
                {
                    glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
                    model = glm::translate(model, glm::vec3(i, k, j));
                    ourShader.setMat4("model", model);
                    glDrawArrays(GL_TRIANGLES, 0, 36);
                }
            }
        }   
    }
    /*--------------------------------------------------------------------------------------------------------------*/
    static void Make_Logo(Array vao)
    {
        vao.Bind();
        Buffer vbo(LogoVertices, sizeof(LogoVertices));
        unsigned int EBO;
        glGenBuffers(1, &EBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(LogoIndices), LogoIndices, GL_STATIC_DRAW);
        vao.linkVBO(vbo, 0, 3, GL_FLOAT, 5 * sizeof(float), (void*)0);
        vao.linkVBO(vbo, 1, 2, GL_FLOAT, 5 * sizeof(float), (void*)(3 * sizeof(float)));
        vao.Unbind();
        vbo.Unbind();
    }

    static void Draw_Logo(Shader ourShader)
    {
        glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
        model = glm::translate(model, glm::vec3(9.5f, 7.55f, 19.41f));
        ourShader.setMat4("model", model);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }
/*--------------------------------------------------------------------------------------------------------------*/
    static void Make_Sky(Array vao)
    {
        vao.Bind();
        Buffer vbo(CieloRazoVertices, sizeof(CieloRazoVertices));
        unsigned int EBO;
        glGenBuffers(1, &EBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(CieloIndices), CieloIndices, GL_STATIC_DRAW);
        vao.linkVBO(vbo, 0, 3, GL_FLOAT, 5 * sizeof(float), (void*)0);
        vao.linkVBO(vbo, 1, 2, GL_FLOAT, 5 * sizeof(float), (void*)(3 * sizeof(float)));
        vao.Unbind();
        vbo.Unbind();
    }

    static void Draw_Sky(Shader ourShader)
    {
        glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
        model = glm::translate(model, glm::vec3(9.4f, 4.4f, 9.6f));
        ourShader.setMat4("model", model);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }
    /*--------------------------------------------------------------------------------------------------------------*/

    //static void Make_Door(Array vao)
    //{
    //    vao.Bind();
    //    Buffer vbo(, sizeof());
    //    vao.linkVBO(vbo, 0, 3, GL_FLOAT, 5 * sizeof(float), (void*)0);
    //    vao.linkVBO(vbo, 1, 2, GL_FLOAT, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    //    vao.Unbind();
    //    vbo.Unbind();
    //}
    //
    //static void Draw_Door(Shader ourShader)
    //{
    //    glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    //    model = glm::translate(model, glm::vec3(15.0f, 1.5, 20.0f));
    //    Color.setMat4("model", model);
    //    glDrawArrays(GL_TRIANGLES, 0, 36);
    //}

    static void Make_ContSlogan(Array vao)
    {
        vao.Bind();
        Buffer vbo(ContVertices, sizeof(ContVertices));
        vao.linkVBO(vbo, 0, 3, GL_FLOAT, 5 * sizeof(float), (void*)0);
        vao.linkVBO(vbo, 1, 2, GL_FLOAT, 5 * sizeof(float), (void*)(3 * sizeof(float)));
        vao.Unbind();
        vbo.Unbind();
    }

    static void Draw_ContSlogan(Shader ourShader)
    {
        for (float i = 0; i < 20; i++)
        {
                glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
                model = glm::translate(model, glm::vec3(i, 4.0f, 20.5f));
                ourShader.setMat4("model", model);
                glDrawArrays(GL_TRIANGLES, 0, 36);
        }

    }
/*--------------- metodos de entrada ---------------*/
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