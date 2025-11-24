#include <iostream>
#include "Window.hpp"

Window::Window(int width, int height, const std::string& title) {
    if (!glfwInit()) {
        std::cerr << "Error: No se pudo inicializar GLFW.\n";
        return;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if (!m_window) {
        std::cerr << "Error: No se pudo crear la ventana GLFW.\n";
        glfwTerminate();
        return;
    }

}

Window::~Window() {
    if (m_window) {
        glfwDestroyWindow(m_window);
    }

}

bool Window::shouldClose() const {
    return m_window && glfwWindowShouldClose(m_window);
}

void Window::pollEvents() const {
    glfwPollEvents();
}
