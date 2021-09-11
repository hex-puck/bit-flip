file(GLOB cxx_sources RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)

add_executable(main ${cxx_sources})
set_target_properties(
        main PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}
        RUNTIME_OUTPUT_NAME ${PROJECT_NAME}
)
