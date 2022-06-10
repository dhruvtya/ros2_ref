cmake_minimum_required(VERSION 3.8)
project(ex_plugins_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(ament_cmake_ros REQUIRED)
find_package(pluginlib REQUIRED)
find_package(ex_plugin_base_pkg REQUIRED)

add_library(example_plugins src/plugins/ex_plugin_1.cpp src/plugins/ex_plugin_2.cpp)
target_include_directories(example_plugins PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
ament_target_dependencies(
  example_plugins
  ex_plugin_base_pkg
  pluginlib
)

pluginlib_export_plugin_description_file(ex_plugin_base_pkg plugins.xml)

install(
  DIRECTORY include/
  DESTINATION include
)
install(
  TARGETS example_plugins
  EXPORT export_${PROJECT_NAME}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

ament_export_include_directories(
  include
)
ament_export_libraries(
  example_plugins
)
ament_export_targets(
  export_${PROJECT_NAME}
)

ament_package()
