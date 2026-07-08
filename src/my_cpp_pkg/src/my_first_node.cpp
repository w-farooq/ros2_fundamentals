#include "rclcpp/rclcpp.hpp"




int main (int argc, char **argv) {

    // Starting ros2 communications 
    rclcpp::init(argc, argv);


    // Creating a Node 
    auto node {std::make_shared<rclcpp::Node>()};


    // Logging a message 
    RCLCPP_INFO(node->get_logger(), "Hello World");

    



    // Shutting down the node 
    rclcpp::shutdown();


    return 0;

}