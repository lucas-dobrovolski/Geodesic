#pragma once

#include <memory>
#include "Window.hpp"
#include "GLContext.hpp"
#include "../render/gui/Gui.hpp"
class App {
public:
    App();
    ~App();
    void run();

private:
    bool init();
    void mainLoop();
    void shutdown();

    void initImGui();
    void shutdownImGui();

    Window* m_window;
    GLContext* m_context;
    Gui* m_gui;

};
