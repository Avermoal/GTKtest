cmake_minimum_required(VERSION 4.1.0 FATAL_ERROR)

set(PROJECT_NAME GTKtest)

project(${PROJECT_NAME})

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED IMPORTED_TARGET gtk4)
pkg_check_modules(OPENGL REQUIRED IMPORTED_TARGET gl)

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

target_include_directories(${PROJECT_NAME} PRIVATE ${GTK4_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIRS})
target_link_directories(${PROJECT_NAME} PRIVATE ${GTK4_LIBRARY_DIRS})
target_link_libraries(${PROJECT_NAME} ${GTK4_LIBRARIES} ${OPENGL_LIBRARIES})

target_compile_options(${PROJECT_NAME} PRIVATE ${GTK4_CFLAGS_OTHER})
