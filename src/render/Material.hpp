#pragma once

class Shader;

class Material {
public:
    Material(Shader* shader);
    ~Material();

    void bind() const;

private:
    Shader* m_shader;
};
