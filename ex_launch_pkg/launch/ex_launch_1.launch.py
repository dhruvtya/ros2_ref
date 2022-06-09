from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    ld = LaunchDescription()

    ex_cpp_pub_server_node = Node(
        package="example_cpp_pkg",
        executable="ex_cpp_pub_server_node",
        name="can_put_new_name_for_node",
        remappings=[
            ("example_topic_2", "ex_topic_2_new")
        ],
        parameters=[
            {"ex_param_2": "Different string"}
        ]
    )
    ex_cpp_sub_client_node = Node(
        package="example_cpp_pkg",
        executable="ex_cpp_sub_client_node",
        name="ex_cpp_sub_client_node",
        remappings=[
            ("example_topic_2", "ex_topic_2_new")
        ]
    )

    ld.add_action(ex_cpp_pub_server_node)
    ld.add_action(ex_cpp_sub_client_node)
    return ld