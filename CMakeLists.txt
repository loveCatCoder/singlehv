cmake_minimum_required(VERSION 3.5.1)

# set the project name
project(singlehv)


set(CMAKE_BUILD_TYPE "Debug")


# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


file(GLOB_RECURSE SRC_DIR_LIST 
        "main.cpp" 
        "base/*.c" 
        "event/*.c"
        "cpputil/*.cpp"
        "ssl/*.c"
)

# add the executable
add_executable(${PROJECT_NAME} ${SRC_DIR_LIST})



include_directories(${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/base 
        ${CMAKE_CURRENT_SOURCE_DIR}/cpputil 
        ${CMAKE_CURRENT_SOURCE_DIR}/event 
        ${CMAKE_CURRENT_SOURCE_DIR}/ssl)


target_link_libraries(${PROJECT_NAME} pthread dl)

message(STATUS ${PROJECT_NAME})

