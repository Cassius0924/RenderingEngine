cmake_minimum_required(VERSION 3.23)
project(RenderingEngine)

set(CMAKE_CXX_STANDARD 14)

add_executable(RenderingEngine main.cpp Vector3.cpp Vector4.cpp Vector4.h Vector3.h Matrix4x4.cpp Matrix4x4.h)
