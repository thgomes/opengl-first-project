cmake_minimum_required(VERSION 3.10)
project(first_project)

# Defina a versão do C++ que você está usando (opcional)
set(CMAKE_CXX_STANDARD 11)

# Adicione o diretório include da GLFW
include_directories(${CMAKE_SOURCE_DIR}/libs/include)

# Adicione o diretório das bibliotecas GLFW
link_directories(${CMAKE_SOURCE_DIR}/libs/lib)

# Adicione o arquivo glad.c ao projeto
add_library(glad ${CMAKE_SOURCE_DIR}/glad.c)

# Adicione o seu arquivo .cpp principal aqui
add_executable(${PROJECT_NAME} main.cpp)

# Link com as bibliotecas GLFW, OpenGL e GLAD
target_link_libraries(${PROJECT_NAME} ${LIBRARIES} glad -lglfw3 -lGL -lX11 -lpthread -lXrandr -lXi -ldl)
