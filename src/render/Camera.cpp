#include "Camera.hpp"
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera()
    : m_position(0.0f, 0.0f, 3.0f)
    , m_target(0.0f, 0.0f, 0.0f)
    , m_up(0.0f, 1.0f, 0.0f)
    , m_yaw(-90.0f)       // mirando hacia -Z
    , m_pitch(0.0f)
{
    m_view = glm::lookAt(m_position, m_target, m_up);

    // Proyección por defecto (cambiable)
    m_proj = glm::perspective(
        glm::radians(60.0f),
        16.0f/9.0f,
        0.1f,
        100.0f
    );
}

void Camera::setPosition(const glm::vec3& pos) {
    m_position = pos;
    updateView();
}

void Camera::lookAt(const glm::vec3& target) {
    m_target = target;
    updateView();
}

void Camera::setProjection(const glm::mat4& proj) {
    m_proj = proj;
}


void Camera::moveLocal(const glm::vec3& delta) {
    // calcular forward/right desde yaw/pitch
    glm::vec3 forward;
    forward.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    forward.y = sin(glm::radians(m_pitch));
    forward.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    forward = glm::normalize(forward);

    glm::vec3 right = glm::normalize(glm::cross(forward, m_up));

    m_position += forward * delta.z;  // mover adelante/atrás
    m_position += right   * delta.x;  // mover izq/der
    m_position += m_up    * delta.y;  // mover vertical

    updateView();
}

void Camera::rotateYawPitch(float yawDelta, float pitchDelta) {
    m_yaw   += yawDelta;
    m_pitch += pitchDelta;

    // Limitar pitch para evitar "flip"
    if (m_pitch > 89.0f)  m_pitch = 89.0f;
    if (m_pitch < -89.0f) m_pitch = -89.0f;

    updateView();
}

void Camera::updateView() {
    glm::vec3 forward;
    forward.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    forward.y = sin(glm::radians(m_pitch));
    forward.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));

    m_target = m_position + glm::normalize(forward);

    m_view = glm::lookAt(m_position, m_target, m_up);
}