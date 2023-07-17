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
    float a = 0.5;
    float vertices[] = {
        //positions         //colors
        //face botton       //red
        -a, -a, -a,         1.0f, 0.0f, 0.0f,
        a, -a, -a,          1.0f, 0.0f, 0.0f,
        a, a, -a,           1.0f, 0.0f, 0.0f,
        a, a, -a,           1.0f, 0.0f, 0.0f,
        -a, a, -a,          1.0f, 0.0f, 0.0f,
        -a, -a, -a,         1.0f, 0.0f, 0.0f,

        //first face       //green
        a, -a,  -a,        0.0f, 1.0f, 0.0f,
        0, 0,  2*a,        0.0f, 1.0f, 0.0f,
        a, a, -a,          0.0f, 1.0f, 0.0f,

        //second face     //blue
        -a,  -a,  -a,     0.0f, 0.0f, 1.0f,
        0,  0, 2*a,       0.0f, 0.0f, 1.0f,
        a, -a, -a,        0.0f, 0.0f, 1.0f,

        //third face      //yellow
        a,  a,  -a,       1.0f, 1.0f, 0.0f,
        -a,  a, -a,       1.0f, 1.0f, 0.0f,
        0, 0, 2*a,        1.0f, 1.0f, 0.0f,

        //four face         //purple
        -a, a, -a,        0.5f, 0.0f, 0.5f,
        -a, -a, -a,       0.5f, 0.0f, 0.5f,
        0, 0,  2*a,       0.5f, 0.0f, 0.5f,

    };
    
    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

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

        // activate shader
        ourShader.use();

        // create transformations
        // make sure to initialize matrix to identity matrix first
        glm::mat4 model         = glm::mat4(1.0f);
        glm::mat4 view          = glm::mat4(1.0f);
        glm::mat4 projection    = glm::mat4(1.0f);


        // model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(0.5f, 1.0f, 0.0f));
        angle =  (float)glfwGetTime();
        // std::cout <<"angle: " << angle << std::endl;
        model = glm::rotate(model,angle, glm::vec3(component_x, component_y, component_z));
        std::cout << "component_x: " << component_x << std::endl;
        std::cout << "component_y: " << component_y << std::endl;
        std::cout << "component_z: " << component_z << std::endl;



        view  = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
        projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        // retrieve the matrix uniform locations
        unsigned int modelLoc = glGetUniformLocation(ourShader.ID, "model");
        unsigned int viewLoc  = glGetUniformLocation(ourShader.ID, "view");
        // pass them to the shaders (3 different ways)
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &view[0][0]);
        // note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
        ourShader.setMat4("projection", projection);

        // render box
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 36);


        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}