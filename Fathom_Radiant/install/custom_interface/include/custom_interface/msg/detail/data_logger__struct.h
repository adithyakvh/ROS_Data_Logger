// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interface:msg/DataLogger.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACE__MSG__DETAIL__DATA_LOGGER__STRUCT_H_
#define CUSTOM_INTERFACE__MSG__DETAIL__DATA_LOGGER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'time_ros'
#include "builtin_interfaces/msg/detail/time__struct.h"

// Struct defined in msg/DataLogger in the package custom_interface.
typedef struct custom_interface__msg__DataLogger
{
  float longitude;
  float latitude;
  float altitude;
  builtin_interfaces__msg__Time time_ros;
  float actual_speed;
} custom_interface__msg__DataLogger;

// Struct for a sequence of custom_interface__msg__DataLogger.
typedef struct custom_interface__msg__DataLogger__Sequence
{
  custom_interface__msg__DataLogger * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interface__msg__DataLogger__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACE__MSG__DETAIL__DATA_LOGGER__STRUCT_H_
