#include "vertex_array.h"
#include "engine.h"


static float vertices[] = {
  0.5f,  0.5f, 0.0f,  // top right
  0.5f, -0.5f, 0.0f,  // bottom right
  -0.5f, -0.5f, 0.0f,  // bottom left
  -0.5f,  0.5f, 0.0f   // top left 
};
static unsigned int indices[] = {  // note that we start from 0!
  0, 1, 3,  // first Triangle
  1, 2, 3   // second Triangle
};
VertexArray::VertexArray(unsigned int Index)
  : Index(Index) {
  glGenVertexArrays(Index, &VAO);
  glBindVertexArray(VAO);
  VertexBuffer VB(vertices, sizeof(vertices));
  IndexBuffer IB(indices, 6);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);
  glBindVertexArray(0); 
}

void VertexArray::Bind(){
  glBindVertexArray(Index);
}

void VertexArray::Unbind(){
  glBindVertexArray(0);
}
