file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_library(MapLib STATIC ${srcs} ${hdrs})