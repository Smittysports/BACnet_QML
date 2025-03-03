cmake_minimum_required(VERSION 3.18)

project(MyBACnet VERSION 1.0 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the output directory for object files
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)

find_package(Qt6 6.2 COMPONENTS Quick Gui REQUIRED)

qt_add_executable(MyBACnet
    main.cpp
)

target_link_libraries(MyBACnet PRIVATE Qt6::Gui Qt6::Quick ThreadingLibrary)
add_subdirectory(Threading)

qt_add_qml_module(MyBACnet
    URI BACnetModule
    VERSION 1.0
    QML_FILES
        Main.qml
        FramedBACnetImage.qml
        BACnetObjectTypes.qml
        RightBar.qml
        Log.qml
        CommandResponse.qml
    RESOURCES
        img/BACnet.jpg
    SOURCES
        Networking.cpp
        Networking.h
        BACnetInterface.cpp
        BACnetInterface.h
        BACnetObjectTypes.cpp
        BACnetObjectTypes.h
    )
    
