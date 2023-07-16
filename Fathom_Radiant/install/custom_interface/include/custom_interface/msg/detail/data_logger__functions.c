// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from custom_interface:msg/DataLogger.idl
// generated code does not contain a copyright notice
#include "custom_interface/msg/detail/data_logger__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `time_ros`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
custom_interface__msg__DataLogger__init(custom_interface__msg__DataLogger * msg)
{
  if (!msg) {
    return false;
  }
  // longitude
  // latitude
  // altitude
  // time_ros
  if (!builtin_interfaces__msg__Time__init(&msg->time_ros)) {
    custom_interface__msg__DataLogger__fini(msg);
    return false;
  }
  // actual_speed
  return true;
}

void
custom_interface__msg__DataLogger__fini(custom_interface__msg__DataLogger * msg)
{
  if (!msg) {
    return;
  }
  // longitude
  // latitude
  // altitude
  // time_ros
  builtin_interfaces__msg__Time__fini(&msg->time_ros);
  // actual_speed
}

bool
custom_interface__msg__DataLogger__are_equal(const custom_interface__msg__DataLogger * lhs, const custom_interface__msg__DataLogger * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // longitude
  if (lhs->longitude != rhs->longitude) {
    return false;
  }
  // latitude
  if (lhs->latitude != rhs->latitude) {
    return false;
  }
  // altitude
  if (lhs->altitude != rhs->altitude) {
    return false;
  }
  // time_ros
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->time_ros), &(rhs->time_ros)))
  {
    return false;
  }
  // actual_speed
  if (lhs->actual_speed != rhs->actual_speed) {
    return false;
  }
  return true;
}

bool
custom_interface__msg__DataLogger__copy(
  const custom_interface__msg__DataLogger * input,
  custom_interface__msg__DataLogger * output)
{
  if (!input || !output) {
    return false;
  }
  // longitude
  output->longitude = input->longitude;
  // latitude
  output->latitude = input->latitude;
  // altitude
  output->altitude = input->altitude;
  // time_ros
  if (!builtin_interfaces__msg__Time__copy(
      &(input->time_ros), &(output->time_ros)))
  {
    return false;
  }
  // actual_speed
  output->actual_speed = input->actual_speed;
  return true;
}

custom_interface__msg__DataLogger *
custom_interface__msg__DataLogger__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interface__msg__DataLogger * msg = (custom_interface__msg__DataLogger *)allocator.allocate(sizeof(custom_interface__msg__DataLogger), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_interface__msg__DataLogger));
  bool success = custom_interface__msg__DataLogger__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_interface__msg__DataLogger__destroy(custom_interface__msg__DataLogger * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_interface__msg__DataLogger__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_interface__msg__DataLogger__Sequence__init(custom_interface__msg__DataLogger__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interface__msg__DataLogger * data = NULL;

  if (size) {
    data = (custom_interface__msg__DataLogger *)allocator.zero_allocate(size, sizeof(custom_interface__msg__DataLogger), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_interface__msg__DataLogger__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_interface__msg__DataLogger__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
custom_interface__msg__DataLogger__Sequence__fini(custom_interface__msg__DataLogger__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      custom_interface__msg__DataLogger__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

custom_interface__msg__DataLogger__Sequence *
custom_interface__msg__DataLogger__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interface__msg__DataLogger__Sequence * array = (custom_interface__msg__DataLogger__Sequence *)allocator.allocate(sizeof(custom_interface__msg__DataLogger__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_interface__msg__DataLogger__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_interface__msg__DataLogger__Sequence__destroy(custom_interface__msg__DataLogger__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_interface__msg__DataLogger__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_interface__msg__DataLogger__Sequence__are_equal(const custom_interface__msg__DataLogger__Sequence * lhs, const custom_interface__msg__DataLogger__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_interface__msg__DataLogger__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_interface__msg__DataLogger__Sequence__copy(
  const custom_interface__msg__DataLogger__Sequence * input,
  custom_interface__msg__DataLogger__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_interface__msg__DataLogger);
    custom_interface__msg__DataLogger * data =
      (custom_interface__msg__DataLogger *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_interface__msg__DataLogger__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          custom_interface__msg__DataLogger__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!custom_interface__msg__DataLogger__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
