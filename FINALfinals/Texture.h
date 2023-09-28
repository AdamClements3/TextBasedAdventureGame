#pragma once

#include <string>

#include "Shader.h"

class Texture {
private:
    std::string path;
    unsigned int id;
    int num;
    
    static int num_textures;
public:
    Texture();
    Texture(std::string in_path);
    
    void Bind(Shader& shader);
    
    inline std::string GetPath() const { return path; }
};