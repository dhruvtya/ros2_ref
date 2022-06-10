# import os
# from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    ld = LaunchDescription()

    # config_file = os.path.join(
    #   get_package_share_directory('package_name'),
    #   'config',
    #   'config_file_name.yaml'
    # )

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
        # namespace="can_put_namespace"
        # parameters=[config_file]
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