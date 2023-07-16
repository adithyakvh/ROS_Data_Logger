// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_interface:msg/DataLogger.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACE__MSG__DETAIL__DATA_LOGGER__TRAITS_HPP_
#define CUSTOM_INTERFACE__MSG__DETAIL__DATA_LOGGER__TRAITS_HPP_

#include "custom_interface/msg/detail/data_logger__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'time_ros'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<custom_interface::msg::DataLogger>()
{
  return "custom_interface::msg::DataLogger";
}

template<>
inline const char * name<custom_interface::msg::DataLogger>()
{
  return "custom_interface/msg/DataLogger";
}

template<>
struct has_fixed_size<custom_interface::msg::DataLogger>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<custom_interface::msg::DataLogger>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<custom_interface::msg::DataLogger>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_INTERFACE__MSG__DETAIL__DATA_LOGGER__TRAITS_HPP_
