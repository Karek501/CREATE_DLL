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

# (3) LINK EXE TO LIB
target_link_libraries(MyApp ${CMAKE_SOURCE_DIR}/OperatorManagerWrapper.dll)

