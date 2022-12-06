cmake_minimum_required(VERSION 3.23)
project(RenderingEngine)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC on)
set(CMAKE_AUTOMUIC on)
set(CMAKE_AUTORCC on)

add_executable(RenderingEngine main.cpp Vector3.cpp Vector4.cpp Vector4.h Vector3.h Matrix4x4.cpp Matrix4x4.h win.cpp win.h win.ui MyDraw.h MyDraw.cpp)

find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)

target_link_libraries(RenderingEngine Qt::Core Qt::Gui Qt::Widgets)
