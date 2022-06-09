#include "example_cpp_pkg/ex_cpp_sub_client.hpp"

// Constructor
ExampleNodeClass::ExampleNodeClass(): Node("ex_cpp_sub_client_node"), counter_(0){
    setupCommunications();

    RCLCPP_INFO(this->get_logger(), "Example ROS2 - C++ subscriber & client node");
    
}

void ExampleNodeClass::setupCommunications(){
    ex_subscriber_ = this->create_subscription<std_msgs::msg::String>(
                                    "example_topic_2", 10 , 
                                    std::bind(&ExampleNodeClass::exampleSubscriberCallBack, this, std::placeholders::_1));
    // std::placeholders for every parameter passed to the callback/bound function

    ex_client_ = this->create_client<example_interfaces::srv::AddTwoInts>("example_service_2");
}

void ExampleNodeClass::exampleSubscriberCallBack(const std_msgs::msg::String::SharedPtr ex_msg){
    RCLCPP_INFO(this->get_logger(), "Received message : %s", ex_msg->data.c_str());

    counter_++;
    // Client asked to call service when subscriber receives message
    thread_1_ = std::thread(std::bind(&ExampleNodeClass::exampleServiceClientFn, this, counter_, counter_));
    thread_1_.detach(); // Have to detach thread before it goes out of scope
}

void ExampleNodeClass::exampleServiceClientFn(int a, int b){
    while(!ex_client_->wait_for_service(std::chrono::seconds(1))){
        RCLCPP_WARN(this->get_logger(), "Waiting for server to be up...");
    }

    auto ex_request = std::make_shared<example_interfaces::srv::AddTwoInts::Request>();
    ex_request->a = a;
    ex_request->b = b;

    auto future = ex_client_->async_send_request(ex_request);

    try{
        auto ex_response = future.get();
        RCLCPP_INFO(this->get_logger(), "Client got response : %d + %d = %ld", a, b, ex_response->sum);
    }
    catch(const std::exception &e){
        RCLCPP_ERROR(this->get_logger(), "Service call failed");
    }
}