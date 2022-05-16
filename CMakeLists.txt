cmake_minimum_required(VERSION 2.6)
file(TO_CMAKE_PATH "$ENV{IMAGINEPP_ROOT}/CMake" p)
list(APPEND CMAKE_MODULE_PATH "${p}") #For old Imagine++
list(APPEND CMAKE_SYSTEM_FRAMEWORK_PATH /Library/Frameworks) #Mac, why not auto?
find_package(Imagine REQUIRED)

project(intpainting)
add_executable(projet-intpainting main.cpp cord.cpp cord.h pixel_bord.cpp pixel_bord.h priorite.cpp priorite.h arthur.cpp arthur.h micka.cpp micka.h simon.cpp simon.h marius.cpp marius.h)
ImagineUseModules(projet-intpainting Graphics)
