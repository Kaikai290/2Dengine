#version 330 core

out vec4 FragColour;

uniform vec4 Colour;

void main()
{
  FragColour = Colour;
}
