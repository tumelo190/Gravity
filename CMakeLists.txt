cmake_minimum_required(VERSION 3.21)
project(Gravity)

include(FetchContent)
FetchContent_Declare(geode URL https://github.com/geode-sdk/geode/releases/download/v0.7.2/geode-sdk.zip)
FetchContent_MakeAvailable(geode)

file(GLOB_RECURSE SOURCES
	src/*.cpp
)

add_library(${PROJECT_NAME} SHARED ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE include)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

setup_geode_mod(${PROJECT_NAME})