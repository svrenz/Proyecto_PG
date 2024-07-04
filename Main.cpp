#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <stb/stb_image.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <sstream>
#include <vector>
#include <irrklang/irrKlang.h>

#include "shaderClass.h"
#include "Textura_J.h"
#include "Textura_P.h"
#include "Camera.h"
#include "Metodos.h"
#include "Buffer.h"
#include "Array.h"
#include "Model.h"

using namespace std;
using namespace irrklang;

int main()
{
   
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    // Get the primary monitor and its video mode
    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* mode = glfwGetVideoMode(monitor);
    GLFWwindow* window = glfwCreateWindow(mode->width, mode->height, "SuperMarket", monitor, NULL);
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
   
    stbi_set_flip_vertically_on_load(false);

    glEnable(GL_DEPTH_TEST); //Activar pruebas de profundidad
    Shader ourShader("shader.vs", "shader.fs"), skyboxShader("skybox.vs", "skybox.fs"), modelShader("model.vs", "model.fs"); //shaders

    Array vaoFloor, vaoWall, skyboxVAO, vaoRoof, vaoLogo, vaoSky, vaoContSlogan; //VAOs

    Metodos::Make_Floor(vaoFloor);//Crear piso
    Metodos::Make_Wall(vaoWall); //Crear paredes
    Metodos::Make_Roof(vaoRoof); //crear el techo
    Metodos::Make_Logo(vaoLogo); //crear el logo pali
    Metodos::Make_Sky(vaoSky); //crear el "cielo razo"
    Metodos::Make_ContSlogan(vaoContSlogan); //crear locker

    Model chips("models/assetChips/scene.gltf"); //modelo de estante
    Model ATM("models/ATM/scene.gltf");
    Model Cajero("models/checkout/scene.gltf");
    Model freezer("models/waterFridget/scene.gltf");
    Model terreno("models/terreno/scene.gltf");
    Model mama("models/mamaLucha/scene.gltf");
    Model meat("models/meat/scene.gltf");
    Model frutas("models/frutas/scene.gltf");
    Model mesa("models/mesa/scene.gltf");
    Model bebidas("models/drinks/scene.gltf");

    //cargar texturas
    Textura_J texPiso("textures/piso.jpg", ourShader, GL_REPEAT),
        texPared("textures/paredBase.jpg", ourShader, GL_REPEAT),
        texTecho("textures/techo3.jpg", ourShader, GL_REPEAT);
    
    Textura_P texLogo("textures/logo_pali.png", ourShader);

    unsigned int cubemapTexture = Metodos::Make_Skybox(skyboxVAO, skyboxShader); //crear el skybox

    ourShader.use();

    texPiso.getLocation(ourShader, 0);
    texPared.getLocation(ourShader, 0);
    texTecho.getLocation(ourShader, 0);
    texLogo.getLocation(ourShader, 0);

    //Adding ambient sound
    ISoundEngine* engine = createIrrKlangDevice();
    if (!engine) {
        return 0;
    }
    engine->play2D("Audio/musicstore.mp3", true);

    while (!glfwWindowShouldClose(window))
    {

        float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        Metodos::processInput(window); // input
        // render
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // activar shader
        ourShader.use();
        modelShader.use();

        // bind textures on corresponding texture units

        glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        glm::mat4 view = camera.GetViewMatrix();    

        modelShader.setMat4("projection", projection);
        modelShader.setMat4("view", view);
        
        // render the loaded model        
        Metodos::Draw_Chips(chips, modelShader);
        Metodos::Draw_ATM(ATM, modelShader);
        Metodos::Draw_Checkout(Cajero, modelShader);
        Metodos::Draw_WaterFridget(freezer, modelShader);
        Metodos::Draw_Mama(mama, modelShader);
        Metodos::Draw_Meat(meat, modelShader);
        Metodos::Draw_Frutas(frutas, modelShader);
        Metodos::Draw_Terreno(terreno, modelShader);
        Metodos::Draw_table(mesa, modelShader);
        Metodos::Draw_Drinks(bebidas, modelShader);

        ourShader.setMat4("projection", projection);
        ourShader.setMat4("view", view);

        texPiso.BindText(GL_TEXTURE0);
        vaoFloor.Bind();
        Metodos::Draw_Floor(ourShader); //dibujar el piso
        
        texPared.BindText(GL_TEXTURE0);
        vaoWall.Bind();
        Metodos::Draw_Wall(ourShader); //dibujar paredes
        
        texTecho.BindText(GL_TEXTURE0);
        vaoRoof.Bind();
        Metodos::Draw_Roof(ourShader);
        
        texLogo.BindText(GL_TEXTURE0);
        vaoLogo.Bind();
        Metodos::Draw_Logo(ourShader);
        
        texPared.BindText(GL_TEXTURE0);
        vaoSky.Bind();
        Metodos::Draw_Sky(ourShader);
        
        texTecho.BindText(GL_TEXTURE0);
        vaoContSlogan.Bind();
        Metodos::Draw_ContSlogan(ourShader);


        Metodos::Draw_Skybox(skyboxVAO, skyboxShader, view, projection, cubemapTexture); //graficar skybox


        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    vaoFloor.Delete();

    glfwTerminate();
    return 0;
}