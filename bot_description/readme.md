# Robot Description Package

This package includes the robot description for a differential drive robot using **ROS2 Jazzy**. The robot features a **GPU LiDAR**, **camera**, and wheels with defined joints, as well as necessary configurations for simulation in Gazebo and visualization in RViz.

## Setup Instructions

### 1. Launch Robot in Gazebo
To spawn the robot in the Gazebo simulation environment, use the following command:

```bash
ros2 launch bot_description spawn.launch.py

```
### 2. Visualize Robot in RViz

To visualize the robot in RViz, use the command below:

```bash

ros2 launch bot_description rviz.launch.py
```

### 3. Control Robot via Teleop
To control the robot using teleop_twist_keyboard,

```bash
ros2 launch bot_description control.launch.py
```
Dependencies
```bash
ROS2 Jazzy

Gazebo

RViz

teleop_twist_keyboard package

```
