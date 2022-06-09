#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"

class ExampleNodeClass: public rclcpp::Node
{
    private:
        rclcpp::TimerBase::SharedPtr timer_;
        int timer_counter_;

        // Topics & services
        rclcpp::Service<example_interfaces::srv::AddTwoInts>::SharedPtr ex_server_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr ex_publisher_;

        // Functions
        void setupCommunications();
        void examplePublishFunction();
        void exampleServerCallBack(const example_interfaces::srv::AddTwoInts::Request::SharedPtr, 
                                    const example_interfaces::srv::AddTwoInts::Response::SharedPtr);

    public:
        ExampleNodeClass();
};