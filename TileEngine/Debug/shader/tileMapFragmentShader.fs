#version 430 
in vec2 texCoordinate; // The input variable from the vertex shader (same name and same type)
flat in int draw;
  
uniform sampler2D myTexture;
  
out vec4 color;

void main()
{
	//if(draw == 0)
	//	discard;
			
	//vec4 textureColor = texture(myTexture, texCoordinate);
	//if( textureColor.a < 0.5){
	//	discard;
	//}
	
    //color = textureColor;
    color = vec4(1.0, 0.0, 0.0, 1.0);

} 