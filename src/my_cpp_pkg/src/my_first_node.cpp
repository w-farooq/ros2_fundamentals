#include "rclcpp/rclcpp.hpp"



class MyNode : public rclcpp::Node{

    public:
    MyNode () : Node("cpp_test") {
        // Logging a message 
        RCLCPP_INFO(this->get_logger(), "Hello World");

        // Creating a timer 
        // Create wall timer function takes two params first one is time, second is the callback function. 
        timer_ = this->create_wall_timer(std::chrono::seconds(1), [this] () {

            RCLCPP_INFO(this->get_logger(), "Hello from the C++ timer callback method: %d", counter_);
            ++counter_;
        });

    };

    private:
    int counter_ {}; // Default value will be 0 for int
    rclcpp::TimerBase::SharedPtr timer_;
    

};


int main (int argc, char **argv) {

    // Starting ros2 communications 
    rclcpp::init(argc, argv);


    // Creating a sharde pointer to an object of MyNode class
    auto node {std::make_shared<MyNode>()};


    
    // Spinning the node 
    rclcpp::spin(node);
    

    // Shutting down the node 
    rclcpp::shutdown();


    return 0;

}