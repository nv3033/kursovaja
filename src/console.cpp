#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <imgui.h>
#include <imgui_impl_opengl3.h>
#include <imgui_impl_glfw.h>
#include "IntoTheVoidEngine3D_header.h"


int main(void)
{
    std::string input_stream;
    int current_input_return = start_engine();
    if (current_input_return != 0) return -1;

    while (true) {
        std::cin >> input_stream;
        current_input_return = execute_input(input_stream);
        if (current_input_return == 1) return 0;
        else if (current_input_return != 0) return -1;
    }

    return 0;
}

