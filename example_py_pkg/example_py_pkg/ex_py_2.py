#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

class ExampleNodeClass(Node):

    def __init__(self):
        super().__init__("ex_py_2")
        self.counter_ = 0
        self.get_logger().info("Example ROS2 - python node 2")
        self.create_timer(0.5, self.timer_callback)

    def timer_callback(self):
        self.counter_ += 1
        self.get_logger().info("Timed print - " + str(self.counter_))

def main(args=None):
    rclpy.init(args=args)

    node = ExampleNodeClass()
    rclpy.spin(node)

    rclpy.shutdown()

if __name__ == "__main__":
    main()