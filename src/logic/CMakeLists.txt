file(GLOB c_headers RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
file(GLOB cxx_sources RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)

add_library(logical ${c_headers} ${cxx_sources})
