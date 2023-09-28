#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "Renderer.h"

void get_errors(const char* area) {
    GLenum err;
    while((err = glGetError()) != GL_NO_ERROR) {
        std::cout << "ERROR: " << err << " in " <<  area << " (graphics)" << std::endl;
    }
}

Renderer::Renderer(int width_in, int height_in) {
    width = width_in;
    height = height_in;
    if (!glfwInit())
        std::cout << "ERROR: Could not load GLFW (graphics)" << std::endl;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    window = glfwCreateWindow(width, height, "graphics", NULL, NULL);
    if (!window){
        glfwTerminate();
        std::cout << "ERROR: Could not create window (graphics)" << std::endl;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)
        std::cout << "ERROR: Could not load GLEW (graphics)" << std::endl;
        
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        
    float bg_vertices[] = {
        -1.0f, -0.8f,     0.0f, 0.0f, // 0
         1.0f, -0.8f,     1.0f, 0.0f, // 1
         1.0f,  1.0f,     1.0f, 1.0f, // 2
        -1.0f,  1.0f,     0.0f, 1.0f  // 3
    };
    bg_buffer = VertexArray(bg_vertices);
    
    get_errors("bg_buffer");
    
    float enemy_vertices[] = {
        -0.5f, -0.8f,     0.0f, 0.0f, // 0
         0.5f, -0.8f,     1.0f, 0.0f, // 1
         0.5f,  1.0f,     1.0f, 1.0f, // 2
        -0.5f,  1.0f,     0.0f, 1.0f  // 3
    };
    enemy_buffer = VertexArray(enemy_vertices);
    
    get_errors("enemy_buffer");
    
    float item_vertices[] = {
        -0.5f, -0.5f,     0.0f, 0.0f, // 0
         0.5f, -0.5f,     1.0f, 0.0f, // 1
         0.5f,  0.5f,     1.0f, 1.0f, // 2
        -0.5f,  0.5f,     0.0f, 1.0f  // 3
    };
    
    item_buffer = VertexArray(item_vertices);
    
    get_errors("item_buffer");
    
    float health_vertices[] = {
        -0.98f, -0.98f,   0.0f, 0.0f, // 0
         0.98f, -0.98f,   1.0f, 0.0f, // 1
         0.98f, -0.82f,   1.0f, 1.0f, // 2
        -0.98f, -0.82f,   0.0f, 1.0f  // 3
    };
    
    health_bar_buffer = VertexArray(health_vertices);
    get_errors("health_bar_buffer");
        
    const char* rect_vertex = 
        "#version 330 core\n"
        "layout (location = 0) in vec2 aPos;\n"
        "layout (location = 1) in vec2 texCoord;\n"
        "out vec2 v_TexCoord;\n"
        "void main() {\n"
        "gl_Position = vec4(aPos, 0.0, 1.0);\n"
        "v_TexCoord = texCoord;\n"
        "}";
        
    const char* rect_fragment = 
        "#version 330 core\n"
        "in vec2 v_TexCoord;\n"
        "out vec4 color\n;"
        "uniform sampler2D u_Texture;\n"
        "void main() {\n"
        "vec4 texColor = texture(u_Texture, v_TexCoord);\n"
        "color = texColor;\n"
        "}";
        
    rect_shader = Shader(rect_vertex, rect_fragment);    
    get_errors("rect_shader");     

    const char* health_vertex = 
        "#version 330 core\n"
        "layout (location = 0) in vec2 aPos;\n"
        "out float ratio;\n"
        "uniform float u_Health;\n"
        "void main() {\n"
        "ratio = (u_Health / 100.0f);\n"
        "gl_Position = vec4(aPos.x * ratio, aPos.y, 0.0, 1.0);\n"
        "}";
        
    const char* health_fragment =
        "#version 330 core\n"
        "in float ratio;\n"
        "out vec4 color;\n;"
        "void main() {\n"
        "color = vec4(1.0, ratio, ratio, 1.0);\n"
        "}";
        
    health_shader = Shader(health_vertex, health_fragment);
    get_errors("health_shader");
        
}

Renderer::~Renderer() {
    glfwTerminate();
}
    
void Renderer::SetBG(std::string path) {
    bool exists = false;
    
    auto i = textures.begin();
    for (; i != textures.end(); i++) {
        if (i->GetPath() == path) {
            exists = true;
            break;
        }
    }
    
    if (!exists) {
        textures.push_back(Texture(path));
        i = textures.end() - 1;
    }
    
    bg_tex = *i;
    
    get_errors("SetBG");
}

void Renderer::SetEnemy(std::string path) {
    if (path == "") {
        draw_enemy = false;
    } else {
        draw_enemy = true;
        bool exists = false;
        
        auto i = textures.begin();
        for (; i != textures.end(); i++) {
            if (i->GetPath() == path) {
                exists = true;
                break;
            }
        }
        
        if (!exists) {
            textures.push_back(Texture(path));
            i = textures.end() - 1;
        }
        
        enemy_tex = *i;
        
        get_errors("SetEnemy");
    }
}

void Renderer::SetItem(std::string path) {
    if (path == "") {
        draw_item = false;
    } else {
        draw_item = true;
        bool exists = false;
        
        auto i = textures.begin();
        for (; i != textures.end(); i++) {
            if (i->GetPath() == path) {
                exists = true;
                break;
            }
        }
        
        if (!exists) {
            textures.push_back(Texture(path));
            i = textures.end() - 1;
        }
        
        item_tex = *i;
        
        get_errors("SetItem");
    }
}

void Renderer::SetHealth(float health_in) {
    health_shader.Bind();
    int location = glGetUniformLocation(health_shader.GetId(), "u_Health");
    glUniform1f(location, health_in);
    
    get_errors("SetHealth");
}

bool Renderer::Close() {
    return glfwWindowShouldClose(window);
}

void Renderer::Draw() {
    glClear(GL_COLOR_BUFFER_BIT);
        
    rect_shader.Bind();
    
    bg_buffer.Bind();
    bg_tex.Bind(rect_shader);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
    
    if (draw_enemy) {
        enemy_buffer.Bind();
        enemy_tex.Bind(rect_shader);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
    }
    
    if (draw_item) {
        item_buffer.Bind();
        item_tex.Bind(rect_shader);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
    }
    
    health_shader.Bind();
    health_bar_buffer.Bind();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

    glfwSwapBuffers(window);

    glfwPollEvents();
    
    get_errors("Draw");
}