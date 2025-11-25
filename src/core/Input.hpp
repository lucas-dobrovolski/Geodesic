#pragma once
#include <GLFW/glfw3.h>
#include <glm/vec2.hpp>

class Input {
public:
    static void setWindow(GLFWwindow* window);
    static void update();

    static bool isKeyDown(int key);
    static bool isMouseButtonDown(int button);

    static glm::vec2 getMousePos();
    static glm::vec2 getMouseDelta();

private:
    friend void glfw_key_callback(GLFWwindow*, int, int, int, int);
    friend void glfw_mouse_button_callback(GLFWwindow*, int, int, int);
    friend void glfw_cursor_pos_callback(GLFWwindow*, double, double);

    static GLFWwindow* s_window;

    static unsigned char s_keys[512];
    static unsigned char s_mouseButtons[8];

    static glm::vec2 s_mousePos;
    static glm::vec2 s_lastMousePos;
    static glm::vec2 s_mouseDelta;

    static bool s_firstFrame;
};

// Declaraciones de los callbacks (NECESARIAS)
void glfw_key_callback(GLFWwindow*, int, int, int, int);
void glfw_mouse_button_callback(GLFWwindow*, int, int, int);
void glfw_cursor_pos_callback(GLFWwindow*, double, double);
