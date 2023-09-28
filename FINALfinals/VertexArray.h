#pragma once

class VertexArray {
private:
    unsigned int id;
    unsigned int vbo;
    unsigned int ibo;
public:
    VertexArray();
    VertexArray(float* vertices);
    
    void Bind();
};