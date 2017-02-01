cmake_minimum_required (VERSION 3.5.2)
project (Merge-Sort)

set (Merge-Sort_VERSION_MAJOR 1)
set (Merge-Sort_VERSION_MINOR 0)


include_directories(include)

add_subdirectory(src)
enable_testing()
add_subdirectory(test)
add_subdirectory(lib)
