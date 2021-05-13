cmake_minimum_required(VERSION 3.10)

project(MaskDetector)

file(GLOB source_files
	"src/*.cpp"
)

set(SOURCES ${source_files})

add_executable(MaskDetector ${SOURCES})
