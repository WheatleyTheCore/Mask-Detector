cmake_minimum_required(VERSION 3.10)

project(MaskDetector)

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )


file(GLOB source_files
	"src/*.cpp"
)

set(SOURCES ${source_files})

add_executable(MaskDetector ${SOURCES})
target_include_directories(MaskDetector PRIVATE "include")
target_link_libraries( MaskDetector ${OpenCV_LIBS} )
