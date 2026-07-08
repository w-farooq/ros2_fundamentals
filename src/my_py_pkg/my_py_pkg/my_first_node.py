#!/usr/bin/env python3

import rclpy 
from rclpy.node import Node


class MyNode (Node) :
    def __init__(self) :
        super().__init__("py_test")
        self.get_logger().info("Hello world")





def main (args=None) :
    # This will initlalise the ros2 communication 
    rclpy.init(args=args)

    # This will create a Node with the name py_test 
    node = MyNode()

    # Keeping the node alive by passing it fo the sping function as an argument
    rclpy.spin(node)

    # This will shutdown the node
    rclpy.shutdown()


if __name__ == "__main__" :
    main()