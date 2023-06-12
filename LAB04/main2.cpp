#include <iostream>
#include <cmath>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/vec3.hpp> //
#include <glm/glm.hpp>  //
// #include "shaderprog.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>

#include <vector>
#include "shader.h"
using namespace std;

std::vector<glm::vec3> vertices;
std::vector<unsigned int> indices;


void buildCircle(float radius, int vCount)
{
    float angle = 360.0f / vCount;

    int triangleCount = vCount - 2;

    std::vector<glm::vec3> temp;
    // positions
    for (int i = 0; i < vCount; i++)
    {
        float currentAngle = angle * i;
        float x = radius * cos(glm::radians(currentAngle));
        float y = radius * sin(glm::radians(currentAngle));
        float z = 0.0f;

        vertices.push_back(glm::vec3(x, y, z));
    }

    // push indexes of each triangle points
    for (int i = 0; i < triangleCount; i++)
    {
        indices.push_back(0);
        indices.push_back(i + 1);
        indices.push_back(i + 2);
    }
}

int main(int argc, char **argv)
{
    // initialize GLFW
    if (!glfwInit())
    {
        return -1;
    }

    // create a window pointer
    GLFWwindow *window = glfwCreateWindow(800, 600, "Hello Circle", NULL, NULL);
    // error check
    if (window == NULL)
    {
        cout << "Error. I could not create a window at all!" << endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        cout << "Failed to initialize GLAD" << endl;
        return -1;
    }

    buildCircle(.7, 8);
	for(int e = 0 ; e < vertices.size(); e++){
		std::cout << glm::to_string(vertices[e]) << endl;
	}

    Shader ourShader("1.0.shader.vs", "1.0.shader.fs");

    // attachment of shaders to program object
    // myProgram.attach("./shaders/vs.glsl", GL_VERTEX_SHADER);
    // myProgram.attach("./shaders/fs.glsl", GL_FRAGMENT_SHADER);
    // myProgram.link();

    // buffer
	// object id variables
	unsigned int vertexBuffer;
	unsigned int vertexArray;
	unsigned int EBO;
    glGenVertexArrays(1, &vertexArray);
    glGenBuffers(1, &vertexBuffer);

    // element buffer object
    glGenBuffers(1, &EBO);

    glBindVertexArray(vertexArray);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);

    // copying
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * vertices.size(), &vertices[0], GL_STATIC_DRAW); // asd
	// with 8 rectangles
	// cout << sizeof(glm::vec3) << endl; // 12
	// cout << vertices.size() << endl; // 8
	// cout << sizeof(glm::vec3) * vertices.size() << endl; // 96
	cout << "printing ... " << endl;
	cout << &vertices[0] << endl;
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);

    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indices.size(), &indices[0], GL_STATIC_DRAW); // asd
    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.0f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        ourShader.use();

        glBindVertexArray(vertexArray);

        glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0); // asd

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}