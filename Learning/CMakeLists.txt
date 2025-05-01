cmake_minimum_required(VERSION 3.18)

project(LearningLibrary)

add_library(LearningLibrary STATIC

    Optional.h
)

# Specify the include directories
target_include_directories(LearningLibrary PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
    
