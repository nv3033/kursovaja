#pragma once
#include <glfw/glfw3.h>
#include <glad/glad.h>

class Triangle
{
public:
    Triangle() = default;

    ~Triangle();

    void Triangle::Init(GLfloat red, GLfloat green, GLfloat blu) {
        static const GLfloat points[] = {
            0.0f, 0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            -0.5f, -0.5f, 0.0f
        };

        GLfloat colors[] = {
            red, green, blu,
            red, green, blu,
            red, green, blu
        };

        GLuint VertexArrayID;
        glGenVertexArrays(1, &VertexArrayID);
        glBindVertexArray(VertexArrayID);

        glGenBuffers(1, &vertexbuffer);
        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);

        glGenBuffers(1, &colorbuffer);
        glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);
    }
    void Triangle::draw_triangle() {
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
        glVertexAttribPointer(
            0,                  
            3,                 
            GL_FLOAT,           
            GL_FALSE,           
            0,                  
            (void*)0            
        );
        glEnableVertexAttribArray(1);
        glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
        glVertexAttribPointer(
            1,                  
            3,                  
            GL_FLOAT,           
            GL_FALSE,           
            0,                  
            (void*)0            
        );

        glDrawArrays(GL_TRIANGLES, 0, 3); // Начиная с вершины 0, всего 3 вершины -> один треугольник

        glDisableVertexAttribArray(0);
    }


private:
    GLuint vertexbuffer;
    GLuint colorbuffer;

};

Triangle::~Triangle(){}

class Quad
{
public:
    Quad() = default;

    ~Quad();

    void Quad::Init(_color_ color, vec2 bottom_right_pos, vec2 upper_right_pos, vec2 bottom_left_pos, vec2 upper_left_pos) {
        static const GLfloat points[] = {
            bottom_right_pos[0], bottom_right_pos[1], 0.0f,
            upper_right_pos[0], upper_right_pos[1], 0.0f,
            bottom_left_pos[0], bottom_left_pos[1], 0.0f,
            upper_left_pos[0], upper_left_pos[1], 0.0f
        };

        GLfloat colors[] = {
            color.r, color.g, color.b,
            color.r, color.g, color.b,
            color.r, color.g, color.b,
            color.r, color.g, color.b
        };

        GLuint VertexArrayID;
        glGenVertexArrays(1, &VertexArrayID);
        glBindVertexArray(VertexArrayID);

        glGenBuffers(1, &vertexbuffer);
        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);

        glGenBuffers(1, &colorbuffer);
        glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);
    }
    void Quad::draw_quad() {
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
        glVertexAttribPointer(
            0,
            3,
            GL_FLOAT,
            GL_FALSE,
            0,
            (void*)0
        );
        glEnableVertexAttribArray(1);
        glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
        glVertexAttribPointer(
            1,
            3,
            GL_FLOAT,
            GL_FALSE,
            0,
            (void*)0
        );

        glDrawArrays(GL_TRIANGLES, 0, 3);
        glDrawArrays(GL_TRIANGLES, 1, 4);
        //glDrawArrays(GL_TRIANGLES, 4, 7);
        //sglDrawArrays(GL_TRIANGLES, 5, 8);

        glDisableVertexAttribArray(0);
    }
    void Quad::clear_buffers(){
        
    }


private:
    GLuint vertexbuffer;
    GLuint colorbuffer;

};

Quad::~Quad() {}