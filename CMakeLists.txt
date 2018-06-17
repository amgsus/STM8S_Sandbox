## This CMakeLists declares some C-preprocessor definitions and adds sources
## from a specified directory (non-recursive).

cmake_minimum_required(VERSION 3.10)
project(STM8S_Sandbox C)

set(CMAKE_C_STANDARD 99)

## Adds some definitions.

add_definitions(-DUSING_CLION)

add_definitions(-DSTM8S103F3_MCU)

## Specify the directory where sources are stored.

set(__PROJECT_DIR__ STVD_Project)

## Adds all C-sources and headers under the specified folder.

file(GLOB __SRC_FILES__ ${__PROJECT_DIR__}/*.c)
file(GLOB __HDR_FILES__ ${__PROJECT_DIR__}/*.h)
file(GLOB __INC_FILES__ ${__PROJECT_DIR__}/*.inc)

message("")
message("Project files to compile:")
foreach(filePath IN LISTS __SRC_FILES__)
    message("+ " ${filePath})
endforeach()

message("")
message("Project headers:")
foreach(filePath IN LISTS __HDR_FILES__)
    message("+ " ${filePath})
endforeach()

message("")
message("Project include-files:")
foreach(filePath IN LISTS __INC_FILES__)
    message("+ " ${filePath})
endforeach()

## You should reload CMake project manually everytime a new .c/.h file is put
## into the sources root.

include_directories(${__PROJECT_DIR__})
add_executable(STM8S_Sandbox
        CLionSandboxForTesting.c
        ${__SRC_FILES__} ${__HDR_FILES__})

message("")