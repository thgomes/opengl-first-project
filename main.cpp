#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

int main() {
    // Initialize GLFW
    glfwInit();

    // Configure GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create new GLFW Window
    GLFWwindow* window = glfwCreateWindow(800, 600, "Minha Janela", NULL, NULL);

    if (window == NULL) {
        std::cout << "Falha ao criar janela GLFW" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Make the window the current context
    glfwMakeContextCurrent(window);

    // Load the OpenGL functions with glad
    if (!gladLoadGL()) {
        std::cout << "Falha ao carregar GLAD" << std::endl;
        return -1;
    }

    // Create a viewport
    glViewport(0, 0, 800, 600);

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Render loop (frame)
    while (!glfwWindowShouldClose(window)) {
        // process user inputs
        processInput(window);

        // Rendering commands here...
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Process GLFW events
        glfwPollEvents();
        // Swap the window buffers
        glfwSwapBuffers(window);

    }

    // Clear GLFW before exit
    glfwTerminate();
    return 0;
}

// Callback function that resize viewport if window size change
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

// Function to process the user inputs
void processInput(GLFWwindow *window) {
    // Close window if ESC was pressed
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}