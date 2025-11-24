#include "App.hpp"
#include <iostream>

// ImGui
#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"


App::App() {
    // Nada pesado aquí.
}

App::~App() {
    shutdown();
}

void App::run() {
    if (!init()) {
        std::cerr << "Error al iniciar la aplicación.\n";
        return;
    }

    mainLoop();
}

bool App::init() {
    m_window = new Window(1280, 720, "Mi Motor");
    if (!m_window)
        return false;

    m_context = new GLContext(m_window->raw());
    m_context->makeCurrent();

    m_gui = new Gui(m_window->raw());

    return true;
}

void App::mainLoop() {
    while (!m_window->shouldClose()) {

        glClearColor(0.02f, 0.02f, 0.04f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        m_gui->begin();

        m_gui->render();

        m_gui->end();

        m_context->swapBuffers();
        m_window->pollEvents();
    }
}

void App::shutdown() {
    if (m_context) {
        m_context->makeCurrent(); // asegurate de tener un contexto activo
    }

    delete m_gui;


    delete m_context;
    delete m_window;
    m_context = nullptr;
    m_window = nullptr;

    glfwTerminate();
}
