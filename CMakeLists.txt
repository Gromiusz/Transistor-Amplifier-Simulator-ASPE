cmake_minimum_required(VERSION 3.10)
project(ASPE)

add_executable(MAIN main.cpp)
find_package(Eigen3 REQUIRED)

target_link_libraries(MAIN Eigen3::Eigen)

add_subdirectory(header_lib)
add_subdirectory(source_lib)


target_link_libraries(MAIN elec_lib)
