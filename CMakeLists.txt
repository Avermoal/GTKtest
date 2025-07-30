cmake_minimum_required(VERSION 4.1.0 FATAL_ERROR)

set(PROJECT_NAME GTKtest)

project(${PROJECT_NAME})

set(MESON_SOURCE_DIR "external/gtk")
set(MESON_BUILD_DIR "${CMAKE_BINARY_DIR}/gtk")

execute_process(
  COMMAND meson setup ${MESON_BUILD_DIR}
  WORKING_DIRECTORY ${MESON_SOURCE_DIR}
)

execute_process(
  COMMAND ninja
  WORKING_DIRECTORY ${MESON_BUILD_DIR}
)

include_directories("${MESON_BUILD_DIR}/include")
find_library(GTK gtk HINTS "${MESON_BUILD_DIR}")

set(PROJECT_INCLUDES
  includes/test.h
)

set(PROJECT_SRC
  src/main.c
)

add_executable(${PROJECT_NAME}
  ${PROJECT_INCLUDES}
  ${PROJECT_SRC}
)

target_link_libraries(${PROJECT_NAME} PRIVATE ${GTK})
