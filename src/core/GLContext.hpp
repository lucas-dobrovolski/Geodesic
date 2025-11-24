#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

class GLContext {
public:
    GLContext(GLFWwindow* window);
    ~GLContext();

    void makeCurrent() const;
    void swapBuffers() const;

private:
    GLFWwindow* m_window = nullptr;
};
