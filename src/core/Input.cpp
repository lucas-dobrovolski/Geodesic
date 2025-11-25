#include "Input.hpp"

GLFWwindow* Input::s_window = nullptr;

unsigned char Input::s_keys[512] = {};
unsigned char Input::s_mouseButtons[8] = {};

glm::vec2 Input::s_mousePos       = glm::vec2(0.0f);
glm::vec2 Input::s_lastMousePos   = glm::vec2(0.0f);
glm::vec2 Input::s_mouseDelta     = glm::vec2(0.0f);

bool Input::s_firstFrame = true;

void Input::setWindow(GLFWwindow* window) {
    s_window = window;

    // Registrar callbacks
    glfwSetKeyCallback(window, glfw_key_callback);
    glfwSetMouseButtonCallback(window, glfw_mouse_button_callback);
    glfwSetCursorPosCallback(window, glfw_cursor_pos_callback);
}

void Input::update() {
    if (!s_window) return;

    if (s_firstFrame) {
        s_lastMousePos = s_mousePos;
        s_firstFrame = false;
    }

    s_mouseDelta = s_mousePos - s_lastMousePos;
    s_lastMousePos = s_mousePos;
}

bool Input::isKeyDown(int key) {
    return s_keys[key];
}

bool Input::isMouseButtonDown(int button) {
    return s_mouseButtons[button];
}

glm::vec2 Input::getMousePos() {
    return s_mousePos;
}

glm::vec2 Input::getMouseDelta() {
    return s_mouseDelta;
}

// ==========================
// CALLBACKS GLFW
// ==========================

void glfw_key_callback(GLFWwindow*, int key, int, int action, int) {
    if (key < 0 || key >= 512) return;

    Input::s_keys[key] = (action != GLFW_RELEASE);
}

void glfw_mouse_button_callback(GLFWwindow*, int button, int action, int) {
    if (button < 0 || button >= 8) return;

    Input::s_mouseButtons[button] = (action != GLFW_RELEASE);
}

void glfw_cursor_pos_callback(GLFWwindow*, double x, double y) {
    Input::s_mousePos = glm::vec2(x, y);
}
