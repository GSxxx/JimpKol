
project(socialgraph)

set(HEDEAR_FILES SocialGraph.h)
set(SOURCE_FILES SocialGraph.cpp)

add_library(libsocialgraph STATIC ${SOURCE_FILES})
target_include_directories(libsocialgraph PUBLIC .)

add_executable(socialgraph ${SOURCE_FILES} main.cpp)

target_link_libraries(socialgraph libsocialgraph)
