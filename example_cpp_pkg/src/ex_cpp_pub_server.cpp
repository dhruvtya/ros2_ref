#include "example_cpp_pkg/ex_cpp_pub_server.hpp"

// Constructor
ExampleNodeClass::ExampleNodeClass(): Node("ex_cpp_pub_server_node"), timer_counter_(0){
    setupCommunications();

    RCLCPP_INFO(this->get_logger(), "Example ROS2 - C++ publisher & server node");
    timer_ = this->create_wall_timer(std::chrono::seconds(5), 
                                     std::bind(&ExampleNodeClass::examplePublishFunction, this));
}

void ExampleNodeClass::setupCommunications(){
    ex_publisher_ = this->create_publisher<std_msgs::msg::String>("example_topic_2", 10);
    ex_server_ = this->create_service<example_interfaces::srv::AddTwoInts>("example_service_2",
                                                                            std::bind(&ExampleNodeClass::exampleServerCallBack, this,
                                                                            std::placeholders::_1, std::placeholders::_2));
}

void ExampleNodeClass::examplePublishFunction(){
    timer_counter_ += 1;
    auto ex_msg = std_msgs::msg::String();
    ex_msg.data = std::string("Example c++ published message : ") + std::to_string(timer_counter_) ;
    ex_publisher_->publish(ex_msg);
}

void ExampleNodeClass::exampleServerCallBack(const example_interfaces::srv::AddTwoInts::Request::SharedPtr req, 
                                            const example_interfaces::srv::AddTwoInts::Response::SharedPtr res){
    RCLCPP_INFO(this->get_logger(), "Service called : %ld + %ld = %ld", req->a, req->b, req->a + req->b);
    res->sum = req->a + req->b;
}