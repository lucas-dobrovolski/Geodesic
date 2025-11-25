#pragma once

class Shader;

class Material {
public:
    Material(Shader* shader);
    ~Material();

    Shader* shader() const { return m_shader; }
    void bind() const;

private:
    Shader* m_shader;
};
