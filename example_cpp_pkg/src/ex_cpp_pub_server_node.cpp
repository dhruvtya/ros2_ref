#include "example_cpp_pkg/ex_cpp_pub_server.hpp"

int main(int argc, char** argv){
    rclcpp::init(argc, argv);
    
    auto node = std::make_shared<ExampleNodeClass>();
    rclcpp::spin(node);

    rclcpp::shutdown();

    return 0;
}