set(EXECUTABLE_NAME visualizer)

add_executable(${EXECUTABLE_NAME} main.cpp)

target_link_libraries(${EXECUTABLE_NAME} ${GL_LIBS} ${OPENGL_LIBS})