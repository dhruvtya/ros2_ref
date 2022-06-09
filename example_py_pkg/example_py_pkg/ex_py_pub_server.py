#!/usr/bin/env python3
from sympy import true
import rclpy
from rclpy.node import Node

from ex_interfaces_pkg.srv import ExSrvOne
from ex_interfaces_pkg.msg import ExMsgOne

class ExampleNodeClass(Node):

    def __init__(self):
        super().__init__("ex_py_pub_server_node")

        # Param (with default value)
        self.declare_parameter("ex_param_1", "Example string")

        # Publisher
        self.ex_publisher_ = self.create_publisher(ExMsgOne, "example_topic_1", 10)
        self.ex_timer_ = self.create_timer(5.0, self.exPublishFunction)

        # Service
        self.ex_server_ = self.create_service(ExSrvOne, "example_service_1", self.exampleServiceCallback)

        self.get_logger().info("Python publisher & server node has started")

    def exPublishFunction(self):
        ex_msg = ExMsgOne()
        ex_msg.first_var = 2
        ex_msg.second_var = 3.4
        ex_msg.third_var = self.get_parameter("ex_param_1").value + "-"
        ex_msg.fourth_var = True
        ex_msg.fifth_var = [1,2,3,4]
        self.ex_publisher_.publish(ex_msg)

    def exampleServiceCallback(self, request, response):
        self.get_logger().info("Server got call : " + str(request.first_var) + " + " + str(request.second_var) + " = " + str(request.first_var + request.second_var) + " | " + request.third_var)
        response.res_int_var = request.first_var + request.second_var
        response.res_bool_var = True
        return response
        


def main(args=None):
    rclpy.init(args=args)

    node = ExampleNodeClass()
    rclpy.spin(node)

    rclpy.shutdown()

if __name__ == "__main__":
    main()