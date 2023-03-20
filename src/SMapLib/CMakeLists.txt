file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_library(SMapLib STATIC ${srcs} ${hdrs})


