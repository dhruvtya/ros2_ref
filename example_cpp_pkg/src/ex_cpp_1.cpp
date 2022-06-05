#include "rclcpp/rclcpp.hpp"

int main(int argc, char **argv){
    rclcpp::init(argc, argv);

    auto node = std::make_shared<rclcpp::Node>("ex_cpp_1");
    RCLCPP_INFO(node->get_logger(), "Example ROS2 - C++ node 1");
    rclcpp::spin(node);

    rclcpp::shutdown();
    return 0;
}