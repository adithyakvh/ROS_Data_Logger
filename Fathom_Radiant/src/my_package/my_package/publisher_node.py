import rclpy
from rclpy.node import Node
from custom_interface.msg import DataLogger
import csv
from datetime import datetime
from builtin_interfaces.msg import Time
from time import sleep

class PublisherNode(Node):
    def __init__(self):
        super().__init__("publisher_node")
        
        self.publisher_ = self.create_publisher(DataLogger, "/data", 10)

    def publish_data(self, file_path):
        
        with open(file_path, 'r') as csv_file:
            heading = next(csv_file)
            reader = csv.reader(csv_file)

            for row in reader:
                longitude, latitude, altitude, time_iso, speed = row[1:6]
                longitude = float(longitude)
                latitude = float(latitude)
                altitude = float(altitude)
                speed = float(speed)

                iso_time = datetime.fromisoformat(time_iso.replace("Z", "+00:00"))
                ros_time = Time(sec=int(iso_time.timestamp()), nanosec=int(iso_time.microsecond * 1000))

                pub_msg = DataLogger()
                pub_msg.longitude = longitude
                pub_msg.latitude = latitude
                pub_msg.altitude = altitude
                pub_msg.time_ros = ros_time
                pub_msg.actual_speed = speed

                self.get_logger().info(f"ros_time: {ros_time.sec}")
                self.publisher_.publish(pub_msg)
                sleep(1.0/3)
                

def main(args=None):
    rclpy.init(args=args)
    publisher_node = PublisherNode()

    file_path = "/home/adithyakvh/Courses/Fathom_Radiant/src/my_package/my_package/Dataset.csv"

    publisher_node.publish_data(file_path)

    publisher_node.destroy_node()
    rclpy.shutdown()
    
if __name__=='__main__':
    main()