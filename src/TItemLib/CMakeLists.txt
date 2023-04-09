file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_library(ItemLib STATIC ${srcs} ${hdrs})