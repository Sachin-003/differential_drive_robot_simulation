from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        # Launch the laser filter node
        Node(
            package='bot_control',
            executable='reading_laser',
            name='laser_filter_node',
            output='screen'
        ),

        # Launch RViz to visualize
        Node(
            package='rviz2',
            executable='rviz2',
            name='rviz2',
            output='screen',
            # arguments=['-d', '/home/your_name/your_name_ws/src/bot_control/rviz/filtered_scan.rviz']  # Optional
        ),
    ])
