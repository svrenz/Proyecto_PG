#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// Funciones de GLFW
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

int main() {
    // Inicializar GLFW
    if (!glfwInit()) {
        std::cerr << "Error al inicializar GLFW" << std::endl;
        return -1;
    }

    // Configurar GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE); // Desactiva el redimensionamiento de la ventana

    // Crear ventana de GLFW con ventana completa
    GLFWwindow* window = glfwCreateWindow(1150, 680, "Super Market", glfwGetPrimaryMonitor(), NULL);
    if (!window) {
        std::cerr << "Error al crear la ventana de GLFW" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Establecer el modo de pantalla completa
    int width, height;
    glfwGetWindowSize(window, &width, &height);
    glfwSetWindowPos(window, 0, 0);
    glfwSetWindowSize(window, width, height);

    // Hacer que la ventana sea el contexto actual
    glfwMakeContextCurrent(window);

    // Inicializar GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Error al inicializar GLAD" << std::endl;
        return -1;
    }

    // Configurar el viewport
    glViewport(0, 0, width, height);

    // Bucle principal del juego
    while (!glfwWindowShouldClose(window)) {
        // Procesar entrada del usuario
        processInput(window);

        // Dibujar aqu?
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Dibujar los objetos del juego aqu?

        // Intercambiar b?feres
        glfwSwapBuffers(window);

        // Revisar eventos
        glfwPollEvents();
    }

    // Limpiar y salir
    glfwTerminate();
    return 0;
}

// Funci?n de callback para el cambio de tama?o de la ventana
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

// Funci?n para procesar la entrada del usuario
void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}