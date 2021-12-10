cmake_minimum_required(VERSION 3.0)

project(SpellNumber C)

set(CMAKE_C_FLAGS "-O3 -Wall -Wextra -pedantic -Wmissing-prototypes -Wstrict-prototypes -Wold-style-definition -lm")
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

enable_testing()

add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(docs)
