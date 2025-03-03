cmake_minimum_required(VERSION 3.18)

project(ThreadingLibrary)

add_library(ThreadingLibrary STATIC
    ThreadPool.cpp
    Subscriber.h
    SubscriptionManager.h
    ThreadPool.h
    ThreadSafeQueue.h
)

# Specify the include directories
target_include_directories(ThreadingLibrary PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
    
