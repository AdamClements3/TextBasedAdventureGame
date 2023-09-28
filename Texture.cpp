#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stb_image/stb_image.h>

#include <iostream>

#include "Texture.h"
#include "Shader.h"

int Texture::num_textures = 0;

Texture::Texture() {}

Texture::Texture(std::string in_path) : path(in_path) {
    int w, h, bpp;
    stbi_set_flip_vertically_on_load(1);
    unsigned char* image_data = stbi_load(path.c_str(), &w, &h, &bpp, 4);
    if (image_data == nullptr)
        std::cout << "Error: problem loading image \"" << path << "\" (graphics)" << std::endl;  

    num = num_textures;
    num_textures++;
    
    glActiveTexture(GL_TEXTURE0 + num);      
    
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_data);
    stbi_image_free(image_data);
}

void Texture::Bind(Shader& shader) { 
    glActiveTexture(GL_TEXTURE0 + num);
    glBindTexture(GL_TEXTURE_2D, id);
    
    int location = glGetUniformLocation(shader.GetId(), "u_Texture");
    glUniform1i(location, num);
}