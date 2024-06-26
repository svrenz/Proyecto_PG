#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <stb/stb_image.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <sstream>

#include "shaderClass.h"
#include "Textura.h"
#include "Camera.h"
#include "Metodos.h"
#include "Buffer.h"
#include "Array.h"

int main()
{

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Get the primary monitor and its video mode
    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* mode = glfwGetVideoMode(monitor);
    GLFWwindow* window = glfwCreateWindow(mode->width, mode->height, "Full-Screen Window", monitor, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, Metodos::framebuffer_size_callback);
    glfwSetCursorPosCallback(window, Metodos::mouse_callback);
    glfwSetScrollCallback(window, Metodos::scroll_callback);

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glEnable(GL_DEPTH_TEST);
    Shader ourShader("shader.vs", "shader.fs");
    Array vaoFloor, vaoWall;
    Metodos::Make_Floor(vaoFloor);
    Metodos::Make_Wall(vaoWall);
    Textura texPiso("textures/piso.jpg", ourShader), texPared("textures/paredBase.jpg", ourShader);
    ourShader.use();
    texPiso.getLocation(ourShader, 0);
    texPared.getLocation(ourShader, 0);

    while (!glfwWindowShouldClose(window))
    {

        float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // input
        // -----
        Metodos::processInput(window);

        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // also clear the depth buffer now!

        // activate shader
        ourShader.use();

        // bind textures on corresponding texture units
        texPiso.BindText(GL_TEXTURE0);
        // pass projection matrix to shader (note that in this case it could change every frame)
        glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        ourShader.setMat4("projection", projection);
        // camera/view transformation
        glm::mat4 view = camera.GetViewMatrix();
        ourShader.setMat4("view", view);
        vaoFloor.Bind();
        Metodos::Draw_Floor(ourShader);

        texPared.BindText(GL_TEXTURE0);
        vaoWall.Bind();
        Metodos::Draw_Wall(ourShader);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    vaoFloor.Delete();

    glfwTerminate();
    return 0;
}