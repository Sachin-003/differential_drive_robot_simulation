# Bot Control Package

This package contains the **Laser Filter Node** that subscribes to the original `/scan` topic, filters the laser scan data to the range of 0 to 120 degrees, and publishes the filtered data to the `/filtered_scan` topic.

## Setup Instructions

### Launch Laser Filter Node

To start the node, use the following command:

```bash
ros2 run bot_control bot_control.launch.py
```
## Topics
```bash
Input topic: /scan (Original Laser Scan Data)

Output topic: /filtered_scan (Filtered Laser Scan Data - 0 to 120 degrees)
```
Dependencies
```bash
ROS2 Jazzy

sensor_msgs/msg/LaserScan

```
