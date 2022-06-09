#include "rclcpp/rclcpp.hpp"
#include "ex_interfaces_pkg/msg/ex_msg_one.hpp"
#include "ex_interfaces_pkg/srv/ex_srv_one.hpp"

class ExampleNodeClass: public rclcpp::Node
{
    private:
        std::thread thread_1_;
        
        rclcpp::Subscription<ex_interfaces_pkg::msg::ExMsgOne>::SharedPtr ex_subscriber_;
        rclcpp::Client<ex_interfaces_pkg::srv::ExSrvOne>::SharedPtr ex_client_;
        
        void setupCommunications();
        void exampleSubscriberCallBack(const ex_interfaces_pkg::msg::ExMsgOne::SharedPtr );
        void exampleServiceClientFn(int , int, std::string );

    public:
        ExampleNodeClass();
};