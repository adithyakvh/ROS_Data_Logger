// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interface:msg/DataLogger.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACE__MSG__DETAIL__DATA_LOGGER__BUILDER_HPP_
#define CUSTOM_INTERFACE__MSG__DETAIL__DATA_LOGGER__BUILDER_HPP_

#include "custom_interface/msg/detail/data_logger__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace custom_interface
{

namespace msg
{

namespace builder
{

class Init_DataLogger_actual_speed
{
public:
  explicit Init_DataLogger_actual_speed(::custom_interface::msg::DataLogger & msg)
  : msg_(msg)
  {}
  ::custom_interface::msg::DataLogger actual_speed(::custom_interface::msg::DataLogger::_actual_speed_type arg)
  {
    msg_.actual_speed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interface::msg::DataLogger msg_;
};

class Init_DataLogger_time_ros
{
public:
  explicit Init_DataLogger_time_ros(::custom_interface::msg::DataLogger & msg)
  : msg_(msg)
  {}
  Init_DataLogger_actual_speed time_ros(::custom_interface::msg::DataLogger::_time_ros_type arg)
  {
    msg_.time_ros = std::move(arg);
    return Init_DataLogger_actual_speed(msg_);
  }

private:
  ::custom_interface::msg::DataLogger msg_;
};

class Init_DataLogger_altitude
{
public:
  explicit Init_DataLogger_altitude(::custom_interface::msg::DataLogger & msg)
  : msg_(msg)
  {}
  Init_DataLogger_time_ros altitude(::custom_interface::msg::DataLogger::_altitude_type arg)
  {
    msg_.altitude = std::move(arg);
    return Init_DataLogger_time_ros(msg_);
  }

private:
  ::custom_interface::msg::DataLogger msg_;
};

class Init_DataLogger_latitude
{
public:
  explicit Init_DataLogger_latitude(::custom_interface::msg::DataLogger & msg)
  : msg_(msg)
  {}
  Init_DataLogger_altitude latitude(::custom_interface::msg::DataLogger::_latitude_type arg)
  {
    msg_.latitude = std::move(arg);
    return Init_DataLogger_altitude(msg_);
  }

private:
  ::custom_interface::msg::DataLogger msg_;
};

class Init_DataLogger_longitude
{
public:
  Init_DataLogger_longitude()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DataLogger_latitude longitude(::custom_interface::msg::DataLogger::_longitude_type arg)
  {
    msg_.longitude = std::move(arg);
    return Init_DataLogger_latitude(msg_);
  }

private:
  ::custom_interface::msg::DataLogger msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interface::msg::DataLogger>()
{
  return custom_interface::msg::builder::Init_DataLogger_longitude();
}

}  // namespace custom_interface

#endif  // CUSTOM_INTERFACE__MSG__DETAIL__DATA_LOGGER__BUILDER_HPP_
