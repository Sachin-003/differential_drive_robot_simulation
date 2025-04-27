from launch import LaunchDescription
from launch.actions import ExecuteProcess
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration
from ament_index_python.packages import get_package_share_directory

import os

def generate_launch_description():
    # Assuming bot_description is your robot's description package
    world_path = os.path.join(
        get_package_share_directory('bot_world'),
        'worlds',
        'my_world.sdf'
    )

    return LaunchDescription([
        # Start Gazebo with the custom world
        ExecuteProcess(
            cmd=['gz', 'sim', world_path],
            output='screen'
        ),

        # Small delay if needed so that Gazebo fully loads
        # TimerAction(period=5.0, actions=[

        # Spawn the robot
        # Node(
        #     package='robot_state_publisher',
        #     executable='robot_state_publisher',
        #     name='robot_state_publisher',
        #     output='screen',
        #     parameters=[{
        #         'robot_description': Command([
        #             'xacro ',
        #             os.path.join(get_package_share_directory('bot_description'), 'urdf', 'mybot.urdf')
        #         ])
        #     }]
        # ),

        # Node(
        #     package='gazebo_ros',
        #     executable='spawn_entity.py',
        #     arguments=[
        #         '-topic', 'robot_description',
        #         '-entity', 'mybot',
        #         '-x', '0', '-y', '0', '-z', '0.1'
        #     ],
        #     output='screen'
        # ),

    ])
