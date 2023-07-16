import rclpy
from rclpy.node import Node
from custom_interface.msg import DataLogger
from std_msgs.msg import Float32


class SubscriberNode(Node):
    def __init__(self):
        super().__init__("subscriber_node")
        
        self.subscription_ = self.create_subscription(DataLogger, "/data", self.scan_callback, 10)
        self.time_diff_publisher = self.create_publisher(Float32, "/diff", 1)

        self.previous_time = None

    def scan_callback(self, scan_msg):
        
        # self.get_logger().info("Inside scan_callback")
        # self.get_logger().info(f"scan_msg: {scan_msg.time_ros.sec}")

        if self.previous_time is None:
            time_diff = float(0)
        elif self.previous_time is not None:
            time_diff = float(scan_msg.time_ros.sec - self.previous_time)
        self.previous_time = scan_msg.time_ros.sec

        time_float = Float32()
        time_float.data = time_diff
        # self.get_logger().info(f"time_diff: {time_diff}")

        self.time_diff_publisher.publish(time_float)

def main(args=None):
    rclpy.init(args=args)
    subscriber_node = SubscriberNode()

    try:
        rclpy.spin(subscriber_node)
    except KeyboardInterrupt:
        pass

    subscriber_node.destroy_node()
    rclpy.shutdown()
    
if __name__=='__main__':
    main()