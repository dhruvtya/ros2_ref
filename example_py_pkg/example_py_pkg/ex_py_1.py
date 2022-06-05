#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

def main(args=None):
    rclpy.init(args=args)

    node = Node("ex_py_1")
    node.get_logger().info("Example ROS2 - python node 1")
    rclpy.spin(node)
    
    rclpy.shutdown()

if __name__ == "__main__":
    main()