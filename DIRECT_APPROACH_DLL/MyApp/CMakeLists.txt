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

# (2) MAKE EXECUTABLE NAD INCLUDE DIRECTORIES
add_executable(${CMAKE_PROJECT_NAME} src/main.cpp)

target_include_directories(MyApp PRIVATE ${SRC_PATH})
target_include_directories(MyApp PRIVATE ${INCLUDE_PATH})
target_include_directories(MyApp PRIVATE ${LIBS_PATH})

# Specify the location of the DLL and associated import library
# Note: For linking, you usually link against a .lib (Windows) or .a (Linux) file, not directly against a .dll.
# Assume there is a corresponding .lib file in the libs directory.
set(LIBRARY_DIR ${CMAKE_SOURCE_DIR}/libs)

# LINK LIBRARY: 2 STEPS
# Add the directory containing the DLL's import library to the link directories
target_link_directories(MyApp PRIVATE ${LIBS_PATH})
# Link against the library (.lib, .dll.a)
target_link_libraries(MyApp PRIVATE ${LIBS_PATH}/libOperatorManagerWrapper.dll.a)
target_link_libraries(MyApp PRIVATE ${LIBS_PATH}/libOperatorManagerWrapper.dll)

# Approach to set a PATH ENV variable. I don't know if its really works
add_custom_command(TARGET MyApp POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E env "PATH=$ENV{PATH};${LIBS_PATH}"
    $<TARGET_FILE:MyApp>)

# Copy the .dll file to the output directory
#add_custom_command(TARGET MyApp POST_BUILD
#    COMMAND ${CMAKE_COMMAND} -E copy_if_different
#        "${LIBS_PATH}/libOperatorManagerWrapper.dll"
#        $<TARGET_FILE_DIR:MyApp>)

