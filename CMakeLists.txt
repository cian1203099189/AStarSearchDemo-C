cmake_minimum_required(VERSION 3.21)
project(Test)

set(CMAKE_CXX_STANDARD 14)




set(Draw D:\\ege20.08_all\\EGE20.08\\include)
set(DrawLink D:\\ege20.08_all\\EGE20.08\\lib\\vs2019\\x64)
include_directories(D:\\ege20.08_all\\EGE20.08\\include)
link_directories(${DrawLink})

link_libraries(graphics64.lib)

add_executable(Test main.cpp BFSFinder.cpp BFSFinder.h Node.cpp Node.h Finder.cpp Finder.h Help.h Help.cpp)




