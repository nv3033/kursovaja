#include <imgui.h>
#include <imgui_impl_opengl3.h>
#include <imgui_impl_glfw.h>
#include <linmath/linmath.h>

#include "include/Window_header.h"
#include "include/console_ui.h"
#include "include/shaders/shader.h"
#include "include/graphics_editor.h"
#include "include/objectss.h"
#include "include/Camera.h"
#include "include/keyboard.h"
#include "include/resources_generator.h"

#include <iostream>
#include <map>
#include <string>
#include <array>

static int start_engine() {
    std::cout << "Into The Void ENGINE 0.0.1:2023" << std::endl;
    return 0;
}

static int open_engine_editor() {

    window window_console(640, 640, "console");
    window_console.create();

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui_ImplOpenGL3_Init();
    ImGui_ImplGlfw_InitForOpenGL(window_console.get_glfw_window(), true);
    ImGuiIO& io = ImGui::GetIO();
    io.DisplaySize.x = 1280;
    io.DisplaySize.y = 720;

    console con;
    bool open = true;
    Shader shader("C:/users/ant/Desktop/GitHub/kursovaja/src/include/shaders/vertex/triangle-shader.vs",
        "C:/users/ant/Desktop/GitHub/kursovaja/src/include/shaders/fragment/triangle-shader.fs");
    while (!glfwWindowShouldClose(window_console.get_glfw_window()))
    {
        glClearColor(0, 0, 0, 1);

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        shader.use();


        
        con.Draw("console", &open);

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window_console.get_glfw_window());
        glfwPollEvents();

        glClear(GL_COLOR_BUFFER_BIT);
    }
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    glfwTerminate();
    return 0;
}

static int engine_close() { return 1; }

static int open_engine_game() {

    window window_game(480, 480, "game title");
    window_game.create();

    Camera c;

    Resources_generator rg;

    GLfloat perp[24];
    Wall::_color_ color = { 1, 0, 0 };
    Wall::_color_ color2 = { 0.5f, 0, 0 };

    /*Camera c;

    float perp[24];

    GLfloat p[] = {
        0.5f, -0.5f, 2,
        0.5f, 0.5f, 2,
        0.5f, -0.5f, 1,
        0.5f, 0.5f, 1,
        -0.5f, -0.5f, 1,
        -0.5f, 0.5f, 1,
        -0.5f, -0.5f, 2,
        -0.5f, 0.5f, 2
    };
    GLfloat colors[] = {
            color2.r, color2.g, color2.b,
            color2.r, color2.g, color2.b,
            color.r, color.g, color.b,
            color.r, color.g, color.b,
            color.r, color.g, color.b,
            color.r, color.g, color.b,
            color2.r, color2.g, color2.b,
            color2.r, color2.g, color2.b
    };*/
    
    //bool Collide_positeve_with_wall1 = false;
    //bool Collide_with_wall2 = false;

    Quad q;

    GLfloat p[24];
    rg.points();
    for (int i = 0; i < 24; i++)
        p[i] = rg.get_point(i);
    GLfloat colors[24];
    rg.color();
    for (int i = 0; i < 24; i++)
        colors[i] = rg.get_color(i);

    std::cout << p[2] << " " << p[3] << " " << p[6] << " " << p[9] << std::endl;

    for (int i = 0; i < 24; i++) 
        perp[i] = c.perspective(p)[i];
    q.Init(colors, perp, sizeof(colors), sizeof(perp));

    bool open = true;
    Shader shader("C:/users/ant/Desktop/GitHub/kursovaja/src/include/shaders/vertex/triangle-shader.vs",
        "C:/users/ant/Desktop/GitHub/kursovaja/src/include/shaders/fragment/triangle-shader.fs");
    while (!glfwWindowShouldClose(window_game.get_glfw_window()))
    {
        glClearColor(0, 0, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT);
        shader.use(); 



        if (glfwGetKey(window_game.get_glfw_window(), GLFW_KEY_D) == GLFW_PRESS)
        {
            c.rotatey(p, 0.0005f);
        }
        if (glfwGetKey(window_game.get_glfw_window(), GLFW_KEY_A) == GLFW_PRESS)
        {
            c.rotatey(p, -0.0005f);
        }
        if (glfwGetKey(window_game.get_glfw_window(), GLFW_KEY_W) == GLFW_PRESS)
        {
            c.translatez(p, -0.0005f);
        }
        if (glfwGetKey(window_game.get_glfw_window(), GLFW_KEY_S) == GLFW_PRESS)
        {
            c.translatez(p, 0.0005f);
        }
        
        
        //c.translatex(p, 0.00001f);
        for (int i = 0; i < 24; i++) 
            perp[i] = c.perspective(p)[i];
        q.draw_init(colors,perp, sizeof(colors), sizeof(perp));
        q.draw_quad();
        glfwSwapBuffers(window_game.get_glfw_window());
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}

static int execute_input(const std::string input) {
    std::map <std::string, int> inpt;
    inpt[""] = 0;
    inpt["start_editor"] = 1;
    inpt["close"] = 2;
    inpt["start_game"] = 3;
    int i = inpt[input];
    switch (i)
    {
    case 0:
        return 0;
    case 1:
        return open_engine_editor();
    case 2:
        return engine_close();
    case 3:
        return open_engine_game();
    default:
        break;
    }
}
