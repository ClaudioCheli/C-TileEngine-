#version 330 core
layout (location = 0) in vec3 vertexPosition; // The position variable has attribute position 0
layout (location = 1) in vec2 texCoord;
   
out vec2 texCoordinate; 

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform int textureIndex;
uniform int tilesetNumberOfRows;
uniform int tilesetNumberOfColumns;

void main(){	
 	gl_Position = projection * view * model * vec4(vertexPosition.x, vertexPosition.y, vertexPosition.z-10.0f, 1.0);
    
    float column  	 = mod(textureIndex-1, tilesetNumberOfColumns);
    float row     	 = (textureIndex-1) / tilesetNumberOfRows;
    vec2 offset 	 = vec2(column/tilesetNumberOfColumns, row/tilesetNumberOfRows);  
    texCoordinate	 = vec2( vec2(texCoord.x/tilesetNumberOfColumns, texCoord.y/tilesetNumberOfRows) + offset );
}