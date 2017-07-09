
project(map)

set(HEDEAR_FILES Map.h)
set(SOURCE_FILES Map.cpp)

add_library(libmap STATIC ${SOURCE_FILES})
target_include_directories(libmap PUBLIC .)

add_executable(map ${SOURCE_FILES} main.cpp)

target_link_libraries(map libmap)
