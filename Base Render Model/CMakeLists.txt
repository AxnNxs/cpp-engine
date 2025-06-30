# CMakeList.txt : CMake project for Base Render Model, include source and define
# project specific logic here.
#

# Minimum required CMake version and project declaration
cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
project("BaseRenderModel" VERSION 1.0 LANGUAGES CXX) # Specify C++ as the language

# Set C++ Standard globally for the project
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)



#FetchContent
include(FetchContent)

# --- Download GLM ---
FetchContent_Declare(
	glm
	GIT_REPOSITORY	https://github.com/g-truc/glm.git
	GIT_TAG			1.0.1	# specific version
)
# --- Add GLM to project ---
FetchContent_MakeAvailable(glm)


# Add source to this project's executable.
add_executable (CMakeTarget "Base Render Model.cpp" "Base Render Model.hpp" "mylibraries/pixelManage.hpp" "mylibraries/pixelManage.cpp")

# --- Link GLM to this project ---
target_link_libraries(CMakeTarget PRIVATE glm)


# --- Set include directories for my own libraries ---
target_include_directories(CMakeTarget PRIVATE
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>	# For building the project
	$<INSTALL_INTERFACE:include>
    ${CMAKE_CURRENT_SOURCE_DIR}/mylibraries
	${glm_SOURCE_DIR}
)



# TODO: Add tests and install targets if needed.

