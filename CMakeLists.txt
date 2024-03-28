cmake_minimum_required(VERSION 3.10)
project(ASPE)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED)

find_package(Eigen3 REQUIRED)
find_package(GTest CONFIG REQUIRED)

enable_testing()

add_subdirectory(header_lib)
add_subdirectory(source_lib)
add_subdirectory(test)

add_executable(MAIN main.cpp)
add_executable(test-ut test-ut.cpp)

target_link_libraries(test-ut GTest::gtest)
target_link_libraries(MAIN Eigen3::Eigen)
target_link_libraries(MAIN elec_lib)

add_test(NAME ut_test COMMAND test-ut)

