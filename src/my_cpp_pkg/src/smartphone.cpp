#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp"



class Smarthphone : public rclcpp::Node{

    public:
    Smarthphone () : Node("smartphone") {
       
        subscriber_ = this->create_subscription<example_interfaces::msg::String>("robot_news",10, [this] (const example_interfaces::msg::String::SharedPtr msg) {call_back_robot_news(msg);});
        RCLCPP_INFO(this->get_logger(), "Smartphone has been started.");

    };

    private:
    rclcpp::Subscription<example_interfaces::msg::String>::SharedPtr subscriber_;

    void call_back_robot_news (const example_interfaces::msg::String::SharedPtr msg) {
        RCLCPP_INFO(this->get_logger(), "%s", msg->data.c_str());
    }
    
    

};


int main (int argc, char **argv) {

    
    rclcpp::init(argc, argv);    
    auto node {std::make_shared<Smarthphone>()};
    rclcpp::spin(node);
    rclcpp::shutdown();


    return 0;

}