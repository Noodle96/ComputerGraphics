#version 330 core
out vec4 FragColor;  
// uniform vec4 ourColor;

//b_add[1]
in vec3 ourColor;
in vec2 TexCoord;
// texture sampler
uniform sampler2D texture1;
//e_add[1]

void main()
{
    // FragColor = ourColor;
    //FragColor = vec4(1.0f, 0.0f, 0.0f, 1.0f); /// red colo
    //b_add[2]
    FragColor = texture(texture1, TexCoord);
    //e_add[2]
}