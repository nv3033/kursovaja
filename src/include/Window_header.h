#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>

class window
{
public:
    window() = default;
    window(const unsigned int width, const unsigned int height, const char* name);
    window(const window& rhs);
    ~window();

    window& window::operator=(window& rhs);

    unsigned int get_width() { return width_; }
    unsigned int get_height() { return height_; }
    const char* get_name() { return name_; }
    GLFWwindow* get_glfw_window() { return window_; }

    int window::create() {
        if (!glfwInit())
        {
            std::cout << "ERROR: Can't initialize OpenGL!";
            return -1;
        }
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
        window_ = glfwCreateWindow(width_, height_, name_, NULL, NULL);
        if (!window_)
        {
            std::cout << "ERROR: Can't open window!";
            glfwTerminate();
            return -1;
        }
        glfwMakeContextCurrent(window_);
        if (!gladLoadGL()) {
            std::cout << "ERROR: OpenGL not loaded!" << std::endl;
            return -1;
        }
        else std::cout << "OpenGL: " << GLVersion.major << "." << GLVersion.minor << std::endl;
        return 0;
    }

private:
    int width_;
    int height_;
    const char* name_;
    GLFWwindow* window_;
};

window::window(const unsigned int width, const unsigned int height, const char* name)
{
    width_ = width;
    height_ = height;
    name_ = name;
}
window::window(const window& rhs)
{
    width_ = rhs.width_;
    height_ = rhs.height_;
    name_ = rhs.name_;
}
window& window::operator=(window& rhs) {
    width_ = rhs.width_;
    height_ = rhs.height_;
    name_ = rhs.name_;
    return *this;
}
window::~window() {}