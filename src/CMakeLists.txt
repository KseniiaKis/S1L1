set(target ${Polynom_LIBRARY})

include_directories(MapLib)
include_directories(SMapLib)
include_directories(StackLib)

add_subdirectory(MapLib)
add_subdirectory(SMapLib)
add_subdirectory(StackLib)