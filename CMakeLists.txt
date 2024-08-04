cmake_minimum_required(VERSION 3.10)

# Set the project name
project(ADVANCEIMAGEPROCESSING VERSION 1.0 LANGUAGES CXX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# List the source files
set(SOURCES
    main.cpp)

# Set the Qt installation directory
set(CMAKE_PREFIX_PATH "C:/Qt/6.7.0/mingw_64")

# Find QT package
find_package(Qt6 COMPONENTS Widgets REQUIRED)

# Add the executable target
add_executable(ADVANCEIMAGEPROCESSING ${SOURCES})

# Include the directory with the header files
target_include_directories(ADVANCEIMAGEPROCESSING PRIVATE ${PROJECT_SOURCE_DIR})

# Find Qt libraries
target_link_libraries(ADVANCEIMAGEPROCESSING PRIVATE Qt6::Widgets)
