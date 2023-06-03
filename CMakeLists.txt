cmake_minimum_required (VERSION 3.13)

set(PROJECT_NAME IntoTheVoidEngine)
project (${PROJECT_NAME})


set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)


add_executable(IntoTheVoidEngine "src/console.cpp" "src/include/Window_header.h" "src/include/console_ui.h" "src/include/graphics_editor.h" "src/include/console_commands.h" "src/include/objectss.h" "src/include/Camera.h" "external/stb_image.h" "src/include/graphics_game.h" "src/include/keyboard.h" "src/include/texture_manager.cpp" "src/include/resources_generator.h")

add_subdirectory(external/glfw)
target_link_libraries(${PROJECT_NAME} glfw)

add_subdirectory(external/glad)
target_link_libraries(${PROJECT_NAME} glad)

add_subdirectory(external/imgui)
target_link_libraries(${PROJECT_NAME} ImGui)

add_subdirectory(external/linmath)

target_include_directories(ImGui PUBLIC external/)
target_link_libraries(ImGui PRIVATE glad glfw)