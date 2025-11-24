#pragma once

class Shader {
public:
    Shader(const char* vs, const char* fs);
    ~Shader();

    void bind() const;

private:
    unsigned int m_program = 0;
};
