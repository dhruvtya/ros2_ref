#include "example_cpp_pkg/ex_cpp_sub_client.hpp"

// Constructor
ExampleNodeClass::ExampleNodeClass(): Node("ex_cpp_sub_client_node"){
    setupCommunications();

    RCLCPP_INFO(this->get_logger(), "Example ROS2 - C++ subscriber & client node");
    
}

void ExampleNodeClass::setupCommunications(){
    ex_subscriber_ = this->create_subscription<ex_interfaces_pkg::msg::ExMsgOne>(
                                    "example_topic_2", 10 , 
                                    std::bind(&ExampleNodeClass::exampleSubscriberCallBack, this, std::placeholders::_1));
    // std::placeholders for every parameter passed to the callback/bound function

    ex_client_ = this->create_client<ex_interfaces_pkg::srv::ExSrvOne>("example_service_2");
}

void ExampleNodeClass::exampleSubscriberCallBack(const ex_interfaces_pkg::msg::ExMsgOne::SharedPtr ex_msg){
    RCLCPP_INFO(this->get_logger(), "Received message : %s", ex_msg->third_var.c_str());

    // Client asked to call service when subscriber receives message
    thread_1_ = std::thread(std::bind(&ExampleNodeClass::exampleServiceClientFn, this, ex_msg->first_var, ex_msg->fifth_var[0], ex_msg->third_var));
    thread_1_.detach(); // Have to detach thread before it goes out of scope
}

void ExampleNodeClass::exampleServiceClientFn(int a, int b, std::string rcvd_string){
    while(!ex_client_->wait_for_service(std::chrono::seconds(1))){
        RCLCPP_WARN(this->get_logger(), "Waiting for server to be up...");
    }

    auto ex_request = std::make_shared<ex_interfaces_pkg::srv::ExSrvOne::Request>();
    ex_request->first_var = a;
    ex_request->second_var = b;
    ex_request->third_var = rcvd_string + "-";

    auto future = ex_client_->async_send_request(ex_request);

    try{
        auto ex_response = future.get();
        RCLCPP_INFO(this->get_logger(), "Client got response : %d + %d = %ld | Also boolean - %d", 
                                            a, b, ex_response->res_int_var, ex_response->res_bool_var);
    }
    catch(const std::exception &e){
        RCLCPP_ERROR(this->get_logger(), "Service call failed");
    }
}