#pragma once

#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window {
public:
    Window(int width, int height, const std::string& title);
    ~Window();

    bool shouldClose() const;
    void pollEvents() const;

    GLFWwindow* raw() const { return m_window; }
    
private:
    GLFWwindow* m_window = nullptr;
};
