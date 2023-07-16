// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_interface:msg/DataLogger.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACE__MSG__DETAIL__DATA_LOGGER__STRUCT_HPP_
#define CUSTOM_INTERFACE__MSG__DETAIL__DATA_LOGGER__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'time_ros'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__custom_interface__msg__DataLogger __attribute__((deprecated))
#else
# define DEPRECATED__custom_interface__msg__DataLogger __declspec(deprecated)
#endif

namespace custom_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DataLogger_
{
  using Type = DataLogger_<ContainerAllocator>;

  explicit DataLogger_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : time_ros(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->longitude = 0.0f;
      this->latitude = 0.0f;
      this->altitude = 0.0f;
      this->actual_speed = 0.0f;
    }
  }

  explicit DataLogger_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : time_ros(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->longitude = 0.0f;
      this->latitude = 0.0f;
      this->altitude = 0.0f;
      this->actual_speed = 0.0f;
    }
  }

  // field types and members
  using _longitude_type =
    float;
  _longitude_type longitude;
  using _latitude_type =
    float;
  _latitude_type latitude;
  using _altitude_type =
    float;
  _altitude_type altitude;
  using _time_ros_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _time_ros_type time_ros;
  using _actual_speed_type =
    float;
  _actual_speed_type actual_speed;

  // setters for named parameter idiom
  Type & set__longitude(
    const float & _arg)
  {
    this->longitude = _arg;
    return *this;
  }
  Type & set__latitude(
    const float & _arg)
  {
    this->latitude = _arg;
    return *this;
  }
  Type & set__altitude(
    const float & _arg)
  {
    this->altitude = _arg;
    return *this;
  }
  Type & set__time_ros(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->time_ros = _arg;
    return *this;
  }
  Type & set__actual_speed(
    const float & _arg)
  {
    this->actual_speed = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_interface::msg::DataLogger_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_interface::msg::DataLogger_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_interface::msg::DataLogger_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_interface::msg::DataLogger_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_interface::msg::DataLogger_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_interface::msg::DataLogger_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_interface::msg::DataLogger_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_interface::msg::DataLogger_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_interface::msg::DataLogger_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_interface::msg::DataLogger_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_interface__msg__DataLogger
    std::shared_ptr<custom_interface::msg::DataLogger_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_interface__msg__DataLogger
    std::shared_ptr<custom_interface::msg::DataLogger_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DataLogger_ & other) const
  {
    if (this->longitude != other.longitude) {
      return false;
    }
    if (this->latitude != other.latitude) {
      return false;
    }
    if (this->altitude != other.altitude) {
      return false;
    }
    if (this->time_ros != other.time_ros) {
      return false;
    }
    if (this->actual_speed != other.actual_speed) {
      return false;
    }
    return true;
  }
  bool operator!=(const DataLogger_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DataLogger_

// alias to use template instance with default allocator
using DataLogger =
  custom_interface::msg::DataLogger_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_interface

#endif  // CUSTOM_INTERFACE__MSG__DETAIL__DATA_LOGGER__STRUCT_HPP_
