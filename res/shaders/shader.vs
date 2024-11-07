#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 iTexCoord;

uniform mat4 Projection;
uniform mat4 View;
uniform mat4 Model;

out vec2 oTexCoord;

void main(){
  gl_Position = Projection * Model * vec4(aPos, 1.0);
  oTexCoord = vec2(iTexCoord.x, 1-iTexCoord.y);
}

