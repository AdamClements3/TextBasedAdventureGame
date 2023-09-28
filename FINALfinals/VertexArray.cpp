#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "VertexArray.h"

VertexArray::VertexArray() {}

VertexArray::VertexArray(float* vertices) {
    glGenVertexArrays(1, &id);
    glBindVertexArray(id);
    
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, 4 * 4 * sizeof(float), vertices, GL_STATIC_DRAW);
    
    // Sets the layout for our VertexArrays
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*) 0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*) (2 * sizeof(float)));
    
    unsigned int indices[] = {
        0, 1, 2,
        2, 3, 0
    };
    glGenBuffers(1, &ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), indices, GL_STATIC_DRAW);
}

void VertexArray::Bind() {
    glBindVertexArray(id);
}