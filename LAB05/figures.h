#ifndef FIGURES_H
#define FIGURES_H


float* getFirstTriangle(int &SIZEOF_L){
	float a = 0.1;
	static float firstTriangle[] = {
        //  0.5f, -0.5f, 0.0f,  // bottom right
        // -0.5f, -0.5f, 0.0f,  // bottom left
        //  0.0f,  0.5f, 0.0f   // top 
//      positions          colors                 textures coordenadas
        -10*a, 0*a, 0.0f,   1.0f, 0.0f, 0.0f,      -8*a, 1*a, //botton left
        0*a, 0*a, 0.0f,   0.0f, 1.0f, 0.0f,      -2*a, 1*a,  //bottom right
        -5*a, 10*a, 0.0f,   0.0f, 0.0f, 1.0f,      -5*a, 7*a, //top
    };
	SIZEOF_L = sizeof(firstTriangle);
	return firstTriangle;
}
// float* getFirstTriangle(int &SIZEOF_L){
// 	float a = 0.1;
// 	static float firstTriangle[] = {
//         //  0.5f, -0.5f, 0.0f,  // bottom right
//         // -0.5f, -0.5f, 0.0f,  // bottom left
//         //  0.0f,  0.5f, 0.0f   // top 
// //      positions          colors                 textures coordenadas
//         -10*a, 1*a, 0.0f,   1.0f, 0.0f, 0.0f,      -8*a, 1*a, //botton left
//         -0*a, 1*a, 0.0f,   0.0f, 1.0f, 0.0f,      -2*a, 1*a,  //bottom right
//         -5*a, 10*a, 0.0f,   0.0f, 0.0f, 1.0f,      -5*a, 7*a, //top
//     };
// 	SIZEOF_L = sizeof(firstTriangle);
// 	return firstTriangle;
// }

float* getSecondTriangle(int &SIZEOF_L){
	float a = 0.1;
	static float secondTriangle[] = {
    //  positions          colors                 textures coordenadas
        -3*a, -8*a, 0.0f,  1.0f, 0.0f, 0.0f,      -8*a, -8*a,  // bottom left
        3*a, -8*a, 0.0f,  0.0f, 1.0f, 0.0f,     -2*a, -8*a,// bottom right
        0*a, -1*a, 0.0f,  0.0f, 0.0f, 1.0f,     -5*a, -1*a,// top
    };
	SIZEOF_L = sizeof(secondTriangle);
	return secondTriangle;
}

float* getThirdTriangle(int &SIZEOF_L){
	float a = 0.1;
	static float thirdTriangle[] = {
    //  positions          colors                 textures coordenadas
        4*a, 2*a, 0.0f,    1.0f, 0.0f, 0.0f,      -8*a, 1*a, // bottom left
        8*a, 2*a, 0.0f,    0.0f, 1.0f, 0.0f,      -2*a, 1*a,// bottom right
        6*a, 6*a, 0.0f,    0.0f, 0.0f, 1.0f,      -5*a, 7*a, // top
    };
	SIZEOF_L = sizeof(thirdTriangle);
	return thirdTriangle;
}

// -8*a, -8*a, 
// 8*a, 2*a,
// 6*a, 6*a,



#endif // !FIGURES_H