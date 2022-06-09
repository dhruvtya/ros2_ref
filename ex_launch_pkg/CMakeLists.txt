cmake_minimum_required(VERSION 3.8)
project(ex_launch_pkg)

# find dependencies
find_package(ament_cmake REQUIRED)

install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
