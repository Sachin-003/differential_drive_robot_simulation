# Robot Description Package

This package includes the robot description for a differential drive robot using **ROS2 Jazzy**. The robot features a **GPU LiDAR**, **camera**, and wheels with defined joints, as well as necessary configurations for simulation in Gazebo and visualization in RViz.

## Setup Instructions

### 1. Launch Robot in Gazebo
To spawn the robot in the Gazebo simulation environment, use the following command:

```bash
ros2 launch bot_description spawn.launch.py

```
![image](https://github.com/user-attachments/assets/1fa305e9-241a-417a-9180-b33a54f6bcdf)



### 2. Visualize Robot in RViz

To visualize the robot in RViz, use the command below:

```bash

ros2 launch bot_description rviz.launch.py
```
![image](https://github.com/user-attachments/assets/b009d8b5-c348-4b3b-a075-a3a3c2a799d7)


### 3. Control Robot via Teleop
To control the robot using teleop_twist_keyboard,

```bash
ros2 launch bot_description control.launch.py
```
![image](https://github.com/user-attachments/assets/e3bd3406-f31e-445e-99a0-95209f851bfe)

### Demo Video



https://github.com/user-attachments/assets/2ef6c6d5-33ea-4cd7-a7be-01dd94361fd1



Dependencies
```bash
ROS2 Jazzy

Gazebo

RViz

teleop_twist_keyboard package

```
