#include "rclcpp/rclcpp.hpp"



class MyNode : public rclcpp::Node{

    public:
    MyNode () : Node("cpp_test"), counter_{}{
        // Logging a message 
        RCLCPP_INFO(this->get_logger(), "Hello World");

        // Creating a timer 
        // Create wall timer function takes two params first one is time, second is the callback function. 
        timer_ = this->create_wall_timer(std::chrono::seconds(1), std::bind(&MyNode::timer_call_back, this));

    };

    private:

    void timer_call_back () {
        RCLCPP_INFO(this->get_logger(), "Hello from the C++ timer callback method: %d", counter_);
        ++counter_;
    }
    rclcpp::TimerBase::SharedPtr timer_;
    int counter_;

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