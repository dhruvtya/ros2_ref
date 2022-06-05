#include "example_cpp_pkg/ex_cpp_2.hpp"

// Constructor
ExampleNodeClass::ExampleNodeClass(): Node("ex_cpp_2_node"), timer_counter_(0){
    RCLCPP_INFO(this->get_logger(), "Example ROS2 - C++ node 2");
    timer_ = this->create_wall_timer(std::chrono::seconds(1), 
                                     std::bind(&ExampleNodeClass::exampleTimer, this));
}

void ExampleNodeClass::exampleTimer(){
    timer_counter_ += 1;
    RCLCPP_INFO(this->get_logger(), "Timed print - %d", timer_counter_);
}