#!/usr/bin/env python3

import rclpy 
from rclpy.node import Node

def main (args=None) :
    # This will initlalise the ros2 communication 
    rclpy.init(args=args)

    # This will create a Node 
    node = Node("py_test")

    # Adding logging 
    node.get_logger().info("Hellow World")

    # This will shutdown the node
    rclpy.shutdown()


    if __name__ == "__main__" :
        main()