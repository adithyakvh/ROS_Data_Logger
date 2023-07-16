# ROS Data Logger

This repository contains a ROS (Robot Operating System) package that consists of a publisher and a subscriber node. The publisher node reads data from a CSV file and publishes it on a topic, while the subscriber node subscribes to the topic and calculates the time difference between consecutive data points.

## Installation

1. Clone the repository to your ROS workspace:

   ```bash
   $ git clone https://github.com/adithyakvh/ROS_Data_Logger.git
   ```

2. Build the ROS package from inside the Fathom_Radiant folder:

   ```bash
   $ cd Fathom_Radiant
   $ colcon build
   ```

## Usage

1. Launch the ROS environment:

   ```bash
   $ source install/setup.bash
   ```

2. Run the launch file which will automatically run the publisher and subscriber nodes respectively:

   ```bash
   $ ros2 launch my_package pub_sub.launch.py
   ```

   The publisher node reads data from a CSV file located at `Fathom_Radiant/src/my_package/my_package/Dataset.csv` and publishes it on the `/data` topic.

   The subscriber node subscribes to the `/data` topic and calculates the time difference between consecutive data points. It publishes the time difference on the `/diff` topic.

3. View the time difference:

   You can view the time difference by subscribing to the `/diff` topic using the `ros2 topic echo` command:

   ```bash
   $ ros2 topic echo /diff
   ```

   The time difference between consecutive data points will be displayed.

## CSV Format

The CSV file should have the following format:

```csv
heading
longitude,latitude,altitude,time_iso,speed
...
```

- The first row is a heading row and is ignored.
- Each subsequent row contains the following comma-separated values:
  - `longitude`: Longitude coordinate
  - `latitude`: Latitude coordinate
  - `altitude`: Altitude value
  - `time_iso`: ISO-formatted time string (e.g., `2023-07-16T12:00:00Z`)
  - `speed`: Speed value

## Custom Message

The package uses a custom message type called `DataLogger`. The message contains the following fields:

- `longitude`: Float64, longitude coordinate
- `latitude`: Float64, latitude coordinate
- `altitude`: Float64, altitude value
- `time_ros`: Time, ROS time stamp
- `actual_speed`: Float64, speed value

## Unit Test

To perform unit tests, navigate to the test folder inside `my_package`

```bash
   $ cd src/my_package/test
   $ pytest
   ```
The test folder has two unit tests for the publisher and subscriber nodes respectively. 
- Publisher node is tested if the message is being correctly read from the csv file and being published.
- Subscriber node is tested if the node reads the messages from the /data topic and correctly computes the time difference between two consecutive messages.

## Acknowledgments

This package was developed by `Adithyakrishna VH`.
