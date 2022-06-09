#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"

class ExampleNodeClass: public rclcpp::Node
{
    private:
        std::thread thread_1_;
        int counter_;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr ex_subscriber_;
        rclcpp::Client<example_interfaces::srv::AddTwoInts>::SharedPtr ex_client_;
        
        void setupCommunications();
        void exampleSubscriberCallBack(const std_msgs::msg::String::SharedPtr );
        void exampleServiceClientFn(int , int );

    public:
        ExampleNodeClass();
};