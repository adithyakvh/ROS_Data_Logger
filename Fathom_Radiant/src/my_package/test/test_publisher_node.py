import pytest
import rclpy
from rclpy.executors import SingleThreadedExecutor
from custom_interface.msg import DataLogger
from my_package.publisher_node import PublisherNode
from datetime import datetime
from builtin_interfaces.msg import Time
import csv

@pytest.fixture
def publisher_node():
    rclpy.init()
    node = PublisherNode()
    yield node
    node.destroy_node()
    rclpy.shutdown()


def test_publish_data(publisher_node):

    file_path = "../my_package/Dataset.csv"
    with open(file_path, 'r') as csv_file:
        heading = next(csv_file)
        reader = csv.reader(csv_file)
        for row in reader:
            expected_longitude, expected_latitude, expected_altitude, time_iso, speed = row[1:6]
            pub_msg = DataLogger()
            pub_msg.longitude =float(expected_longitude)
            pub_msg.latitude = float(expected_latitude)
            pub_msg.altitude = float(expected_altitude)
            
            pub_msg.actual_speed = float(speed)

            iso_time = datetime.fromisoformat(time_iso.replace("Z", "+00:00"))
            ros_time = Time(sec=int(iso_time.timestamp()), nanosec=int(iso_time.microsecond * 1000))
            pub_msg.time_ros = ros_time
            break


    # Create a list to store the received messages
    received_msgs = []

    # Define a callback function to capture the published messages
    def callback(msg):
        received_msgs.append(msg)

    # Subscribe to the "/data" topic
    subscriber = publisher_node.create_subscription(
        DataLogger, "/data", callback, 10
    )

    # Publish the test message
    publisher_node.publisher_.publish(pub_msg)

    # Wait for the message to be received
    executor = SingleThreadedExecutor()
    executor.add_node(publisher_node)
    executor.spin_once(timeout_sec=1.0)

    # Verify the received message
    assert len(received_msgs) == 1
    received_msg = received_msgs[0]
    assert received_msg.longitude == pytest.approx(float(expected_longitude))
    assert received_msg.latitude ==  pytest.approx(float(expected_latitude))
    assert received_msg.altitude ==  pytest.approx(float(expected_altitude))
    


if __name__ == '__main__':
    pytest.main()