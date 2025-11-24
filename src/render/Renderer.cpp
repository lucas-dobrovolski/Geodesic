#include "Renderer.hpp"
#include "../core/GLContext.hpp"
#include <glad/glad.h>

Renderer::Renderer() {
}

Renderer::~Renderer() {
}

void Renderer::beginFrame(const Camera& cam) {
    // Por ahora no hay cámara real
    m_commands.clear();

    glClearColor(0.02f, 0.02f, 0.04f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::submit(const DrawCommand& cmd) {
    m_commands.push_back(cmd);
}

void Renderer::endFrame() {
    // Próximo paso: recorrer comandos y dibujar meshes
    for (const DrawCommand& cmd : m_commands) {
        // Nada todavía
    }
}
