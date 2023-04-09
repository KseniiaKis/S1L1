file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_library(TTreeLib STATIC ${srcs} ${hdrs})