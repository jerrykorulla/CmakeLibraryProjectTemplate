cmake_minimum_required(VERSION 3.15)
project(MathLibrary VERSION 1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set output directories for different types of binary files
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/dist/bin)    # For .dll or .exe
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/dist/lib)    # For .so or .dylib
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/dist/lib)    # For .lib or .a

# Create the library
add_library(MathLibrary SHARED
    src/Calculator.cpp
)

# Include path for public headers
target_include_directories(MathLibrary
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

# Define symbol for exporting the DLL
target_compile_definitions(MathLibrary PRIVATE MATHLIBRARY_EXPORTS)

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}/dist" CACHE PATH "Install path" FORCE)
endif()

# Install targets to relative paths (they'll go under --prefix)
install(TARGETS MathLibrary
    RUNTIME DESTINATION bin     # .dll (Windows)
    ARCHIVE DESTINATION lib     # .lib
    LIBRARY DESTINATION lib     # .so/.dylib
)

# Install headers to include/
install(DIRECTORY include/ DESTINATION include)

