cmake_minimum_required(VERSION 3.20) # Adjust version as needed
project(algo_design) # Replace 'algo_design' with your project name

# Set C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS True)

# Add the executable
add_executable(algo_design main.cpp)

# Optionally specify the include directory for headers
target_include_directories(algo_design PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

find_package(range-v3 REQUIRED)

target_link_libraries(${PROJECT_NAME} range-v3::range-v3)