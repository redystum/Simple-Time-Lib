# Simple Time Library

A C library for working with date and time, providing various functions for manipulating and formatting date and time data. This library allows you to perform a wide range of operations on date and time values, such as converting between Unix timestamps and datetime structures, adding or subtracting time intervals, and comparing dates with various levels of precision.

**Author**: redystum
**Version**: 1.0
**Date**: November 2, 2023

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Getting Started](#getting-started)
- [Usage Examples](#usage-examples)
- [Contributing](#contributing)
- [License](#license)

## Introduction

The Simple Time Library is designed to simplify date and time manipulation in C programs. It provides a wide range of functions to work with date and time data, making it easier to perform operations such as formatting, comparison, and arithmetic calculations.

## Features

- Convert between Unix timestamps and datetime structures.
- Format datetime values as strings with customizable formatting.
- Add or subtract days, months, years, hours, minutes, and seconds from Unix timestamps.
- Check if a given year is a leap year.
- Compare datetime values with various levels of precision.
- Calculate the difference in days, months, years, hours, minutes, or seconds between two datetime values or Unix timestamps.

## Getting Started

To use the Simple Time Library in your project, follow these steps:

1. Clone the repository or download the source code files.
2. Include the "simple_time_lib.h" header file in your C program.
3. Compile your program with the library.

Make sure you have a C development environment set up on your system before using this library.

## Usage Examples

Below are some usage examples to demonstrate how to use the library functions:

```c
#include "simple_time_lib.h"

int main() {
    // Get the current Unix timestamp
    int currentUnixTime = unix_time();

    // Get the current datetime as a formatted string
    char* currentDatetimeString = current_datetime_string("%Y-%M-%D %h:%m:%s");

    // Convert a Unix timestamp to a datetime structure
    datetime dt = unix_to_datetime(currentUnixTime);

    // Add 3 days to a Unix timestamp
    int newUnixTime = add_days(currentUnixTime, 3);

    // Check if a year is a leap year
    bool isLeap = is_leap_year(2024);

    // Compare two datetime structures with a margin of 2 days
    bool areEqual = compare_with_days_margin(dt1, dt2, 2);

    // Get the number of days between two datetime structures
    int daysDifference = get_days_between_datetime(dt1, dt2);

    return 0;
}
```

## Contributing

Contributions to the Simple Time Library are welcome! If you have ideas for improvements, bug fixes, or new features, feel free to open an issue or create a pull request in the GitHub repository.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.