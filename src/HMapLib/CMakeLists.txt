file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_library(HMapLib STATIC ${srcs} ${hdrs})