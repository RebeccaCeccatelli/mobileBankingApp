cmake_minimum_required(VERSION 3.17)
project(mobile_banking_app)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(project_files)
#add_subdirectory(test)

add_executable(mobile_banking_app main.cpp)

target_link_libraries(mobile_banking_app core)