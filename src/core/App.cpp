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
    shutdown();
}

bool App::init() {
    m_window = new Window(1280, 720, "Mi Motor");
    if (!m_window)
        return false;

    initImGui();
    return true;
}

void App::initImGui() {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    ImGuiIO& io = ImGui::GetIO(); 
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

    ImGui::StyleColorsDark();

    GLFWwindow* raw = m_window->raw();

    ImGui_ImplGlfw_InitForOpenGL(raw, true);
    ImGui_ImplOpenGL3_Init("#version 460");
}

void App::mainLoop() {
    while (!m_window->shouldClose()) {

        // Preparación de frame IMGUI
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // --- EJEMPLO: UI mínima ---
        ImGui::Begin("Mi primera UI");
        ImGui::Text("Hola desde ImGui + tu motor.");
        ImGui::End();
        // --------------------------

        glClearColor(0.02f, 0.02f, 0.04f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Render final de ImGui
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        m_window->swapBuffers();
        m_window->pollEvents();
    }
}

void App::shutdownImGui() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void App::shutdown() {
    shutdownImGui();

    delete m_window;
    m_window = nullptr;
}
