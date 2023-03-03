file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_library(StackLib STATIC ${srcs} ${hdrs})

target_link_libraries(${target} ${LIBRARY_DEPS})