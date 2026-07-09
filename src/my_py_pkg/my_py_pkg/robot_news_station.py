#!/usr/bin/env python3

import rclpy 
from rclpy.node import Node
from example_interfaces.msg import String 


class RobotNewsStation (Node) :
    def __init__(self) :
        super().__init__("robot_news_station")
        # Creating a Publisher 
        # Need to provide name, data type and queue size
        self.publisher_ = self.create_publisher(String, "robot_news", 10)
        # this will publish the message very 0.5 seconds
        self.timer_ = self.create_timer(0.5, self.publish_news)
        self.get_logger().info("Robot News Station node has been started.")

    def publish_news (self) :
        # Creating the message 
        msg = String()
        msg.data = "Hello"
        # publishing the message 
        self.publisher_.publish(msg)
        






def main (args=None) :
    
    rclpy.init(args=args)
    node = RobotNewsStation()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__" :
    main()