file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_library(MapLib STATIC ${srcs} ${hdrs})

target_link_libraries(${target} ${LIBRARY_DEPS})
