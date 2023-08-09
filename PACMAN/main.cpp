#include "utilities.h"
#include "shader.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Cubo", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // configure global opengl state
    // -----------------------------
    glEnable(GL_DEPTH_TEST);

    // build and compile our shader zprogram
    // ------------------------------------
    Shader ourShader("coordinate_systems.vs", "coordinate_systems.fs");
    Shader ourShader2("coordinate_systems.vs", "coordinate_systems.fs");


    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    // //view image geogebra
    // float vertices[] = {
    //     //face botton
    //     -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
    //      0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
    //      0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    //      0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    //     -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
    //     -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

    //     //face up
    //     -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    //      0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
    //      0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
    //      0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
    //     -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
    //     -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

    //     //face left
    //     -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    //     -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    //     -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    //     -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    //     -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    //     -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

    //     // face right
    //      0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    //      0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    //      0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    //      0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    //      0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    //      0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

    //     //face  delante
    //     -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    //      0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
    //      0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
    //      0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
    //     -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    //     -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

    //     //face trasera
    //     -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
    //      0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    //      0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    //      0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    //     -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
    //     -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
    // };
    //view image geogebra
    // float vertices[] = {
    //     //positions             //colors
    //     //face botton           //red
    //     -0.5f, -0.5f, -0.5f,    1.0f, 0.0f, 0.0f,
    //      0.5f, -0.5f, -0.5f,    1.0f, 0.0f, 0.0f,
    //      0.5f,  0.5f, -0.5f,    1.0f, 0.0f, 0.0f,
    //      0.5f,  0.5f, -0.5f,    1.0f, 0.0f, 0.0f,
    //     -0.5f,  0.5f, -0.5f,    1.0f, 0.0f, 0.0f,
    //     -0.5f, -0.5f, -0.5f,    1.0f, 0.0f, 0.0f,

    //     //face up               //green
    //     -0.5f, -0.5f,  0.5f,    0.0f, 1.0f, 0.0f,
    //      0.5f, -0.5f,  0.5f,    0.0f, 1.0f, 0.0f,
    //      0.5f,  0.5f,  0.5f,    0.0f, 1.0f, 0.0f,
    //      0.5f,  0.5f,  0.5f,    0.0f, 1.0f, 0.0f,
    //     -0.5f,  0.5f,  0.5f,    0.0f, 1.0f, 0.0f,
    //     -0.5f, -0.5f,  0.5f,    0.0f, 1.0f, 0.0f,

    //     //face left             //blue
    //     -0.5f,  0.5f,  0.5f,    0.0f, 0.0f, 1.0f,
    //     -0.5f,  0.5f, -0.5f,    0.0f, 0.0f, 1.0f,
    //     -0.5f, -0.5f, -0.5f,    0.0f, 0.0f, 1.0f,
    //     -0.5f, -0.5f, -0.5f,    0.0f, 0.0f, 1.0f,
    //     -0.5f, -0.5f,  0.5f,    0.0f, 0.0f, 1.0f,
    //     -0.5f,  0.5f,  0.5f,    0.0f, 0.0f, 1.0f,

    //     // face right           //yellow
    //      0.5f,  0.5f,  0.5f,    1.0f, 1.0f, 0.0f,
    //      0.5f,  0.5f, -0.5f,    1.0f, 1.0f, 0.0f,
    //      0.5f, -0.5f, -0.5f,    1.0f, 1.0f, 0.0f,
    //      0.5f, -0.5f, -0.5f,    1.0f, 1.0f, 0.0f,
    //      0.5f, -0.5f,  0.5f,    1.0f, 1.0f, 0.0f,
    //      0.5f,  0.5f,  0.5f,    1.0f, 1.0f, 0.0f,

    //     //face  delante         //purple
    //     -0.5f, -0.5f, -0.5f,    0.5f, 0.0f, 0.5f,
    //      0.5f, -0.5f, -0.5f,    0.5f, 0.0f, 0.5f,
    //      0.5f, -0.5f,  0.5f,    0.5f, 0.0f, 0.5f,
    //      0.5f, -0.5f,  0.5f,    0.5f, 0.0f, 0.5f,
    //     -0.5f, -0.5f,  0.5f,    0.5f, 0.0f, 0.5f,
    //     -0.5f, -0.5f, -0.5f,    0.5f, 0.0f, 0.5f,

    // //face trasera              //deep pink
    //     -0.5f,  0.5f, -0.5f,    1.0f, 0.07f, 0.57f,
    //      0.5f,  0.5f, -0.5f,    1.0f, 0.07f, 0.57f,
    //      0.5f,  0.5f,  0.5f,    1.0f, 0.07f, 0.57f,
    //      0.5f,  0.5f,  0.5f,    1.0f, 0.07f, 0.57f,
    //     -0.5f,  0.5f,  0.5f,    1.0f, 0.07f, 0.57f,
    //     -0.5f,  0.5f, -0.5f,    1.0f, 0.07f, 0.57f,
    // };

    float base[] = {
        //positions             //colors
        //face botton           //red
        //celeste
        -1.3f, -1.3f, -0.1f,   0.04f, 0.71f, 0.94f, //a
        1.3f, -1.3f, -0.1f,   0.04f, 0.71f, 0.94f, //b 
        1.3f, -1.3f, 0.1f,  0.04f, 0.71f, 0.94f,  //c
        1.3f, -1.3f, 0.1f,   0.04f, 0.71f, 0.94f, //d
        -1.3f, -1.3f, 0.1f,  0.04f, 0.71f, 0.94f,  //e
        -1.3f, -1.3f, -0.1f,   0.04f, 0.71f, 0.94f,//f

        -1.3f, -1.2f, -0.1f,   0.04f, 0.71f, 0.94f, //g
        1.3f, -1.2f, -0.1f,   0.04f, 0.71f, 0.94f,//h
        1.3f, -1.2f, 0.1f,   0.04f, 0.71f, 0.94f, //i
        1.3f, -1.2f, 0.1f,   0.04f, 0.71f, 0.94f, //j
        -1.3f, -1.2f, 0.1f,  0.04f, 0.71f, 0.94f, //k
        -1.3f, -1.2f, -0.1f,   0.04f, 0.71f, 0.94f,   //l

        1.3f, -1.3f, 0.1f,   0.04f, 0.71f, 0.94f, //c
        -1.3f, -1.3f, 0.1f,  0.04f, 0.71f, 0.94f, //e
        1.3f, -1.2f, 0.1f,   0.04f, 0.71f, 0.94f,  //j
        1.3f, -1.2f, 0.1f,   0.04f, 0.71f, 0.94f,  //j
        -1.3f, -1.2f, 0.1f,  0.04f, 0.71f, 0.94f, //k
        -1.3f, -1.3f, 0.1f,  0.04f, 0.71f, 0.94f, //e

        ///////////////////////////////////////////
        //green
        -1.3f, 1.3f, -0.1f,   0.0f, 1.0f, 0.0f, //a'
        1.3f, 1.3f, -0.1f,   0.0f, 1.0f, 0.0f, //b '
        1.3f, 1.3f, 0.1f,   0.0f, 1.0f, 0.0f,  //c'
        1.3f, 1.3f, 0.1f,   0.0f, 1.0f, 0.0f,  //d'
        -1.3f, 1.3f, 0.1f,  0.0f, 1.0f, 0.0f,  //e'
        -1.3f, 1.3f, -0.1f,   0.0f, 1.0f, 0.0f,//f'

        -1.3f, 1.2f, -0.1f,   0.0f, 1.0f, 0.0f, //g'
        1.3f, 1.2f, -0.1f,   0.0f, 1.0f, 0.0f, //h'
        1.3f, 1.2f, 0.1f,   0.0f, 1.0f, 0.0f,  //i'
        1.3f, 1.2f, 0.1f,   0.0f, 1.0f, 0.0f,  //j'
        -1.3f, 1.2f, 0.1f,  0.0f, 1.0f, 0.0f,  //k'
        -1.3f, 1.2f, -0.1f,   0.0f, 1.0f, 0.0f,//l'

        1.3f, 1.3f, 0.1f,   0.0f, 1.0f, 0.0f,  //c'
        -1.3f, 1.3f, 0.1f,  0.0f, 1.0f, 0.0f,  //e'
        1.3f, 1.2f, 0.1f,   0.0f, 1.0f, 0.0f,  //j'
        1.3f, 1.2f, 0.1f,   0.0f, 1.0f, 0.0f,  //j'
        -1.3f, 1.2f, 0.1f,  0.0f, 1.0f, 0.0f,  //k'
        -1.3f, 1.3f, 0.1f,  0.0f, 1.0f, 0.0f,  //e'

        ///////////////////////////////////////////

        //red
        -1.3f, 1.3f, 0.1f,   1.0f, 0.0f, 0.0f,
        -1.3f, -1.3f, 0.1f,   1.0f, 0.0f, 0.0f,
        -1.3f, 1.3f, -0.1f,    1.0f, 0.0f, 0.0f,
        -1.3f, -1.3f, 0.1f,   1.0f, 0.0f, 0.0f,
        -1.3f, -1.3f, -0.1f,   1.0f, 0.0f, 0.0f,
        -1.3f, 1.3f, -0.1f,    1.0f, 0.0f, 0.0f,

        -1.4f, -1.3f, -0.1f,  1.0f, 0.0f, 0.0f,
        -1.4f, -1.3f, 0.1f,   1.0f, 0.0f, 0.0f,
        -1.4f, 1.3f, -0.1f,  1.0f, 0.0f, 0.0f,
        -1.4f, 1.3f, -0.1f,   1.0f, 0.0f, 0.0f,
        -1.4f, -1.3f, 0.1f,   1.0f, 0.0f, 0.0f,
        -1.4f, 1.3f, 0.1f,   1.0f, 0.0f, 0.0f,

    
        -1.4f, 1.3f, 0.1f,   1.0f, 0.0f, 0.0f,
        -1.4f, -1.3f, 0.1f,   1.0f, 0.0f, 0.0f,
        -1.3f, -1.3f, 0.1f, 1.0f, 0.0f, 0.0f,

        -1.3f, -1.3f, 0.1f,  1.0f, 0.0f, 0.0f,
        -1.3f, 1.3f,  0.1f, 1.0f, 0.0f, 0.0f,
        -1.4f, 1.3f, 0.1f,  1.0f, 0.0f, 0.0f,

        //blue
        1.3f, 1.3f, 0.1f,   0.0f, 0.0f, 1.0f,
        1.3f, -1.3f, 0.1f,    0.0f, 0.0f, 1.0f,
        1.3f, 1.3f, -0.1f,     0.0f, 0.0f, 1.0f,
        1.3f, -1.3f, 0.1f,    0.0f, 0.0f, 1.0f,
        1.3f, -1.3f, -0.1f,    0.0f, 0.0f, 1.0f,
        1.3f, 1.3f, -0.1f,     0.0f, 0.0f, 1.0f,

        1.4f, -1.3f, -0.1f,   0.0f, 0.0f, 1.0f,
        1.4f, -1.3f, 0.1f,    0.0f, 0.0f, 1.0f,
        1.4f, 1.3f, -0.1f,   0.0f, 0.0f, 1.0f,
        1.4f, 1.3f, -0.1f,    0.0f, 0.0f, 1.0f,
        1.4f, -1.3f, 0.1f,    0.0f, 0.0f, 1.0f,
        1.4f, 1.3f, 0.1f,    0.0f, 0.0f, 1.0f,

    
        1.4f, 1.3f, 0.1f,   0.0f, 0.0f, 1.0f,
        1.4f, -1.3f, 0.1f,   0.0f, 0.0f, 1.0f,
        1.3f, -1.3f, 0.1f,  0.0f, 0.0f, 1.0f,

        1.3f, -1.3f, 0.1f,   0.0f, 0.0f, 1.0f,
        1.3f, 1.3f,  0.1f, 0.0f, 0.0f, 1.0f,
        1.4f, 1.3f, 0.1f,   0.0f, 0.0f, 1.0f,
    };

    float pacman[] = {
        //pacman
        -0.06f, -0.06f, -0.06f,    0.5f, 0.0f, 0.25f,
         0.06f, -0.06f, -0.06f,    0.5f, 0.0f, 0.25f,
         0.06f,  0.06f, -0.06f,    0.5f, 0.0f, 0.25f,
         0.06f,  0.06f, -0.06f,    0.5f, 0.0f, 0.25f,
        -0.06f,  0.06f, -0.06f,    0.5f, 0.0f, 0.25f,
        -0.06f, -0.06f, -0.06f,    0.5f, 0.0f, 0.25f,

        //face up               //green
        -0.06f, -0.06f,  0.06f,    0.5f, 0.0f, 0.25f,
         0.06f, -0.06f,  0.06f,    0.5f, 0.0f, 0.25f,
         0.06f,  0.06f,  0.06f,    0.5f, 0.0f, 0.25f,
         0.06f,  0.06f,  0.06f,    0.5f, 0.0f, 0.25f,
        -0.06f,  0.06f,  0.06f,    0.5f, 0.0f, 0.25f,
        -0.06f, -0.06f,  0.06f,    0.5f, 0.0f, 0.25f,

        // face left             //blue
        -0.06f,  0.06f,  0.06f,     0.5f, 0.0f, 0.25f,
        -0.06f,  0.06f, -0.06f,     0.5f, 0.0f, 0.25f,
        -0.06f, -0.06f, -0.06f,     0.5f, 0.0f, 0.25f,
        -0.06f, -0.06f, -0.06f,     0.5f, 0.0f, 0.25f,
        -0.06f, -0.06f,  0.06f,     0.5f, 0.0f, 0.25f,
        -0.06f,  0.06f,  0.06f,     0.5f, 0.0f, 0.25f,

        // face right           //yellow
         0.06f,  0.06f,  0.06f,    0.5f, 0.0f, 0.25f,
         0.06f,  0.06f, -0.06f,    0.5f, 0.0f, 0.25f,
         0.06f, -0.06f, -0.06f,    0.5f, 0.0f, 0.25f,
         0.06f, -0.06f, -0.06f,    0.5f, 0.0f, 0.25f,
         0.06f, -0.06f,  0.06f,    0.5f, 0.0f, 0.25f,
         0.06f,  0.06f,  0.06f,    0.5f, 0.0f, 0.25f,

        // face  delante         //purple
        -0.06f, -0.06f, -0.06f,    0.5f, 0.0f, 0.25f,
         0.06f, -0.06f, -0.06f,    0.5f, 0.0f, 0.25f,
         0.06f, -0.06f,  0.06f,    0.5f, 0.0f, 0.25f,
         0.06f, -0.06f,  0.06f,    0.5f, 0.0f, 0.25f,
        -0.06f, -0.06f,  0.06f,    0.5f, 0.0f, 0.25f,
        -0.06f, -0.06f, -0.06f,    0.5f, 0.0f, 0.25f,

    // face trasera              //deep pink
        -0.06f,  0.06f, -0.06f,     0.5f, 0.0f, 0.25f,
         0.06f,  0.06f, -0.06f,     0.5f, 0.0f, 0.25f,
         0.06f,  0.06f,  0.06f,     0.5f, 0.0f, 0.25f,
         0.06f,  0.06f,  0.06f,     0.5f, 0.0f, 0.25f,
        -0.06f,  0.06f,  0.06f,     0.5f, 0.0f, 0.25f,
        -0.06f,  0.06f, -0.06f,     0.5f, 0.0f, 0.25f,
    };

    
    unsigned int VBOs[2], VAOs[2];
    glGenVertexArrays(2, VAOs);
    glGenBuffers(2, VBOs);


    //base
    glBindVertexArray(VAOs[0]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(base), base, GL_STATIC_DRAW);
    // position attribute
    // glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // texture coord attribute
    // glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    // glEnableVertexAttribArray(1);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    //pacman
    glBindVertexArray(VAOs[1]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(pacman), pacman, GL_STATIC_DRAW);
    // position attribute
    // glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // texture coord attribute
    // glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    // glEnableVertexAttribArray(1);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);



    // //BEGIN COMMENT
    // // load and create a texture 
    // // -------------------------
    // unsigned int texture1, texture2;
    // // texture 1
    // // ---------
    // glGenTextures(1, &texture1);
    // glBindTexture(GL_TEXTURE_2D, texture1);
    // // set the texture wrapping parameters
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // // set texture filtering parameters
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // // load image, create texture and generate mipmaps
    // int width, height, nrChannels;
    // stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
    // // unsigned char *data = stbi_load("/home/russell/ComputerGraphics/img/img/peru.jpg", &width, &height, &nrChannels, 0);

	// unsigned char *data = stbi_load("/home/russell/ComputerGraphics/img/img/cono.jpg", &width, &height, &nrChannels, 0);
    // if (data)
    // {
    //     glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    //     glGenerateMipmap(GL_TEXTURE_2D);
    // }
    // else
    // {
    //     std::cout << "Failed to load texture" << std::endl;
    // }
    // stbi_image_free(data);
    // // texture 2
    // // ---------
    // glGenTextures(1, &texture2);
    // glBindTexture(GL_TEXTURE_2D, texture2);
    // // set the texture wrapping parameters
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // // set texture filtering parameters
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // // load image, create texture and generate mipmaps
    // data = stbi_load("/home/russell/ComputerGraphics/img/img/peru.jpg", &width, &height, &nrChannels, 0);
    // if (data)
    // {
    //     // note that the awesomeface.png has transparency and thus an alpha channel, so make sure to tell OpenGL the data type is of GL_RGBA
    //     glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    //     glGenerateMipmap(GL_TEXTURE_2D);
    // }
    // else
    // {
    //     std::cout << "Failed to load texture" << std::endl;
    // }
    // stbi_image_free(data);

    // // tell opengl for each sampler to which texture unit it belongs to (only has to be done once)
    // // -------------------------------------------------------------------------------------------
    // ourShader.use();
    // ourShader.setInt("texture1", 0);
    // ourShader.setInt("texture2", 1);
    // //END COMMENT


    // render loop
    // -----------
    // float angle =0.0;
    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        processInput(window);

        // render
        // ------
        // glClearColor(0.19f, 0.19f, .56f, 1.0f);
        glClearColor(.12f, .12f, .35f, 1.0f);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // also clear the depth buffer now!

        // bind textures on corresponding texture units
        // glActiveTexture(GL_TEXTURE0);
        // glBindTexture(GL_TEXTURE_2D, texture1);
        // glActiveTexture(GL_TEXTURE1);
        // glBindTexture(GL_TEXTURE_2D, texture2);

        // // activate shader
        // ourShader.use();

        // // create transformations
        // // make sure to initialize matrix to identity matrix first
        // glm::mat4 model         = glm::mat4(1.0f);
        // glm::mat4 view          = glm::mat4(1.0f);
        // glm::mat4 projection    = glm::mat4(1.0f);


        // // model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(0.5f, 1.0f, 0.0f));
        // // angle =  (float)glfwGetTime();
        // angle = 0;
        // // std::cout <<"angle: " << angle << std::endl;
        // // model = glm::rotate(model,angle, glm::vec3(component_x, component_y, component_z));
        // model = glm::rotate(model,angle, glm::vec3(0.1, 0.1, 0.1));

        // std::cout << "component_x: " << component_x << std::endl;
        // std::cout << "component_y: " << component_y << std::endl;
        // std::cout << "component_z: " << component_z << std::endl;



        // view  = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
        // projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        // // retrieve the matrix uniform locations
        // unsigned int modelLoc = glGetUniformLocation(ourShader.ID, "model");
        // unsigned int viewLoc  = glGetUniformLocation(ourShader.ID, "view");
        // // pass them to the shaders (3 different ways)
        // glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        // glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &view[0][0]);
        // // note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
        // ourShader.setMat4("projection", projection);

        // // render box
        // glBindVertexArray(VAO);
        // glDrawArrays(GL_TRIANGLES, 0, 39);


        // activate shader
        ourShader.use();
        // create transformations
        glm::mat4 model         = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
        glm::mat4 view          = glm::mat4(1.0f);
        glm::mat4 projection    = glm::mat4(1.0f);
        angle  = (float)glfwGetTime();
        model = glm::rotate(model, glm::radians(-30.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        view  = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
        projection = glm::perspective(glm::radians(55.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        // retrieve the matrix uniform locations
        unsigned int modelLoc = glGetUniformLocation(ourShader.ID, "model");
        unsigned int viewLoc  = glGetUniformLocation(ourShader.ID, "view");
        // pass them to the shaders (3 different ways)
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &view[0][0]);
        // note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
        ourShader.setMat4("projection", projection);
        // render container
        glBindVertexArray(VAOs[0]);
        glDrawArrays(GL_TRIANGLES, 0, 72); 






        //render a pacaman
        ourShader2.use();
        glm::mat4 model2         = glm::mat4(1.0f);
        glm::mat4 view2          = glm::mat4(1.0f);
        glm::mat4 projection2    = glm::mat4(1.0f);

        // model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(0.5f, 1.0f, 0.0f));
        //angle =  (float)glfwGetTime();
        // std::cout <<"angle: " << angle << std::endl;
        model2 = glm::rotate(model2,glm::radians(-60.0f), glm::vec3(1.0f, 0.0f, 0.0f));


        // std::cout << "component_x: " << component_x << std::endl;
        // std::cout << "component_y: " << component_y << std::endl;
        // std::cout << "component_z: " << component_z << std::endl;

        std::cout << "translation_x: " << translation_x << std::endl;
        std::cout << "translation_y: " << translation_y << std::endl;
        std::cout << "translation_z: " << translation_z << std::endl;

        view2  = glm::translate(view2, glm::vec3(translation_x, translation_y, translation_z));
        //projection2 = glm::perspective(glm::radians(55.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        // retrieve the matrix uniform locations
        unsigned int modelLoc2 = glGetUniformLocation(ourShader2.ID, "model");
        unsigned int viewLoc2  = glGetUniformLocation(ourShader2.ID, "view");
        // pass them to the shaders (3 different ways)
        glUniformMatrix4fv(modelLoc2, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(viewLoc2, 1, GL_FALSE, &view2[0][0]);
        // note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
        ourShader2.setMat4("projection", projection);

        glBindVertexArray(VAOs[1]);
        glDrawArrays(GL_TRIANGLES,0,36);





        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(2, VAOs);
    glDeleteBuffers(2, VBOs);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}