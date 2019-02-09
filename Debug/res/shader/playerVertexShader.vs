#version 430 
layout (location = 0) in vec3 vertexPosition;
layout (location = 1) in vec2 texCoord;
   
out vec2 texCoordinate; 

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform int textureIndex;
uniform int tilesetNumberOfRows;
uniform int tilesetNumberOfColumns;

void main(){	
 	gl_Position = projection * model * vec4(vertexPosition.x, vertexPosition.y, vertexPosition.z , 1.0);
    
    float column  	 = mod(textureIndex-1, tilesetNumberOfColumns);
    float row     	 = (textureIndex-1) / tilesetNumberOfRows;
    vec2 offset 	 = vec2(column/tilesetNumberOfColumns, row/tilesetNumberOfRows);  
    texCoordinate	 = vec2( vec2(texCoord.x/tilesetNumberOfColumns, texCoord.y/tilesetNumberOfRows) + offset );
}