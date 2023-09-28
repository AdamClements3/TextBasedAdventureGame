#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "Shader.h"

Shader::Shader() {}

Shader::Shader(const char* vsource, const char* fsource) {
    unsigned int vs;
    unsigned int fs;
    
    vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs, 1, &vsource, NULL);
    glCompileShader(vs);
    
    int val;
    glGetShaderiv(vs, GL_COMPILE_STATUS, &val);
    if (val == GL_FALSE) {
        int length;
        glGetShaderiv(vs, GL_INFO_LOG_LENGTH, &length);
        char message[length];
        glGetShaderInfoLog(vs, length, &length, message);
        std::cout << "ERROR: failed to compile vshader (graphics):" << std::endl;
        std::cout << message << std::endl;
    }
    
    fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs, 1, &fsource, NULL);
    glCompileShader(fs);
    
    glGetShaderiv(fs, GL_COMPILE_STATUS, &val);
    if (val == GL_FALSE) {
        int length;
        glGetShaderiv(fs, GL_INFO_LOG_LENGTH, &length);
        char message[length];
        glGetShaderInfoLog(fs, length, &length, message);
        std::cout << "ERROR: failed to compile fshader (graphics):" << std::endl;
        std::cout << message << std::endl;
    }
    
    id = glCreateProgram();
    glAttachShader(id, vs);
    glAttachShader(id, fs);
    glLinkProgram(id);
    glValidateProgram(id);
    
    glDeleteShader(vs);
    glDeleteShader(fs);
    
    glUseProgram(id);
}

void Shader::Bind() {
    glUseProgram(id);
}