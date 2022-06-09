#!/usr/bin/env python3

from functools import partial

import rclpy
from rclpy.node import Node

from ex_interfaces_pkg.srv import ExSrvOne
from ex_interfaces_pkg.msg import ExMsgOne

class ExampleNodeClass(Node):

    def __init__(self):
        super().__init__("ex_py_sub_client_node")

        self.ex_subscriber_ = self.create_subscription(ExMsgOne, "example_topic_1", self.exampleSubscriberCallBack, 10)
        self.get_logger().info("Python node subscriber & client has started")

    def exampleSubscriberCallBack(self, ex_msg):
        self.get_logger().info("Received : " + ex_msg.third_var)
    
        self.exampleServiceClientFn(ex_msg.first_var,ex_msg.fifth_var[0], ex_msg.third_var)

    def exampleServiceClientFn(self, a, b, rcvd_string):
        ex_client_ = self.create_client(ExSrvOne, "example_service_1")
        while not ex_client_.wait_for_service(1.0):
            self.get_logger().warn("Waiting for Server example_service_1")

        ex_request_ = ExSrvOne.Request()
        ex_request_.first_var = a
        ex_request_.second_var = b
        ex_request_.third_var = rcvd_string + "-"

        future = ex_client_.call_async(ex_request_)
        future.add_done_callback(partial(self.exampleClientCallback, a=a, b=b))

    def exampleClientCallback(self, future, a, b):
        try:
            ex_response_ = future.result()
            self.get_logger().info(str(a) + "+" + str(b) + "=" + str(ex_response_.res_int_var) + " | Also got - " + str(ex_response_.res_bool_var))
        except Exception as e:
            self.get_logger().error("Service call failed %r" % (e,))    


def main(args=None):
    rclpy.init(args=args)

    node = ExampleNodeClass()
    rclpy.spin(node)

    rclpy.shutdown()

if __name__ == "__main__":
    main()