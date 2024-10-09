cmake_minimum_required(VERSION 3.22.1)
project(des
  VERSION 0.0.1
  DESCRIPTION "DES encryption algorithm"
  LANGUAGES CXX)

add_executable(${PROJECT_NAME} main.cpp
  des.cpp
  utility.cpp
  args.cpp
)
