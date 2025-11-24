#pragma once
#include <GLFW/glfw3.h>

class Gui {
public:
    Gui(GLFWwindow* window);
    ~Gui();

    void begin();
    void render();
    void end(); // opcional
};