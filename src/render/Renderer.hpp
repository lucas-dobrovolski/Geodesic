#pragma once

#include <vector>
#include <glm/glm.hpp>
#include "Material.hpp"
#include "Mesh.hpp"
#include "Shader.hpp"


struct Camera {
    glm::mat4 view;
    glm::mat4 proj;
};


struct DrawCommand {
    Mesh* mesh;
    Material* material;
    glm::mat4 model;
};

class Renderer {
public:
    Renderer();
    ~Renderer();

    void beginFrame(const Camera& cam);
    void submit(const DrawCommand& cmd);
    void drawFrame();

private:
    glm::mat4 m_view;
    glm::mat4 m_proj;

    std::vector<DrawCommand> m_commands;
    const Camera* m_currentCamera = nullptr; 
};
