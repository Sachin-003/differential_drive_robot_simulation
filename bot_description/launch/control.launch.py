from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='teleop_twist_keyboard',
            executable='teleop_twist_keyboard',
            name='teleop_keyboard',
            output='screen',
            prefix='xterm -e',  # This opens it in a new terminal window so you can type
            remappings=[
                ('/cmd_vel', '/cmd_vel')
            ],
        ),
    ])
