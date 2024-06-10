message(STATUS "included core subdirectory")

# print compiler command
if(EZCC_BUILD_DEBUG MATCHES "on")
  set(CMAKE_VERBOSE_MAKEFILE TRUE)
endif()

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} EZCC_SRC)

if(EZCC_BUILD_DEBUG MATCHES "on")
  message(STATUS "${EZCC_SRC}")
endif()

add_executable(ezcc_driver ${EZCC_SRC})

target_link_libraries(ezcc_driver PUBLIC ezcc_global)
