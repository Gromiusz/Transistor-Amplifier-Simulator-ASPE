add_library(elec_lib STATIC electronics_elements.cpp)
target_link_libraries(elec_lib Eigen3::Eigen)