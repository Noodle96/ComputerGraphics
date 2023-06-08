#ifndef FIGURES_H
#define FIGURES_H


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

#endif // !FIGURES_H