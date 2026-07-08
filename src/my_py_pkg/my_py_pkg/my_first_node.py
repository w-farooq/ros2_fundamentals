#!/usr/bin/env python3

import rclpy 
from rclpy.node import Node


class MyNode (Node) :
    def __init__(self) :
        super().__init__("py_test")
        self.counter_ = 0
        self.get_logger().info("Hello world")

        # create_timer function takes two arguments : 
        # first float timer period in seconds 
        # second callback_function 
        self.create_timer(1.0, self.timer_callback)
    
    # Timer callback 
    def timer_callback (self) : 
        self.get_logger().info("Hello from the timer method count: " + str(self.counter_))
        self.counter_ +=1





def main (args=None) :
    # This will initlalise the ros2 communication 
    rclpy.init(args=args)

    # This will create a Node with the name py_test 
    node = MyNode()

    # Keeping the node alive by passing it to the spin function as an argument
    # It will allow the node to process any callbacks 
    rclpy.spin(node)

    # This will shutdown the node
    rclpy.shutdown()


if __name__ == "__main__" :
    main()