# OpenGL Graph Algorithms Visualizer
This repository is for developing a visual demonstration of graph algorithms such as BFS, DFS, Path Finding Algorithms, etc., on a 2D grid for the ease of understanding.  
It is my first attempt at using OpenGL for a project so this also serves for my understanding of graphics application development.  

It makes use of the following libraries in order to utilise OpenGL:
- GLEW 2.1.0
- GLM 0.9.9.8
- GLFW 3.3.4

The static library files and header files have been consolidated into the ```external``` folder and can be used from there.

## Build Instructions
The build procedure follows the simple cmake-build-install process.

cd into the project directory containing the top level CMakeLists.txt file.  
Then run  

```
mkdir build && cd build
cmake .. -G "MinGW Makefiles" -DCMAKE_INSTALL_PREFIX=./install/
cmake --build .
cmake --install .
```
You can change the install directory by modifying CMAKE_INSTALL_PREFIX above.