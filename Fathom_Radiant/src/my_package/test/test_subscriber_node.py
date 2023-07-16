import pytest
import rclpy
from rclpy.node import Node
from custom_interface.msg import DataLogger
from std_msgs.msg import Float32
from my_package.subscriber_node import SubscriberNode
from builtin_interfaces.msg import Time
from datetime import datetime
import csv

@pytest.fixture
def subscriber_node():
    rclpy.init()
    node = SubscriberNode()
    yield node
    node.destroy_node()
    rclpy.shutdown()


def test_subscriber_node_scan_callback(subscriber_node):
    received_messages = []

    def callback(msg):
        received_messages.append(msg)

    subscription = subscriber_node.create_subscription(
        msg_type=Float32,
        topic='/diff',
        qos_profile=10,
        callback=callback
    )

    file_path = "../my_package/Dataset.csv"
    test_data_points = []
    time_diff_column = []
    with open(file_path, 'r') as csv_file:
        heading = next(csv_file)
        reader = csv.reader(csv_file)
        for row_no, row in enumerate(reader):
            time_iso = row[4]
            iso_time = datetime.fromisoformat(time_iso.replace("Z", "+00:00"))
            ros_time = Time(sec=int(iso_time.timestamp()), nanosec=int(iso_time.microsecond * 1000))

            test_data_points.append(ros_time)
            time_diff_column.append(float(row[6]))
            if row_no >= 2:
                break

    # Create sample messages to publish
    sample_messages = [
        DataLogger(time_ros=test_data_points[0]),
        DataLogger(time_ros=test_data_points[1]),
        DataLogger(time_ros=test_data_points[2]),
    ]
    
    for i, msg in enumerate(sample_messages):
        subscriber_node.scan_callback(msg)
        rclpy.spin_once(subscriber_node)
        if i > 0:
            time_diff = time_diff_column[i]
            assert abs(received_messages[i].data - time_diff) < 0.001

    assert len(received_messages) == 3


if __name__ == '__main__':
    pytest.main()