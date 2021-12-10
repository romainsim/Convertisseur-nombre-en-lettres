project(SpellNumberLibrary C)

add_library(
  spell-number SHARED
  decomposition/decomposition.c decomposition/decomposition.h decomposition/decomposition.inc
  french/date.c french/date.h
  french/french.c french/french.h
  roman/roman.c roman/roman.h roman/roman.inc
)

install(
  TARGETS spell-number
  LIBRARY DESTINATION lib/${CMAKE_BUILD_TYPE}
  ARCHIVE DESTINATION lib/${CMAKE_BUILD_TYPE}
  RUNTIME DESTINATION bin/${CMAKE_BUILD_TYPE}
)

install(
  FILES decomposition/decomposition.h french/date.h french/french.h roman/roman.h
  DESTINATION include
)
