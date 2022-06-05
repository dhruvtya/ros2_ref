cmake_minimum_required(VERSION 3.8)
project(example_cpp_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

# Example C++ Node 1
add_executable(ex_cpp_1 src/ex_cpp_1.cpp)
ament_target_dependencies(ex_cpp_1 rclcpp)

# Example C++ Node 2
include_directories(include)
add_executable(ex_cpp_2_node src/ex_cpp_2_node.cpp src/ex_cpp_2.cpp)
ament_target_dependencies(ex_cpp_2_node rclcpp)

install(TARGETS
  ex_cpp_1
  ex_cpp_2_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
