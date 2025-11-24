#pragma once

#include <vector>
#include <glm/glm.hpp>

class Mesh;
class Material;
class Camera;

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
    void endFrame();

private:
    glm::mat4 m_view;
    glm::mat4 m_proj;

    std::vector<DrawCommand> m_commands;
};
