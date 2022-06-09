#include "example_cpp_pkg/ex_cpp_pub_server.hpp"

// Constructor
ExampleNodeClass::ExampleNodeClass(): Node("ex_cpp_pub_server_node"){
    // Parameter
    this->declare_parameter("ex_param_2", "Example string");

    
    setupCommunications();

    RCLCPP_INFO(this->get_logger(), "Example ROS2 - C++ publisher & server node");
    timer_ = this->create_wall_timer(std::chrono::seconds(5), 
                                     std::bind(&ExampleNodeClass::examplePublishFunction, this));
}

void ExampleNodeClass::setupCommunications(){
    // Publishers
    ex_publisher_ = this->create_publisher<ex_interfaces_pkg::msg::ExMsgOne>("example_topic_2", 10);

    // Services
    ex_server_ = this->create_service<ex_interfaces_pkg::srv::ExSrvOne>("example_service_2",
                                                                            std::bind(&ExampleNodeClass::exampleServerCallBack, this,
                                                                            std::placeholders::_1, std::placeholders::_2));
}

void ExampleNodeClass::examplePublishFunction(){
    auto ex_msg = ex_interfaces_pkg::msg::ExMsgOne();
    ex_msg.first_var = 3;
    ex_msg.second_var = 4.5;
    ex_msg.third_var = this->get_parameter("ex_param_2").as_string() + "-"; // Have to cast data type
    ex_msg.fourth_var = false;
    ex_msg.fifth_var.push_back(10);
    ex_msg.fifth_var.push_back(9);
    ex_publisher_->publish(ex_msg);
}

void ExampleNodeClass::exampleServerCallBack(const ex_interfaces_pkg::srv::ExSrvOne::Request::SharedPtr req, 
                                            const ex_interfaces_pkg::srv::ExSrvOne::Response::SharedPtr res){
    RCLCPP_INFO(this->get_logger(), "Service called : %ld + %ld = %ld | With - %s", 
                                    req->first_var, req->second_var, req->first_var + req->second_var, req->third_var.c_str());
    res->res_int_var = req->first_var + req->second_var;
    res->res_bool_var = false;
}