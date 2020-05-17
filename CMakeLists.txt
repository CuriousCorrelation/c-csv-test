CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

set(CMAKE_C_STANDARD 99)

project(c-csv-test)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(external/c-csv)

add_library(C-Csv-Test
  src/c-csv-test.c
)

target_include_directories(C-Csv-Test
  PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/include)

include_directories(c-csv ${CMAKE_CURRENT_LIST_DIR}/external/c-csv/include)

add_executable(${PROJECT_NAME} main.c)

target_link_libraries(
  ${PROJECT_NAME}
  C-Csv-Test
  c-csv
  )
