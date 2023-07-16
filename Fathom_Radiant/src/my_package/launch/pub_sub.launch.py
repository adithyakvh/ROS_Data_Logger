from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    
    talker_node = Node(
        package='my_package',
        namespace='',
        executable='publisher_node',
        name='publisher_node'
        )

    listener_node = Node(package='my_package',
        namespace='',
        executable='subscriber_node',
        name='subscriber_node')

    ld = LaunchDescription()

    #ld.add_action(node1)
    ld.add_action(talker_node)
    ld.add_action(listener_node)

    return ld
