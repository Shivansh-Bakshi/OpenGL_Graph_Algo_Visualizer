cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(Graph_Algo_Visualizer VERSION 1.0)

find_package(OpenGL REQUIRED)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


if( CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR )
    message( FATAL_ERROR "Please select another Build Directory !)" )
endif()
if( CMAKE_SOURCE_DIR MATCHES " " )
	message( "Your Source Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()
if( CMAKE_BINARY_DIR MATCHES " " )
	message( "Your Build Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()

include_directories(
	${CMAKE_SOURCE_DIR}/external/include/
)

link_directories(
	${CMAKE_SOURCE_DIR}/external/lib/
)

set(GL_LIBS
        -lglew32 
		-lglfw3
)

set(OPENGL_LIBS
	${OPENGL_LIBRARY}
)

# add src subdirectory
add_subdirectory(src)

install(TARGETS visualizer DESTINATION bin)
install(FILES "${CMAKE_SOURCE_DIR}/external/bin/glew32.dll" DESTINATION bin)
install(FILES "${CMAKE_SOURCE_DIR}/external/lib/glfw3.dll" DESTINATION bin)
