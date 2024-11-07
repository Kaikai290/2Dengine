#version 330 core

out vec4 FragColour;

in vec2 oTexCoord;

uniform vec4 Colour;
uniform sampler2D ID;

void main()
{
  vec4 Tex = texture(ID, oTexCoord);
  FragColour = Tex;
}
