cmake_minimum_required (VERSION 3.13)

project ("kursovaja")

add_subdirectory ("kursovaja")
add_executable(main kursovaja/kursovaja.cpp)

add_subdirectory(external/glad)
target_link_libraries(kursovaja glad)