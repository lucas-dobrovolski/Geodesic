#include "Material.hpp"
#include "Shader.hpp"

Material::Material(Shader* shader)
    : m_shader(shader) {}

Material::~Material() {}

void Material::bind() const {
    // En el futuro hará shader->bind();
}
