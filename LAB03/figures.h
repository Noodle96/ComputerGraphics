#ifndef FIGURES_H
#define FIGURES_H


float* getFirstTriangle(int &SIZEOF_L){
	float a = 0.1;
	static float firstTriangle[] = {
        //  0.5f, -0.5f, 0.0f,  // bottom right
        // -0.5f, -0.5f, 0.0f,  // bottom left
        //  0.0f,  0.5f, 0.0f   // top 
        0.0f, -4*a, 0.0f, //botton right
        -8*a, -4*a, 0.0f, //bottom left
        -4*a, 4*a, 0.0f //top
    };
	SIZEOF_L = sizeof(firstTriangle);
	return firstTriangle;
}


float* getSecondTriangle(int &SIZEOF_L){
	float a = 0.1;
	static float secondTriangle[] = {
        4*a, -4*a, 0.0f, // bottom
        8*a, 4*a, 0.0f, // top right
        0.0f, 4*a, 0.0f // top left
    };
	SIZEOF_L = sizeof(secondTriangle);
	return secondTriangle;
}



#endif // !FIGURES_H