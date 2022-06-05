#include "rclcpp/rclcpp.hpp"

class ExampleNodeClass: public rclcpp::Node
{
    private:
        void exampleTimer();
        rclcpp::TimerBase::SharedPtr timer_;
        int timer_counter_;

    public:
        ExampleNodeClass();
};