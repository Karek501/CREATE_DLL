cmake_minimum_required(VERSION 3.10)

project(MyApp)

set(CMAKE_PROJECT_NAME "MyApp")

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(DCMAKE_BUILD_TYPE "Release")

# (1) ADD SUBDIRECTORIES
add_subdirectory(src)
set(SRC_PATH "${CMAKE_CURRENT_SOURCE_DIR}/src" CACHE INTERNAL "")

add_subdirectory(include)
set(INCLUDE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/include" CACHE INTERNAL "")

add_subdirectory(libs)
set(LIBS_PATH "${CMAKE_CURRENT_SOURCE_DIR}/libs" CACHE INTERNAL "")

add_subdirectory(bin)
set(BIN_PATH "${CMAKE_CURRENT_SOURCE_DIR}/bin" CACHE INTERNAL "")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_PATH})


# (2) MAKE EXECUTABLE
add_executable(${CMAKE_PROJECT_NAME} src/main.cpp)

# Specify the location of the DLL and associated import library
# Note: For linking, you usually link against a .lib (Windows) or .a (Linux) file, not directly against a .dll.
# Assume there is a corresponding .lib file in the libs directory.
set(LIBRARY_DIR ${CMAKE_SOURCE_DIR}/libs)

# Add the directory containing the DLL's import library to the link directories
target_include_directories(MyApp PRIVATE ${LIBRARY_DIR})
target_link_directories(MyApp PRIVATE ${LIBRARY_DIR})

# Link against the library (replace 'mylibrary' with the actual library name without the .lib extension)
target_link_libraries(MyApp PRIVATE ${LIBRARY_DIR}/libOperatorManagerWrapper.dll.a)
