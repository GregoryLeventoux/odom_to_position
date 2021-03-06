from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='odom_to_position',
            executable='odom_to_position',
            name='viewer1',
            parameters=[{"subscribed_topic": "/r2d2/odom"},{"published_topic": "/real_position"}]),
        Node(
            package='odom_to_position',
            executable='odom_to_position',
            name='viewer2',
            parameters=[{"subscribed_topic": "/odometry/filtered"},{"published_topic": "/position/filtered"}])])
