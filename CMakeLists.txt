CMAKE_MINIMUM_REQUIRED(VERSION 4.3.0)

project("SAP")

find_package(PkgConfig REQUIRED)
pkg_check_modules(ASLA REQUIRED alsa)

add_executable(${PROJECT_NAME} src/main.c)

target_include_directories(${PROJECT_NAME} PRIVATE ${ASLA_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${ASLA_LIBRARIES})


