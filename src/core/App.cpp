#include "App.hpp"
#include <iostream>

// ImGui
#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"
#include <glm/gtc/matrix_transform.hpp>


App::App() {
    // Nada pesado aquí.
}

App::~App() {
    std::cout << "Running shutdown()\n";
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

    m_renderer = new Renderer();

    m_camera = new Camera();

    m_camera->setPosition(glm::vec3(0,0,3));
    m_camera->lookAt(glm::vec3(0,0,0)); // <<< punto al que mira
    m_camera->setProjection(glm::perspective(glm::radians(70.0f), 1280.f/720.f, 0.1f, 100.f));

    Input::setWindow(m_window->raw()); 

    // --- mesh de prueba ---
    std::vector<Vertex> quadVerts = {
        {{-0.5f, -0.5f, 0}, {0,0,1}, {0,0}},
        {{ 0.5f, -0.5f, 0}, {0,0,1}, {1,0}},
        {{ 0.5f,  0.5f, 0}, {0,0,1}, {1,1}},
        {{-0.5f,  0.5f, 0}, {0,0,1}, {0,1}}
    };

    std::vector<unsigned int> quadIdx = {0,1,2, 2,3,0};

    m_testMesh = new Mesh(quadVerts, quadIdx);

    // --- shader de prueba ---
    const char* vs = R"(
        #version 460 core
        layout(location = 0) in vec3 aPos;
        layout(location = 1) in vec3 aNormal;
        layout(location = 2) in vec2 aUV;
        
        uniform mat4 u_Model;
        uniform mat4 u_View;
        uniform mat4 u_Projection;

        void main() {
            gl_Position = u_Projection * u_View * u_Model * vec4(aPos, 1.0);
        }
    )";

    const char* fs = R"(
        #version 460 core
        out vec4 FragColor;
        void main() {
            FragColor = vec4(1,1,1,1);
        }
    )";

    m_testShader = new Shader(vs, fs);
    m_testMaterial = new Material(m_testShader);

    return true;
}

void App::mainLoop() {
    while (!m_window->shouldClose()) {

        
        // --- 1) Input ---
        updateInput();

        // --- 2) Lógica ---
        update(Time::dt());

        // --- 3) Render ---
        render();


        m_context->swapBuffers();
        m_window->pollEvents();
        Input::update(); 
    }
}

void App::shutdown() {
    if (m_context) {
        m_context->makeCurrent(); // asegurate de tener un contexto activo
    }
    
    delete m_camera;
    delete m_testMaterial;    
    delete m_testShader;
    delete m_testMesh;
    delete m_renderer;
    delete m_gui;
    delete m_context;
    delete m_window;

    m_context = nullptr;
    m_window = nullptr;

    glfwTerminate();

}

void App::updateInput(){
    Input::update();

    // Por ejemplo: mover la cámara
    float speed = 5.0f * (1.0f/60.0f);

    if (Input::isKeyDown(GLFW_KEY_W))
        m_camera->moveLocal({0, 0, -speed});
    if (Input::isKeyDown(GLFW_KEY_S))
        m_camera->moveLocal({0, 0, speed});

    if (Input::isMouseButtonDown(GLFW_MOUSE_BUTTON_RIGHT)) {
        glm::vec2 delta = Input::getMouseDelta();
        m_camera->rotateYawPitch(delta.x * 0.1f, delta.y * 0.1f);
    }
}

void App::update(double dt){
    Time::beginFrame();
}

void App::render(){

    m_renderer->beginFrame(*m_camera);

    DrawCommand cmd;
    cmd.mesh = m_testMesh;
    cmd.material = m_testMaterial;
    cmd.model = glm::mat4(1.0f);

    m_renderer->submit(cmd);

    m_renderer->drawFrame();

    m_gui->begin();

    m_gui->render();

    m_gui->end();

}