cmake_minimum_required(VERSION 3.10)
project(saliency)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O3")

add_executable(${PROJECT_NAME}  src/SaliencyDetector.cpp src/ImageLoader.cpp src/SymmetricSurroundSaliency.cpp)


add_definitions( -DMAGICKCORE_QUANTUM_DEPTH=16 )
add_definitions( -DMAGICKCORE_HDRI_ENABLE=0 )
find_package(ImageMagick REQUIRED COMPONENTS MagickCore Magick++)


include_directories(${ImageMagick_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${ImageMagick_LIBRARIES})

message("${ImageMagick_INCLUDE_DIRS}")
message("${ImageMagick_LIBRARIES}")