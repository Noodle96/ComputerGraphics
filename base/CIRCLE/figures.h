#ifndef FIGURES_H
#define FIGURES_H

 #include<vector> 


float* getFirstTriangle(int &SIZEOF_L){
	float a = 0.1;
	static float firstTriangle[] = {
        //  0.5f, -0.5f, 0.0f,  // bottom right
        // -0.5f, -0.5f, 0.0f,  // bottom left
        //  0.0f,  0.5f, 0.0f   // top 
        0.0f, 0.0f, 0.0f, //botton left
        8*a, 0.0, 0.0f, //bottom right
        8*a, 8*a, 0.0f //top
    };
	SIZEOF_L = sizeof(firstTriangle);
	return firstTriangle;
}

void buildCircle(float radius, int vCount,std::vector<glm::vec3> &vertices, std::vector<unsigned int> &indices){
    // std::vector<glm::vec3> vertices;
    // std::vector<unsigned int> indices;

    float angle = 360.0f / vCount;
    int triangleCount = vCount - 2;

    std::vector<glm::vec3> temp;
    // positions
    for (int i = 0; i < vCount; i++){
        float currentAngle = angle * i;
        float x = radius * cos(glm::radians(currentAngle));
        float y = radius * sin(glm::radians(currentAngle));
        float z = 0.0f;

        vertices.push_back(glm::vec3(x, y, z));
    }

    // push indexes of each triangle points
    for (int i = 0; i < triangleCount; i++){
        indices.push_back(0);
        indices.push_back(i + 1);
        indices.push_back(i + 2);
    }
}

#endif // !FIGURES_H