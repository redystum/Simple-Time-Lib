# Simple Time Library Documentation

The Simple Time Library is a C library for working with date and time data. It provides various functions for manipulating and formatting date and time values. Below, you'll find documentation for each function along with usage examples.

## Table of Contents

1. [Struct: `datetime`](#struct-datetime)
2. [Function: `int unix_time()`](#1-function-int-unixtime)
3. [Function: `datetime current_datetime()`](#2-function-datetime-currentdatetime)
4. [Function: `char *datetime_to_string(datetime dt, const char *format)`](#3-function-char-datetimetostringdatetime-dt-const-char-format)
5. [Function: `datetime unix_to_datetime(int unix)`](#4-function-datetime-unixtodatetimeint-unix)
6. [Function: `char *unix_to_string(int unix, const char *format)`](#5-function-char-unixtostringint-unix-const-char-format)
7. [Function: `char *current_datetime_string(const char *format)`](#6-function-char-currentdatetimestringconst-char-format)
8. [Function: `int datetime_to_unix(datetime dt)`](#7-function-int-datetimetounixdatetime-dt)
9. [Function: `int add_days(int unix, int days)`](#8-function-int-adddaysint-unix-int-days)
10. [Function: `int add_months(int unix, int months)`](#9-function-int-addmonthsint-unix-int-months)
11. [Function: `int add_years(int unix, int years)`](#10-function-int-addyearsint-unix-int-years)
12. [Function: `int add_hours(int unix, int hours)`](#11-function-int-addhoursint-unix-int-hours)
13. [Function: `int add_minutes(int unix, int minutes)`](#12-function-int-addminutesint-unix-int-minutes)
14. [Function: `int add_seconds(int unix, int seconds)`](#13-function-int-addsecondsint-unix-int-seconds)
15. [Function: `int subtract_days(int unix, int days)`](#14-function-int-subtractdaysint-unix-int-days)
16. [Function: `int subtract_months(int unix, int months)`](#15-function-int-subtractmonthsint-unix-int-months)
17. [Function: `int subtract_years(int unix, int years)`](#16-function-int-subtractyearsint-unix-int-years)
18. [Function: `int subtract_hours(int unix, int hours)`](#17-function-int-subtracthoursint-unix-int-hours)
19. [Function: `int subtract_minutes(int unix, int minutes)`](#18-function-int-subtractminutesint-unix-int-minutes)
20. [Function: `int subtract_seconds(int unix, int seconds)`](#19-function-int-subtractsecondsint-unix-int-seconds)
21. [Function: `bool is_leap_year(int year)`](#20-function-bool-isleapyearint-year)
22. [Function: `bool is_valid_datetime(datetime dt)`](#21-function-bool-isvaliddatetimedatetime-dt)
23. [Function: `bool compare_datetime(datetime dt1, datetime dt2)`](#22-function-bool-comparedatetimedatetime-dt1-datetime-dt2)
24. [Function: `bool compare_with_days_margin(datetime dt1, datetime dt2, int days)`](#23-function-bool-comparewithdaysmargindatetime-dt1-datetime-dt2-int-days)
25. [Function: `bool compare_with_months_margin(datetime dt1, datetime dt2, int months)`](#24-function-bool-comparewithmonthsmargindatetime-dt1-datetime-dt2-int-months)
26. [Function: `bool compare_with_years_margin(datetime dt1, datetime dt2, int years)`](#25-function-bool-comparewithyearsmargindatetime-dt1-datetime-dt2-int-years)
27. [Function: `bool compare_with_hours_margin(datetime dt1, datetime dt2, int hours)`](#26-function-bool-comparewithhoursmargindatetime-dt1-datetime-dt2-int-hours)
28. [Function: `bool compare_with_minutes_margin(datetime dt1, datetime dt2, int minutes)`](#27-function-bool-comparewithminutesmargindatetime-dt1-datetime-dt2-int-minutes)
29. [Function: `bool compare_with_seconds_margin(datetime dt1, datetime dt2, int seconds)`](#28-function-bool-comparewithsecondsmargindatetime-dt1-datetime-dt2-int-seconds)
30. [Function: `bool compare_with_days_margin_unix(int unix1, int unix2, int days)`](#29-function-bool-comparewithdaysmarginunixint-unix1-int-unix2-int-days)
31. [Function: `bool compare_with_months_margin_unix(int unix1, int unix2, int months)`](#30-function-bool-comparewithmonthsmarginunixint-unix1-int-unix2-int-months)
32. [Function: `bool compare_with_years_margin_unix(int unix1, int unix2, int years)`](#31-function-bool-comparewithyearsmarginunixint-unix1-int-unix2-int-years)
33. [Function: `bool compare_with_hours_margin_unix(int unix1, int unix2, int hours)`](#32-function-bool-comparewithhoursmarginunixint-unix1-int-unix2-int-hours)
34. [Function: `bool compare_with_minutes_margin_unix(int unix1, int unix2, int minutes)`](#33-function-bool-comparewithminutesmarginunixint-unix1-int-unix2-int-minutes)
35. [Function: `bool compare_with_seconds_margin_unix(int unix1, int unix2, int seconds)`](#34-function-bool-comparewithsecondsmarginunixint-unix1-int-unix2-int-seconds)
36. [Function: `int get_days_between_datetime(datetime dt1, datetime dt2)`](#35-function-int-getdaysbetweendatetimedatetime-dt1-datetime-dt2)
37. [Function: `int get_months_between_datetime(datetime dt1, datetime dt2)`](#36-function-int-getmonthsbetweendatetimedatetime-dt1-datetime-dt2)
38. [Function: `int get_years_between_datetime(datetime dt1, datetime dt2)`](#37-function-int-getyearsbetweendatetimedatetime-dt1-datetime-dt2)
39. [Function: `int get_hours_between_datetime(datetime dt1, datetime dt2)`](#38-function-int-gethoursbetweendatetimedatetime-dt1-datetime-dt2)
40. [Function: `int get_minutes_between_datetime(datetime dt1, datetime dt2)`](#39-function-int-getminutesbetweendatetimedatetime-dt1-datetime-dt2)
41. [Function: `int get_seconds_between_datetime(datetime dt1, datetime dt2)`](#40-function-int-getsecondsbetweendatetimedatetime-dt1-datetime-dt2)
42. [Function: `int get_days_between_unix(int unix1, int unix2)`](#41-function-int-getdaysbetweenunixint-unix1-int-unix2)
43. [Function: `int get_months_between_unix(int unix1, int unix2)`](#42-function-int-getmonthsbetweenunixint-unix1-int-unix2)
44. [Function: `int get_years_between_unix(int unix1, int unix2)`](#43-function-int-getyearsbetweenunixint-unix1-int-unix2)
45. [Function: `int get_hours_between_unix(int unix1, int unix2)`](#44-function-int-gethoursbetweenunixint-unix1-int-unix2)
46. [Function: `int get_minutes_between_unix(int unix1, int unix2)`](#45-function-int-getminutesbetweenunixint-unix1-int-unix2)
47. [Function: `int get_seconds_between_unix(int unix1, int unix2)`](#46-function-int-getsecondsbetweenunixint-unix1-int-unix2)


## Struct: `datetime`

The `datetime` struct represents a date and time in a specific format.

**Members**

- `int year`: The year portion of the date.
- `int month`: The month portion of the date (1-12).
- `int day`: The day portion of the date (1-31).
- `int hour`: The hour portion of the time (0-23).
- `int minute`: The minute portion of the time (0-59).
- `int second`: The second portion of the time (0-59).

**Usage**

You can create a `datetime` struct and initialize its members as follows:

```c
datetime dt;
dt.year = 2023;
dt.month = 11;
dt.day = 3;
dt.hour = 12;
dt.minute = 30;
dt.second = 0;
// or
datetime dt = {2023, 11, 3, 12, 30, 0};
```

**Example**

```c
datetime myDatetime;
myDatetime.year = 2023;
myDatetime.month = 11;
myDatetime.day = 3;
myDatetime.hour = 12;
myDatetime.minute = 30;
myDatetime.second = 0;

printf("Date and Time: %d-%02d-%02d %02d:%02d:%02d\n", myDatetime.year, myDatetime.month, myDatetime.day, myDatetime.hour, myDatetime.minute, myDatetime.second);
```

## 1. Function: `int unix_time()`

This function returns the current Unix timestamp in seconds since 1970.

**Example**:

```c
int currentUnixTime = unix_time();
printf("Current Unix timestamp: %d\n", currentUnixTime);
```

## 2. Function: `datetime current_datetime()`

This function returns the current date and time as a `datetime` structure.

**Example**:

```c
datetime currentDt = current_datetime();
printf("Current Date and Time: %d-%d-%d %d:%d:%d\n", currentDt.year, currentDt.month, currentDt.day, currentDt.hour, currentDt.minute, currentDt.second);
```

## 3. Function: `char *datetime_to_string(datetime dt, const char *format)`

This function converts a `datetime` structure to a formatted string based on the provided format.

**Example**:

```c
datetime dt = {2023, 11, 2, 14, 30, 0};
char *formattedString = datetime_to_string(dt, "%Y-%M-%D %h:%m:%s");
printf("Formatted Date and Time: %s\n", formattedString);
free(formattedString); // Don't forget to free the allocated memory.
```

## 4. Function: `datetime unix_to_datetime(int unix)`

This function converts a Unix timestamp to a `datetime` structure.

**Example**:

```c
int unixTimestamp = 1604515200; // November 4, 2020, 12:00:00 AM
datetime dt = unix_to_datetime(unixTimestamp);
printf("Date and Time from Unix Timestamp: %d-%d-%d %d:%d:%d\n", dt.year, dt.month, dt.day, dt.hour, dt.minute, dt.second);
```

## 5. Function: `char *unix_to_string(int unix, const char *format)`

This function converts a Unix timestamp to a formatted string based on the provided format.

**Example**:

```c
int unixTimestamp = 1604515200; // November 4, 2020, 12:00:00 AM
char *formattedString = unix_to_string(unixTimestamp, "%Y-%M-%D %h:%m:%s");
printf("Formatted Date and Time from Unix Timestamp: %s\n", formattedString);
free(formattedString); // Don't forget to free the allocated memory.
```

## 6. Function: `char *current_datetime_string(const char *format)`

This function returns the current date and time as a formatted string based on the provided format.

**Example**:

```c
char *formattedString = current_datetime_string("%Y-%M-%D %h:%m:%s");
printf("Current Date and Time (Formatted): %s\n", formattedString);
free(formattedString); // Don't forget to free the allocated memory.
```

## 7. Function: `int datetime_to_unix(datetime dt)`

This function converts a `datetime` structure to a Unix timestamp.

**Example**:

```c
datetime dt = {2023, 11, 2, 14, 30, 0};
int unixTimestamp = datetime_to_unix(dt);
printf("Unix Timestamp from Date and Time: %d\n", unixTimestamp);
```

## 8. Function: `int add_days(int unix, int days)`

This function adds a specified number of days to a Unix timestamp.

**Example**:

```c
int unixTimestamp = 1604515200; // November 4, 2020, 12:00:00 AM
int newUnixTimestamp = add_days(unixTimestamp, 5); // Add 5 days
printf("New Unix Timestamp after adding days: %d\n", newUnixTimestamp);
```

## 9. Function: `int add_months(int unix, int months)`

This function adds a specified number of months to a Unix timestamp.

**Example**:

```c
int unixTimestamp = 1604515200; // November 4, 2020, 12:00:00 AM
int newUnixTimestamp = add_months(unixTimestamp, 3); // Add 3 months
printf("New Unix Timestamp after adding months: %d\n", newUnixTimestamp);
```

## 10. Function: `int add_years(int unix, int years)`

This function adds a specified number of years to a Unix timestamp.

**Example**:

```c
int unixTimestamp = 1604515200; // November 4, 2020, 12:00:00 AM
int newUnixTimestamp = add_years(unixTimestamp, 2); // Add 2 years
printf("New Unix Timestamp after adding years: %d\n", newUnixTimestamp);
```

## 11. Function: `int add_hours(int unix, int hours)`

This function adds a specified number of hours to a Unix timestamp.

**Example**:

```c
int unixTimestamp = 1604515200; // November 4, 2020, 12:00:00 AM
int newUnixTimestamp = add_hours(unixTimestamp, 6); // Add 6 hours
printf("New Unix Timestamp after adding hours: %d\n", newUnixTimestamp);
```

## 12. Function: `int add_minutes(int unix, int minutes)`

This function adds a specified number of minutes to a Unix timestamp.

**Example**:

```c
int unixTimestamp = 1604515200; // November 4, 2020, 12:00:00 AM
int newUnixTimestamp = add_minutes(unixTimestamp, 30); // Add 30 minutes
printf("New Unix Timestamp after adding minutes: %d\n", newUnixTimestamp);
```

## 13. Function: `int add_seconds(int unix, int seconds)`

This function adds a specified number of seconds to a Unix timestamp.

**Example**:

```c
int unixTimestamp = 1604515200; // November 4, 2020, 12:00:00 AM
int newUnixTimestamp = add_seconds(unixTimestamp, 45); // Add 45 seconds
printf("New Unix Timestamp after adding seconds: %d\n", newUnixTimestamp);
```

## 14. Function: `int subtract_days(int unix, int days)`

This function subtracts a specified number of days from a Unix timestamp.

**Example**:

```c
int unixTimestamp = 1604515200; // November 4, 2020, 12:00:00 AM
int newUnixTimestamp = subtract_days(unixTimestamp, 2); // Subtract 2 days
printf("New Unix Timestamp after subtracting days: %d\n", newUnixTimestamp);
```

## 15. Function: `int subtract_months(int unix, int months)`

This function subtracts a specified number of months from a Unix timestamp.

**Example**:

```c
int unixTimestamp = 1604515200; // November 4, 2020, 12:00:00 AM
int newUnixTimestamp = subtract_months(unixTimestamp, 2); // Subtract 2 months
printf("New Unix Timestamp after subtracting months: %d\n", newUnixTimestamp);
```

## 16. Function: `int subtract_years(int unix, int years)`

This function subtracts a specified number of years from a Unix timestamp.

**Example**:

```c
int unixTimestamp = 1604515200; // November 4, 2020, 12:00:00 AM
int newUnixTimestamp = subtract_years(unixTimestamp, 1); // Subtract 1 year
printf("New Unix Timestamp after subtracting years: %d\n", newUnixTimestamp);
```

## 17. Function: `int subtract_hours(int unix, int hours)`

This function subtracts a specified number of hours from a Unix timestamp.

**Example**:

```c
int unixTimestamp = 1604515200; // November 4, 2020, 12:00:00 AM
int newUnixTimestamp = subtract_hours(unixTimestamp, 3); // Subtract 3 hours
printf("New Unix Timestamp after subtracting hours: %d\n", newUnixTimestamp);
```

## 18. Function: `int subtract_minutes(int unix, int minutes)`

This function subtracts a specified number of minutes from a Unix timestamp.

**Example**:

```c
int unixTimestamp = 1604515200; // November 4, 2020, 12:00:00 AM
int newUnixTimestamp = subtract_minutes(unixTimestamp, 15); // Subtract 15 minutes
printf("New Unix Timestamp after subtracting minutes: %d\n", newUnixTimestamp);
```

## 19. Function: `int subtract_seconds(int unix, int seconds)`

This function subtracts a specified number of seconds from a Unix timestamp.

**Example**:

```c
int unixTimestamp = 1604515200; // November 4, 2020, 12:00:00 AM
int newUnixTimestamp = subtract_seconds(unixTimestamp, 10); // Subtract 10 seconds
printf("New Unix Timestamp after subtracting seconds: %d\n", newUnixTimestamp);
```

## 20. Function: `bool is_leap_year(int year)`

This function checks if a given year is a leap year and returns `true` if it is.

**Example**:

```c
int year = 2024;
bool isLeapYear = is_leap_year(year);
if (isLeapYear) {
    printf("%d is a leap year.\n", year);
} else {
    printf("%d is not a leap year.\n", year);
}
```

## 21. Function: `bool is_valid_datetime(datetime dt)`

This function checks if a given `datetime` struct represents a valid date and time.

**Example**:

```c
datetime dt = {2023, 2, 30, 15, 45, 0}; // An invalid date
bool isValid = is_valid_datetime(dt);
if (isValid) {
    printf("The provided datetime is valid.\n");
} else {
    printf("The provided datetime is not valid.\n");
}
```

## 22. Function: `bool compare_datetime(datetime dt1, datetime dt2)`

This function compares two `datetime` structs and returns `true` if they are equal.

**Example**:

```c
datetime dt1 = {2023, 11, 3, 15, 30, 0};
datetime dt2 = {2023, 11, 3, 15, 30, 0};
bool areEqual = compare_datetime(dt1, dt2);
if (areEqual) {
    printf("The two datetime structs are equal.\n");
} else {
    printf("The two datetime structs are not equal.\n");
}
```

## 23. Function: `bool compare_with_days_margin(datetime dt1, datetime dt2, int days)`

This function compares two `datetime` structs with a specified margin of days and returns `true` if they are equal within that margin.

**Example**:

```c
datetime dt1 = {2023, 11, 3, 15, 0, 0};
datetime dt2 = {2023, 11, 5, 15, 0, 0};
int marginDays = 3;
bool areEqual = compare_with_days_margin(dt1, dt2, marginDays);
if (areEqual) {
    printf("The two datetime structs are equal within a %d-day margin.\n", marginDays);
} else {
    printf("The two datetime structs are not equal within a %d-day margin.\n", marginDays);
}
```

## 24. Function: `bool compare_with_months_margin(datetime dt1, datetime dt2, int months)`

This function compares two `datetime` structs with a specified margin of months and returns `true` if they are equal within that margin.

**Example**:

```c
datetime dt1 = {2023, 11, 3, 15, 0, 0};
datetime dt2 = {2023, 12, 3, 15, 0, 0};
int marginMonths = 2;
bool areEqual = compare_with_months_margin(dt1, dt2, marginMonths);
if (areEqual) {
    printf("The two datetime structs are equal within a %d-month margin.\n", marginMonths);
} else {
    printf("The two datetime structs are not equal within a %d-month margin.\n", marginMonths);
}
```

## 25. Function: `bool compare_with_years_margin(datetime dt1, datetime dt2, int years)`

This function compares two `datetime` structs with a specified margin of years and returns `true` if they are equal within that margin.

**Example**:

```c
datetime dt1 = {2023, 11, 3, 15, 0, 0};
datetime dt2 = {2025, 11, 3, 15, 0, 0};
int marginYears = 1;
bool areEqual = compare_with_years_margin(dt1, dt2, marginYears);
if (areEqual) {
    printf("The two datetime structs are equal within a %d-year margin.\n", marginYears);
} else {
    printf("The two datetime structs are not equal within a %d-year margin.\n", marginYears);
}
```

## 26. Function: `bool compare_with_hours_margin(datetime dt1, datetime dt2, int hours)`

This function compares two `datetime` structs with a specified margin of hours and returns `true` if they are equal within that margin.

**Example**:

```c
datetime dt1 = {2023, 11, 3, 15, 0, 0};
datetime dt2 = {2023, 11, 3, 16, 0, 0};
int marginHours = 1;
bool areEqual = compare_with_hours_margin(dt1, dt2, marginHours);
if (areEqual) {
    printf("The two datetime structs are equal within a %d-hour margin.\n", marginHours);
} else {
    printf("The two datetime structs are not equal within a %d-hour margin.\n", marginHours);
}
```

## 27. Function: `bool compare_with_minutes_margin(datetime dt1, datetime dt2, int minutes)`

This function compares two `datetime` structs with a specified margin of minutes and returns `true` if they are equal within that margin.

**Example**:

```c
datetime dt1 = {2023, 11, 3, 15, 30, 0};
datetime dt2 = {2023, 11, 3, 15, 35, 0};
int marginMinutes = 5;
bool areEqual = compare_with_minutes_margin(dt1, dt2, marginMinutes);
if (areEqual) {
    printf("The two datetime structs are equal within a %d-minute margin.\n", marginMinutes);
} else {
    printf("The two datetime structs are not equal within a %d-minute margin.\n", marginMinutes);
}
```

## 28. Function: `bool compare_with_seconds_margin(datetime dt1, datetime dt2, int seconds)`

This function compares two `datetime` structs with a specified margin of seconds and returns `true` if they are equal within that margin.

**Example**:

```c
datetime dt1 = {2023, 11, 3, 15, 30, 20};
datetime dt2 = {2023, 11, 3, 15, 30, 25};
int marginSeconds = 5;
bool areEqual = compare_with_seconds_margin(dt1, dt2, marginSeconds);
if (areEqual) {
    printf("The two datetime structs are equal within a %d-second margin.\n", marginSeconds);
} else {
    printf("The two datetime structs are not equal within a %d-second margin.\n", marginSeconds);
}
```

## 29. Function: `bool compare_with_days_margin_unix(int unix1, int unix2, int days)`

This function compares two Unix timestamps with a specified margin of days and returns `true` if they are equal within that margin.

**Example**:

```c
int unixTimestamp1 = 1604515200; // November 4, 2020, 12:00:00 AM
int unixTimestamp2 = 1604688000; // November 5, 2020, 12:00:00 AM
int marginDays = 2;
bool areEqual = compare_with_days_margin_unix(unixTimestamp1, unixTimestamp2, marginDays);
if (areEqual) {
    printf("The two Unix timestamps are equal within a %d-day margin.\n", marginDays);
} else {
    printf("The two Unix timestamps are not equal within a %d-day margin.\n", marginDays);
}
```

## 30. Function: `bool compare_with_months_margin_unix(int unix1, int unix2, int months)`

This function compares two Unix timestamps with a specified margin of months and returns `true` if they are equal within that margin.

**Example**:

```c
int unixTimestamp1 = 1604515200; // November 4, 2020, 12:00:00 AM
int unixTimestamp2 = 1612108800; // January 31, 2021, 12:00:00 AM
int marginMonths = 2;
bool areEqual = compare_with_months_margin_unix(unixTimestamp1, unixTimestamp2, marginMonths);
if (areEqual) {
    printf("The two Unix timestamps are equal within a %d-month margin.\n", marginMonths);
} else {
    printf("The two Unix timestamps are not equal within a %d-month margin.\n", marginMonths);
}
```

## 31. Function: `bool compare_with_years_margin_unix(int unix1, int unix2, int years)`

This function compares two Unix timestamps with a specified margin of years and returns `true` if they are equal within that margin.

**Example**:

```c
int unixTimestamp1 = 1604515200; // November 4, 2020, 12:00:00 AM
int unixTimestamp2 = 1636051200; // November 4, 2023, 12:00:00 AM
int marginYears = 2;
bool areEqual = compare_with_years_margin_unix(unixTimestamp1, unixTimestamp2, marginYears);
if (areEqual) {
    printf("The two Unix timestamps are equal within a %d-year margin.\n", marginYears);
} else {
    printf("The two Unix timestamps are not equal within a %d-year margin.\n", marginYears);
}
```

## 32. Function: `bool compare_with_hours_margin_unix(int unix1, int unix2, int hours)`

This function compares two Unix timestamps with a specified margin of hours and returns `true` if they are equal within that margin.

**Example**:

```c
int unixTimestamp1 = 1604515200; // November 4, 2020, 12:00:00 AM
int unixTimestamp2 = 1604587200; // November 4, 2020, 10:00:00 AM
int marginHours = 2;
bool areEqual = compare_with_hours_margin_unix(unixTimestamp1, unixTimestamp2, marginHours);
if (areEqual) {
    printf("The two Unix timestamps are equal within a %d-hour margin.\n", marginHours);
} else {
    printf("The two Unix timestamps are not equal within a %d-hour margin.\n", marginHours);
}
```

## 33. Function: `bool compare_with_minutes_margin_unix(int unix1, int unix2, int minutes)`

This function compares two Unix timestamps with a specified margin of minutes and returns `true` if they are equal within that margin.

**Example**:

```c
int unixTimestamp1 = 1604515200; // November 4, 2020, 12:00:00 AM
int unixTimestamp2 = 1604517000; // November 4, 2020, 12:30:00 AM
int marginMinutes = 30;
bool areEqual = compare_with_minutes_margin_unix(unixTimestamp1, unixTimestamp2, marginMinutes);
if (areEqual) {
    printf("The two Unix timestamps are equal within a %d-minute margin.\n", marginMinutes);
} else {
    printf("The two Unix timestamps are not equal within a %d-minute margin.\n", marginMinutes);
}
```

## 34. Function: `bool compare_with_seconds_margin_unix(int unix1, int unix2, int seconds)`

This function compares two Unix timestamps with a specified margin of seconds and returns `true` if they are equal within that margin.

**Example**:

```c
int unixTimestamp1 = 1604515200; // November 4, 2020, 12:00:00 AM
int unixTimestamp2 = 1604515245; // November 4, 2020, 12:00:45 AM
int marginSeconds = 60;
bool areEqual = compare_with_seconds_margin_unix(unixTimestamp1, unixTimestamp2, marginSeconds);
if (areEqual) {
    printf("The two Unix timestamps are equal within a %d-second margin.\n", marginSeconds);
} else {
    printf("The two Unix timestamps are not equal within a %d-second margin.\n", marginSeconds);
}
```

## 35. Function: `int get_days_between_datetime(datetime dt1, datetime dt2)`

This function calculates the number of days between two `datetime` structs.

**Example**:

```c
datetime dt1 = {2023, 11, 1, 0, 0, 0};
datetime dt2 = {2023, 11, 5, 0, 0, 0};
int daysBetween = get_days_between_datetime(dt1, dt2);
printf("There are %d days between the two datetime structs.\n", daysBetween);
```

## 36. Function: `int get_months_between_datetime(datetime dt1, datetime dt2)`

This function calculates the number of months between two `datetime` structs.

**Example**:

```c
datetime dt1 = {2023, 11, 1, 0, 0, 0};
datetime dt2 = {2024, 1, 1, 0, 0, 0};
int monthsBetween = get_months_between_datetime(dt1, dt2);
printf("There are %d months between the two datetime structs.\n", monthsBetween);
```

## 37. Function: `int get_years_between_datetime(datetime dt1, datetime dt2)`

This function calculates the number of years between two `datetime` structs.

**Example**:

```c
datetime dt1 = {2020, 11, 1, 0, 0, 0};
datetime dt2 = {2023, 11, 1, 0, 0, 0};
int yearsBetween = get_years_between_datetime(dt1, dt2);
printf("There are %d years between the two datetime structs.\n", yearsBetween);
```

## 38. Function: `int get_hours_between_datetime(datetime dt1, datetime dt2)`

This function calculates the number of hours between two `datetime` structs.

**Example**:

```c
datetime dt1 = {2023, 11, 3, 12, 0, 0};
datetime dt2 = {2023, 11, 3, 18, 0, 0};
int hoursBetween = get_hours_between_datetime(dt1, dt2);
printf("There are %d hours between the two datetime structs.\n", hoursBetween);
```

## 39. Function: `int get_minutes_between_datetime(datetime dt1, datetime dt2)`

This function calculates the number of minutes between two `datetime` structs.

**Example**:

```c
datetime dt1 = {2023, 11, 3, 12, 0, 0};
datetime dt2 = {2023, 11, 3, 12, 30, 0};
int minutesBetween = get_minutes_between_datetime(dt1, dt2);
printf("There are %d minutes between the two datetime structs.\n", minutesBetween);
```

## 40. Function: `int get_seconds_between_datetime(datetime dt1, datetime dt2)`

This function calculates the number of seconds between two `datetime` structs.

**Example**:

```c
datetime dt1 = {2023, 11, 3, 12, 0, 0};
datetime dt2 = {2023, 11, 3, 12, 0, 45};
int secondsBetween = get_seconds_between_datetime(dt1, dt2);
printf("There are %d seconds between the two datetime structs.\n", secondsBetween);
```

## 41. Function: `int get_days_between_unix(int unix1, int unix2)`

This function calculates the number of days between two Unix timestamps.

**Example**:

```c
int unixTimestamp1 = 1604515200; // November 4, 2020, 12:00:00 AM
int unixTimestamp2 = 1604688000; // November 5, 2020, 12:00:00 AM
int daysBetween = get_days_between_unix(unixTimestamp1, unixTimestamp2);
printf("There are %d days between the two Unix timestamps.\n", daysBetween);
```

## 42. Function: `int get_months_between_unix(int unix1, int unix2)`

This function calculates the number of months between two Unix timestamps.

**Example**:

```c
int unixTimestamp1 = 1604515200; // November 4, 2020, 12:00:

00 AM
int unixTimestamp2 = 1612108800; // January 31, 2021, 12:00:00 AM
int monthsBetween = get_months_between_unix(unixTimestamp1, unixTimestamp2);
printf("There are %d months between the two Unix timestamps.\n", monthsBetween);
```

## 43. Function: `int get_years_between_unix(int unix1, int unix2)`

This function calculates the number of years between two Unix timestamps.

**Example**:

```c
int unixTimestamp1 = 1604515200; // November 4, 2020, 12:00:00 AM
int unixTimestamp2 = 1636051200; // November 4, 2023, 12:00:00 AM
int yearsBetween = get_years_between_unix(unixTimestamp1, unixTimestamp2);
printf("There are %d years between the two Unix timestamps.\n", yearsBetween);
```

## 44. Function: `int get_hours_between_unix(int unix1, int unix2)`

This function calculates the number of hours between two Unix timestamps.

**Example**:

```c
int unixTimestamp1 = 1604515200; // November 4, 2020, 12:00:00 AM
int unixTimestamp2 = 1604587200; // November 4, 2020, 10:00:00 AM
int hoursBetween = get_hours_between_unix(unixTimestamp1, unixTimestamp2);
printf("There are %d hours between the two Unix timestamps.\n", hoursBetween);
```

## 45. Function: `int get_minutes_between_unix(int unix1, int unix2)`

This function calculates the number of minutes between two Unix timestamps.

**Example**:

```c
int unixTimestamp1 = 1604515200; // November 4, 2020, 12:00:00 AM
int unixTimestamp2 = 1604517000; // November 4, 2020, 12:30:00 AM
int minutesBetween = get_minutes_between_unix(unixTimestamp1, unixTimestamp2);
printf("There are %d minutes between the two Unix timestamps.\n", minutesBetween);
```

## 46. Function: `int get_seconds_between_unix(int unix1, int unix2)`

This function calculates the number of seconds between two Unix timestamps.

**Example**:

```c
int unixTimestamp1 = 1604515200; // November 4, 2020, 12:00:00 AM
int unixTimestamp2 = 1604515245; // November 4, 2020, 12:00:45 AM
int secondsBetween = get_seconds_between_unix(unixTimestamp1, unixTimestamp2);
printf("There are %d seconds between the two Unix timestamps.\n", secondsBetween);
```

##
Documentation generated by [ChatGPT](https://chat.openai.com/) :)