
#include "utilities.h"
#include "shader.h"
#include "figures.h"

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main(){
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
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Laboratorio 03", NULL, NULL);
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

    // build and compile our shader program
    // you can name your shader files however you like

    Shader ourShader("1.0.shader.vs", "1.0.shader.fs");
    Shader ourShader2("2.0.shader.vs", "2.0.shader.fs");
    Shader ourShader3("3.0.shader.vs", "3.0.shader.fs");

    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    int SIZEOF_L_FIRST_TRIANGLE;
    int SIZEOF_L_SECOND_TRIANGLE;
    int SIZEOF_L_THIRD_TRIANGLE;

    float* firstTriangle = getFirstTriangle(SIZEOF_L_FIRST_TRIANGLE);
    float *secondTriangle = getSecondTriangle(SIZEOF_L_SECOND_TRIANGLE);
    float *thirdTriangle = getThirdTriangle(SIZEOF_L_THIRD_TRIANGLE);

    

    unsigned int VBOs[3], VAOs[3];
    glGenVertexArrays(3, VAOs); // we can also generate multiple VAOs or buffers at the same time
    glGenBuffers(3, VBOs);

    //first Triangle
    glBindVertexArray(VAOs[0]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
    glBufferData(GL_ARRAY_BUFFER, SIZEOF_L_FIRST_TRIANGLE, firstTriangle, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);	// Vertex attributes stay the same
    glEnableVertexAttribArray(0);

    //second triangle
    glBindVertexArray(VAOs[1]);	// note that we bind to a different VAO now
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);	// and a different VBO
    glBufferData(GL_ARRAY_BUFFER, SIZEOF_L_SECOND_TRIANGLE, secondTriangle, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0); // because the vertex data is tightly packed we can also specify 0 as the vertex attribute's stride to let OpenGL figure it out
    glEnableVertexAttribArray(0);

    //third triangle
    glBindVertexArray(VAOs[2]);	// note that we bind to a different VAO now
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[2]);	// and a different VBO
    glBufferData(GL_ARRAY_BUFFER, SIZEOF_L_THIRD_TRIANGLE, thirdTriangle, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0); // because the vertex data is tightly packed we can also specify 0 as the vertex attribute's stride to let OpenGL figure it out
    glEnableVertexAttribArray(0);

    // render loop
    // -----------
    float scaleFactor = 0.5;
    bool subida = true;
    int k = 0;

    float transationFactor = 0.1;
    bool topeDerecha = true;
    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        processInput(window);

        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // be sure to activate the shader before any calls to glUniform
        /*
        glUseProgram(shaderProgram);
        */

        // create transformations



        glm::mat4 transform = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
        glm::mat4 transform2 = glm::mat4(1.0f);
        glm::mat4 transform3 = glm::mat4(1.0f);
        //std::cout << glm::to_string(transform) << std::endl;
        //transform = glm::rotate(transform, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));


        //LOGICA DE LA SCALA
        if(subida){
            scaleFactor += 0.005;
            if(scaleFactor >= 1.25) subida = false;
        }else{
            scaleFactor-= 0.005;
            if(scaleFactor <= 0.5) subida = true;
        }


        //LOGICA DELA TRANSLACION
        if(topeDerecha){
            transationFactor += 0.005;
            if(transationFactor >= 1.2) topeDerecha=false;
        }else{
            transationFactor -= 0.005;
            if(transationFactor <= -0.2) topeDerecha = true;
        }
        // std::cout <<traslationFactor << std::endl;
        
        
        transform = glm::scale(transform, glm::vec3(scaleFactor, scaleFactor, scaleFactor));
        transform2 = glm::translate(transform2, glm::vec3(transationFactor, 0, 0));
        // transform2 = glm::translate(transform2, glm::vec3(1.0f, 1.0f, 0.0f));
        
        //transform = glm::rotate(transform, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));


        // if(k <=200){
        //     std::cout << glm::to_string(transform) << std::endl;
        //     k++;    
        // }

        //FIRST TRIANGLE
        ourShader.use();
        glBindVertexArray(VAOs[0]);
        // update shader uniform
        //double  timeValue = glfwGetTime();
        //std::cout << "timeValue: " << timeValue << std::endl;
        // float greenValue = static_cast<float>(sin(timeValue) / 2.0 + 0.5);
        //float greenValue = static_cast<float>(fabs(sin(1.2*timeValue)));
        //std::cout << "greenValue: " << greenValue << std::endl;


        //int vertexColorLocation = glGetUniformLocation(ourShader.ID, "ourColor");
        // ourShader.changeOurColor(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
        // // glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);

        unsigned int transformLoc = glGetUniformLocation(ourShader.ID, "transform");
        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
        // render the triangle
        glDrawArrays(GL_TRIANGLES, 0, 3);

        //SECOND TRIANGLE
        // transform2 = glm::scale(transform2, glm::vec3(1.75-scaleFactor, 1.75-scaleFactor, 1.75-scaleFactor));
        ourShader2.use();
        glBindVertexArray(VAOs[1]);
        // float redValue = static_cast<float>(fabs(sin(1.2*timeValue)));
        // vertexColorLocation = glGetUniformLocation(ourShader2.ID, "ourColor");
        // ourShader2.changeOurColor(vertexColorLocation, (1.0-redValue), 0.0f, 0.0f, 1.0f);

        unsigned int transformLoc2 = glGetUniformLocation(ourShader2.ID, "transform2");
        glUniformMatrix4fv(transformLoc2, 1, GL_FALSE, glm::value_ptr(transform2));
        glDrawArrays(GL_TRIANGLES, 0, 3);



        //THIRD TRIANGLE
        ourShader3.use();
        glBindVertexArray(VAOs[2]);
        glDrawArrays(GL_TRIANGLES, 0, 3);



        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    /*
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    */
    glDeleteVertexArrays(3, VAOs);
    glDeleteBuffers(3, VBOs);

    //glDeleteProgram(shaderProgram);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}