#pragma once
#include <glm/glm.hpp>

class Camera {
public:
    Camera();
    ~Camera() = default;

    // Setters directos
    void setPosition(const glm::vec3& pos);
    void lookAt(const glm::vec3& target);

    // Setters de matrices (si querés cargarlas manualmente)
    void setProjection(const glm::mat4& proj);

    void moveLocal(const glm::vec3& delta);

    // Rotación tipo FPS (yaw izquierda/derecha, pitch arriba/abajo)
    void rotateYawPitch(float yawDelta, float pitchDelta);

    // Acceso
    const glm::mat4& view() const { return m_view; }
    const glm::mat4& proj() const { return m_proj; }

    // Recalcular vista manualmente (si movés la cámara)
    void updateView();

private:
    glm::vec3 m_position;
    glm::vec3 m_target;
    glm::vec3 m_up;

    // Orientación (en grados)
    float m_yaw;
    float m_pitch;

    glm::mat4 m_view;
    glm::mat4 m_proj;
};
