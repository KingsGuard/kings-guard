# CMakeList.txt : CMake project for King's Guard (Linux), include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)
project(KingsGuard)

# Add source to this project's executable.
add_executable (KingsGuard GameLoop.cpp Gameplay.cpp Tutorial.cpp Main.cpp)

# TODO: Add tests and install targets if needed.
