#include "rclcpp/rclcpp.hpp"
#include "ex_interfaces_pkg/msg/ex_msg_one.hpp"
#include "ex_interfaces_pkg/srv/ex_srv_one.hpp"

class ExampleNodeClass: public rclcpp::Node
{
    private:
        rclcpp::TimerBase::SharedPtr timer_;

        // Topics & services
        rclcpp::Service<ex_interfaces_pkg::srv::ExSrvOne>::SharedPtr ex_server_;
        rclcpp::Publisher<ex_interfaces_pkg::msg::ExMsgOne>::SharedPtr ex_publisher_;

        // Functions
        void setupCommunications();
        void examplePublishFunction();
        void exampleServerCallBack(const ex_interfaces_pkg::srv::ExSrvOne::Request::SharedPtr, 
                                    const ex_interfaces_pkg::srv::ExSrvOne::Response::SharedPtr);

    public:
        ExampleNodeClass();
};