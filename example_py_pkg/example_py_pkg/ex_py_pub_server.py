#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from example_interfaces.srv import AddTwoInts

class ExampleNodeClass(Node):

    def __init__(self):
        super().__init__("ex_py_pub_server_node")

        # Publisher
        self.ex_publisher_ = self.create_publisher(String, "example_topic_1", 10)
        self.ex_timer_ = self.create_timer(5.0, self.exPublishFunction)

        # Service
        self.ex_server_ = self.create_service(AddTwoInts, "example_service_1", self.exampleServiceCallback)

        self.get_logger().info("Python publisher & server node has started")

    def exPublishFunction(self):
        ex_msg = String()
        ex_msg.data = "Example message"
        self.ex_publisher_.publish(ex_msg)

    def exampleServiceCallback(self, request, response):
        self.get_logger().info("Called : " + str(request.a) + " + " + str(request.b) + " = " + str(request.a + request.b))
        response.sum = request.a + request.b
        return response
        


def main(args=None):
    rclpy.init(args=args)

    node = ExampleNodeClass()
    rclpy.spin(node)

    rclpy.shutdown()

if __name__ == "__main__":
    main()