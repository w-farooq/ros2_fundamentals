#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp"

using namespace std::chrono_literals;

class RobotNewsStationNode : public rclcpp::Node {

    public:
    RobotNewsStationNode () : Node("robot_news") {
        // Creating the publisher 
        // create publisher method takes the data type of the msg , topic name and queue size
        publisher_ = this->create_publisher<example_interfaces::msg::String>("robot_news", 10);
        timer_ = this->create_wall_timer(0.5s, [this] () {publish_news();});

        RCLCPP_INFO(this->get_logger(), "Robot News Station Node started");

    }
    

    private:
    void publish_news () {
        auto msg {example_interfaces::msg::String()};
        msg.data = "Hi, from the c++ publisher";
        publisher_->publish(msg);
    }
    rclcpp::Publisher<example_interfaces::msg::String>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;


    
};


int main (int argc, char **argv) {

    rclcpp::init(argc, argv);


    auto node {std::make_shared<RobotNewsStationNode>()};

    rclcpp::spin(node);
    rclcpp::shutdown();

    return 0;
}