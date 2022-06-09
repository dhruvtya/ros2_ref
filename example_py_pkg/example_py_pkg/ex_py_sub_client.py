#!/usr/bin/env python3

from functools import partial

import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from example_interfaces.srv import AddTwoInts

class ExampleNodeClass(Node):

    def __init__(self):
        super().__init__("ex_py_sub_client_node")

        self.ex_counter_ = 0
        self.ex_subscriber_ = self.create_subscription(String, "example_topic_1", self.exampleSubscriberCallBack, 10)
        self.get_logger().info("Python node subscriber & client has started")

    def exampleSubscriberCallBack(self, ex_msg):
        self.get_logger().info("Received : " + ex_msg.data)
        self.ex_counter_ += 1
        self.exampleServiceClient(self.ex_counter_,self.ex_counter_)

    def exampleServiceClientFn(self, a, b):
        ex_client_ = self.create_client(AddTwoInts, "example_service_1")
        while not ex_client_.wait_for_service(1.0):
            self.get_logger().warn("Waiting for Server example_service_1")

        ex_request_ = AddTwoInts.Request()
        ex_request_.a = a
        ex_request_.b = b

        future = ex_client_.call_async(ex_request_)
        future.add_done_callback(partial(self.exampleClientCallback, a=a, b=b))

    def exampleClientCallback(self, future, a, b):
        try:
            ex_response_ = future.result()
            self.get_logger().info(str(a) + "+" + str(b) + "=" + str(ex_response_.sum))
        except Exception as e:
            self.get_logger().error("Service call failed %r" % (e,))    


def main(args=None):
    rclpy.init(args=args)

    node = ExampleNodeClass()
    rclpy.spin(node)

    rclpy.shutdown()

if __name__ == "__main__":
    main()