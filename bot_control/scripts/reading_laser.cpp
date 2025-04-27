#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"

using std::placeholders::_1;

class LaserFilterNode : public rclcpp::Node
{
public:
    LaserFilterNode() : Node("laser_filter_node")
    {
        // Subscribe to original /scan
        laser_subscriber_ = this->create_subscription<sensor_msgs::msg::LaserScan>(
            "/scan", 10, std::bind(&LaserFilterNode::laser_callback, this, _1));

        // Publisher for filtered /filtered_scan
        laser_publisher_ = this->create_publisher<sensor_msgs::msg::LaserScan>(
            "/filtered_scan", 10);

        RCLCPP_INFO(this->get_logger(), "Laser Filter Node Started");
    }

private:
    void laser_callback(const sensor_msgs::msg::LaserScan::SharedPtr msg)
    {
        auto filtered_msg = sensor_msgs::msg::LaserScan();

        filtered_msg.header = msg->header;
        filtered_msg.angle_min = 0.0;
        filtered_msg.angle_max = 2.0 * M_PI / 3.0; // 120 degrees
        filtered_msg.angle_increment = msg->angle_increment;
        filtered_msg.time_increment = msg->time_increment;
        filtered_msg.scan_time = msg->scan_time;
        filtered_msg.range_min = msg->range_min;
        filtered_msg.range_max = msg->range_max;

        // Calculate start and end indices for 0 to 120 degrees
        int start_idx = static_cast<int>((0.0 - msg->angle_min) / msg->angle_increment);
        int end_idx = static_cast<int>((2.0 * M_PI / 3.0 - msg->angle_min) / msg->angle_increment);

        if (start_idx < 0) start_idx = 0;
        if (end_idx >= msg->ranges.size()) end_idx = msg->ranges.size() - 1;

        filtered_msg.ranges.assign(
            msg->ranges.begin() + start_idx,
            msg->ranges.begin() + end_idx + 1
        );

        // Publish filtered scan
        laser_publisher_->publish(filtered_msg);
    }

    rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr laser_subscriber_;
    rclcpp::Publisher<sensor_msgs::msg::LaserScan>::SharedPtr laser_publisher_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<LaserFilterNode>());
    rclcpp::shutdown();
    return 0;
}
