#pragma once
#include <vector>
#include <glad/glad.h>

struct Vertex {
    float position[3];
    float normal[3];
    float uv[2];
};

class Mesh {
public:
    Mesh(const std::vector<Vertex>& vertices,
         const std::vector<unsigned int>& indices);

    ~Mesh();
    void bind() const { glBindVertexArray(m_vao); }
    void draw() const;
    GLsizei indexCount() const { return m_indexCount; }
private:
    GLuint m_vao = 0;
    GLuint m_vbo = 0;
    GLuint m_ebo = 0;

    GLsizei m_indexCount = 0;

    void setupMesh(const std::vector<Vertex>& vertices,
                   const std::vector<unsigned int>& indices);
};
