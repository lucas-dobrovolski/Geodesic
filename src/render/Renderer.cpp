#include "Renderer.hpp"
#include "../core/GLContext.hpp"
#include <glad/glad.h>

Renderer::Renderer() {
}

Renderer::~Renderer() {
}

void Renderer::beginFrame(const Camera& cam) {

    m_currentCamera = &cam;
    m_commands.clear();

    glClearColor(0.02f, 0.02f, 0.04f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::submit(const DrawCommand& cmd) {
    m_commands.push_back(cmd);
}

void Renderer::drawFrame() {
    // Próximo paso: recorrer comandos y dibujar meshes
    for (const DrawCommand& cmd : m_commands) {
        cmd.material->bind();
        
        cmd.material->shader()->setMat4("u_Model", cmd.model);
        cmd.material->shader()->setMat4("u_View", m_currentCamera->view);
        cmd.material->shader()->setMat4("u_Projection", m_currentCamera->proj);
        
        cmd.mesh->draw();
    }
}
