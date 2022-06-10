cmake_minimum_required(VERSION 3.8)
project(ex_plugin_base_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(pluginlib REQUIRED)

install(
  DIRECTORY include/
  DESTINATION include
)

ament_export_include_directories(
  include
)

include_directories(include)
add_executable(ex_plugins_loader src/ex_plugins_loader.cpp)
ament_target_dependencies(ex_plugins_loader pluginlib)

install(
  TARGETS ex_plugins_loader
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
