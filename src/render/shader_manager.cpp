#include "shader_manager.h"

ShaderManager::ShaderManager()
{

}

ShaderSource ShaderManager::LoadShadersFromFiles(std::string VertexShaderFilePath, std::string FragmentShaderFilePath){
  ShaderSource CurrentShader;

  std::ifstream VertexShader(VertexShaderFilePath);
  if(!VertexShader.is_open()){
    std::cout << "Vertex Shader failed to open file" << std::endl;
  }

  std::ifstream FragmentShader(FragmentShaderFilePath);
  if(!FragmentShader.is_open()){
    std::cout << "Fragment Shader failed to open file" << std::endl;
  } 

  std::stringstream VertexShaderStream;
  VertexShaderStream << VertexShader.rdbuf();
  CurrentShader.VertexShader = VertexShaderStream.str();
  
  VertexShader.close();

  std::stringstream FragmentShaderStream;
  FragmentShaderStream << FragmentShader.rdbuf();
  CurrentShader.FragmentShader = FragmentShaderStream.str();

  FragmentShader.close();

  return CurrentShader;
}

void ShaderManager::CreateShader()
{
  ShaderSource ShaderFiles = LoadShadersFromFiles("W:/2Dengine/res/shaders/shader.vs", "W:/2Dengine/res/shaders/shader.fs"); //Change this from absolute paths

  unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);

  const char* VertexShaderPointer = ShaderFiles.VertexShader.c_str();
  glShaderSource(vertexShader, 1, &VertexShaderPointer, NULL);
  glCompileShader(vertexShader);

  GetShaderLog(vertexShader, "VERTEX");

  unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

  const char* FragmentShaderPointer = ShaderFiles.FragmentShader.c_str();
  glShaderSource(fragmentShader, 1, &FragmentShaderPointer, NULL);
  glCompileShader(fragmentShader);

  GetShaderLog(fragmentShader, "FRAGMENT");

  ShaderProgram = glCreateProgram();
  glAttachShader(ShaderProgram, vertexShader);
  glAttachShader(ShaderProgram, fragmentShader);
  glLinkProgram(ShaderProgram);

  GetShaderLog(ShaderProgram,"LINKING_FAILED");

  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);
}

void ShaderManager::UseShader(){
  glUseProgram(ShaderProgram);
}

void ShaderManager::GetShaderLog(unsigned int Shader, std::string ShaderType)
{
  int success;
  char infoLog[512];
  glGetShaderiv(Shader, GL_COMPILE_STATUS, &success);
  if (!success)
  {
    glGetShaderInfoLog(Shader, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::" << ShaderType << "::COMPILATION_FAILED\n" << infoLog << std::endl;
  }
}
