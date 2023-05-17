// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
#include "libraries.h"

void processInput(GLFWwindow *window){
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) glfwSetWindowShouldClose(window, true);
    if(glfwGetKey(window,GLFW_KEY_LEFT) == GLFW_PRESS) std::cout << "GLFW_KEY_LEFT pressed" << std::endl;
    if(glfwGetKey(window,GLFW_KEY_RIGHT) == GLFW_PRESS) std::cout << "GLFW_KEY_RIGHT pressed" << std::endl;
    if(glfwGetKey(window,GLFW_KEY_UP) == GLFW_PRESS) std::cout << "GLFW_KEY_UP pressed" << std::endl;
    if(glfwGetKey(window,GLFW_KEY_DOWN) == GLFW_PRESS) std::cout << "GLFW_KEY_DOWN pressed" << std::endl;
    if(glfwGetKey(window,GLFW_KEY_ENTER) == GLFW_PRESS) std::cout << "GLFW_KEY_ENTER pressed" << std::endl;
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    std::cout << "callback (\"framebuffer_size_callback\") execute" << std::endl;
    glViewport(0, 0, width, height);
}