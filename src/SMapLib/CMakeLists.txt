file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_library(SMapLib STATIC ${srcs} ${hdrs})

target_link_libraries(${target} ${LIBRARY_DEPS})
