set(target ${Polynom_LIBRARY})

include_directories(MapLib)
include_directories(SMapLib)
include_directories(StackLib)

target_link_libraries(${target} ${LIBRARY_DEPS})

add_subdirectory(MapLib)
add_subdirectory(SMapLib)
add_subdirectory(StackLib)

