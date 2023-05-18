#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <imgui.h>
#include <imgui_impl_opengl3.h>
#include <imgui_impl_glfw.h>
#include <map>
#include <string>
#include "include/Window_header.h"
#include "include/console_ui.h"
#include "include/shaders/shader.h"
#include "include/graphics.h"


static int start_engine() {
    std::cout << "Into The Void ENGINE 0.0.1:2023" << std::endl;
    return 0;
}



static int open_engine_editor() {
    window window_console(1280, 720, "console");
    window_console.create();

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui_ImplOpenGL3_Init();
    ImGui_ImplGlfw_InitForOpenGL(window_console.get_glfw_window(), true);
    ImGuiIO& io = ImGui::GetIO();
    io.DisplaySize.x = 1280;
    io.DisplaySize.y = 720;
    
    //Triangle tr1;
    //tr1.Init(1, 0, 0);

    console con;
    bool open = true;
    Shader shader("C:/users/ant/Desktop/GitHub/kursovaja/src/include/shaders/vertex/triangle-shader.vs",
        "C:/users/ant/Desktop/GitHub/kursovaja/src/include/shaders/fragment/triangle-shader.fs");
    while (!glfwWindowShouldClose(window_console.get_glfw_window()))
    {
        glClearColor(0, 1, 1, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        shader.use();
        
        //tr1.draw_triangle();
        con.Draw("console", &open);

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window_console.get_glfw_window());
        glfwPollEvents();
    }
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    glfwTerminate();
    return 0;
}

static int engine_close() { return 1; }


static int execute_input(const std::string input) {
    std::map <std::string, int> inpt;
    inpt[""] = 0;
    inpt["start"] = 1;
    inpt["close"] = 2;
    int i = inpt[input];
    switch (i)
    {
    case 0:
        return 0;
    case 1:
        return open_engine_editor();
    case 2:
        return engine_close();
    default:
        break;
    }
}
