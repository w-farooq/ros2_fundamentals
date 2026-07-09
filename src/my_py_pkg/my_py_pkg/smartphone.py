#!/usr/bin/env python3

import rclpy 
from rclpy.node import Node
from example_interfaces.msg import String


class SmartphoneNode (Node) :
    def __init__(self) :
        super().__init__("smartphone")
        # Creating the subscriber 
        # Takes four params data type and topic name a callback and a queue size
        self.subcsubscriber_ = self.create_subscription(String, "robot_news", self.callback_robot_news, 10)
        self.get_logger().info("smartphone has been started.")
       
    def callback_robot_news (self, msg : String) :
        self.get_logger().info(msg.data)
    


    





def main (args=None) :
    
    rclpy.init(args=args)
    node = SmartphoneNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__" :
    main()