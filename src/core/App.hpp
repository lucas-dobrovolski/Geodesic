#pragma once

#include <memory>

#include "Window.hpp"
#include "GLContext.hpp"

#include "../render/gui/Gui.hpp"
#include "../render/Renderer.hpp"
#include "../render/Mesh.hpp"
#include "../render/Material.hpp"
#include "../render/Shader.hpp"

class Camera;

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

    Renderer* m_renderer = nullptr;
    Camera* m_camera = nullptr;

    Mesh* m_testMesh = nullptr;
    Material* m_testMaterial = nullptr;
    Shader* m_testShader = nullptr;

};
