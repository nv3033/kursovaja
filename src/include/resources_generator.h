#pragma once
#include"objectss.h"
#include"glad/glad.h"

#include<iostream>



class Resources_generator
{
public:
	Resources_generator() = default;
	~Resources_generator();

    Wall wall1;
    Wall wall2;
    GLfloat p[24] = {};
    GLfloat colors[24] = {};


    GLfloat* Resources_generator::points() {
        float walls[] = { 0.5f, 1, 0.5f, 2, -0.5f, 1, -0.5f, 2 };
            /*0.5f, -0.5f, 2,
            0.5f, 0.5f, 2,
            0.5f, -0.5f, 1,
            0.5f, 0.5f, 1,
            -0.5f, -0.5f, 1,
            -0.5f, 0.5f, 1,
            -0.5f, -0.5f, 2,
            -0.5f, 0.5f, 2
        };*/
        for (int i = 0; i < 4; i++) {
            p[i * 6] = walls[i*2];
            p[i * 6 + 2] = walls[i*2 + 1];
            p[i * 6 + 3] = walls[i*2];
            p[i * 6 + 5] = walls[i*2 + 1];
            p[i * 6 + 1] = -0.5f;
            p[i * 6 + 4] = 0.5f;
        }
        std::cout << p[2] << " " << p[3] << " " << p[6] << " " << p[9] << std::endl;
        return p;
    }

    GLfloat get_point(int i) {
        return p[i];
    }

    GLfloat* Resources_generator::color() {
        wall1.color = {1, 0, 0};
        wall2.color = { 0, 0, 1 };
        for (int i = 0; i < 24; i++) {
            if (i < 12) {
                if (i % 3 == 0) colors[i] = wall1.color.r;
                if (i % 3 == 1) colors[i] = wall1.color.b;
                if (i % 3 == 2) colors[i] = wall1.color.g;
            }
            else {
                if (i % 3 == 0) colors[i] = wall2.color.r;
                if (i % 3 == 1) colors[i] = wall2.color.b;
                if (i % 3 == 2) colors[i] = wall2.color.g;
            }
        }
        return colors;
    }
    GLfloat get_color(int i) {
        return colors[i];
    }
private:
};

Resources_generator::~Resources_generator() {

}

