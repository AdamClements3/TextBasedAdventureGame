#pragma once

class Shader {
private:
    unsigned int id;
public:
    Shader();
    Shader(const char* vsource, const char* fsource);
    
    void Bind();
    
    inline unsigned int GetId() { return id; }

};