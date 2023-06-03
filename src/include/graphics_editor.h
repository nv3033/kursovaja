#pragma once
#include <glfw/glfw3.h>
#include <glad/glad.h>
#include "objectss.h"
#include <vector>
#include "linmath/linmath.h"



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
    //Quad() = default;

    ~Quad();

    
    Quad::Quad() {

    }

    void Quad::Init(GLfloat* colors, GLfloat* points, int sizec, int size){//, std::vector<vec2> bottom_right_pos, std::vector<vec2> upper_right_pos, std::vector<vec2> bottom_left_pos, std::vector<vec2> upper_left_pos) {
        

        GLuint VertexArrayID;
        glGenVertexArrays(1, &VertexArrayID);
        glBindVertexArray(VertexArrayID);

        glGenBuffers(1, &vertexbuffer);

        glGenBuffers(1, &colorbuffer);
    }
    void Quad::draw_init(GLfloat* colors, GLfloat* points, int sizec, int size) {

        glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
        glBufferData(GL_ARRAY_BUFFER, sizec, colors, GL_STREAM_DRAW);
        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
        glBufferData(GL_ARRAY_BUFFER, size, points, GL_STREAM_DRAW);
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
        glDrawArrays(GL_TRIANGLES, 4, 7);
        glDrawArrays(GL_TRIANGLES, 5, 8);
                
        glDisableVertexAttribArray(0);
    }
    void Quad::clear_buffers(){
        
    }


private:
    //GLfloat points[12];

    GLuint vertexbuffer;
    GLuint colorbuffer;

};

Quad::~Quad() {}