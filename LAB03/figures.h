#ifndef FIGURES_H
#define FIGURES_H


float* getFirstTriangle(int &SIZEOF_L){
	float a = 0.1;
	static float firstTriangle[] = {
        //  0.5f, -0.5f, 0.0f,  // bottom right
        // -0.5f, -0.5f, 0.0f,  // bottom left
        //  0.0f,  0.5f, 0.0f   // top 
        -8*a, 1*a, 0.0f, //botton left
        -2*a, 1*a, 0.0f, //bottom right
        -5*a, 7*a, 0.0f //top
    };
	SIZEOF_L = sizeof(firstTriangle);
	return firstTriangle;
}


float* getSecondTriangle(int &SIZEOF_L){
	float a = 0.1;
	static float secondTriangle[] = {
        -8*a, -8*a, 0.0f, // bottom left
        -2*a, -8*a, 0.0f, // bottom right
        -5*a, -1*a, 0.0f // top
    };
	SIZEOF_L = sizeof(secondTriangle);
	return secondTriangle;
}

float* getThirdTriangle(int &SIZEOF_L){
	float a = 0.1;
	static float thirdTriangle[] = {
        4*a, 2*a, 0.0f, // bottom left
        8*a, 2*a, 0.0f, // bottom right
        6*a, 6*a, 0.0f // top
    };
	SIZEOF_L = sizeof(thirdTriangle);
	return thirdTriangle;
}




#endif // !FIGURES_H