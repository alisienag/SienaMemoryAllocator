cmake_minimum_required(VERSION 3.30)

project(SienaMemoryManager)

if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release)
endif()

file (GLOB src_files
	"*.h"
	"*.c"
)

add_executable(SienaMemoryManager ${src_files})
