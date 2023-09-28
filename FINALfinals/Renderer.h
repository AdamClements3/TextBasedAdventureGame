#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <vector>

#include "Texture.h"
#include "VertexArray.h"
#include "Shader.h"

class Renderer {
private:
    GLFWwindow* window;
    int width, height;
    
    unsigned int rect_ibo;
    
    Shader rect_shader;
    Shader health_shader;
    
    std::vector<Texture> textures;
    
    Texture bg_tex;
    VertexArray bg_buffer;
    
    Texture enemy_tex;
    VertexArray enemy_buffer;

    Texture item_tex;
    VertexArray item_buffer;
    
    VertexArray health_bar_buffer;
    
    bool draw_enemy, draw_item;
public:
    Renderer(int width_in, int height_in); // Constructor, input a width and height
    ~Renderer(); // Destructor
        
    void SetBG(std::string path); // Sets the background
    void SetEnemy(std::string path); // Sets the enemy. To display no enemy input ""
    void SetItem(std::string path); // Sets the item. To display no item input ""
    void SetHealth(float health_in); // Sets the health. health is 0-100
    
    bool Close(); // Checks to see if the window should close
    
    void Draw(); // Draws the scene
};