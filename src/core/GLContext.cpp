#include "GLContext.hpp"

GLContext::GLContext(GLFWwindow* window) : m_window(window) {
    if (!m_window) {
        std::cerr << "Error: GLContext requiere una ventana válida.\n";
        return;
    }

    glfwMakeContextCurrent(m_window);
    glfwSwapInterval(1); // VSync

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Error: No se pudo inicializar GLAD.\n";
    }
    
    glEnable(GL_DEPTH_TEST);
}

GLContext::~GLContext() {
    // No se destruye la ventana aquí, solo el contexto
}

void GLContext::makeCurrent() const {
    if (m_window)
        glfwMakeContextCurrent(m_window);
}

void GLContext::swapBuffers() const {
    if (m_window)
        glfwSwapBuffers(m_window);
}
