project(SpellNumberProgram C)

include_directories(${CMAKE_SOURCE_DIR}/src/lib)

add_executable(spell-number-bin main.c)
add_dependencies(spell-number-bin spell-number)
target_link_libraries(spell-number-bin spell-number)

set_target_properties(spell-number-bin PROPERTIES OUTPUT_NAME spell-number)
