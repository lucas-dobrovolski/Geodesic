// Shader.cpp
#include "Shader.hpp"
#include <iostream>

Shader::Shader(const char* vertexSrc, const char* fragmentSrc) {
    GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vertexSrc, nullptr);
    glCompileShader(vertex);
    // TODO: check compile errors

    GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fragmentSrc, nullptr);
    glCompileShader(fragment);
    // TODO: check compile errors

    m_program = glCreateProgram();
    glAttachShader(m_program, vertex);
    glAttachShader(m_program, fragment);
    glLinkProgram(m_program);
    // TODO: check link errors

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

Shader::~Shader() {
    glDeleteProgram(m_program);
}

void Shader::bind() const {
    glUseProgram(m_program);
}

void Shader::setMat4(const char* name, const glm::mat4& value) const {
    GLint loc = glGetUniformLocation(m_program, name);
    glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(value));
}

void Shader::setVec3(const char* name, const glm::vec3& value) const {
    GLint loc = glGetUniformLocation(m_program, name);
    glUniform3fv(loc, 1, &value[0]);
}

void Shader::setFloat(const char* name, float value) const {
    GLint loc = glGetUniformLocation(m_program, name);
    glUniform1f(loc, value);
}