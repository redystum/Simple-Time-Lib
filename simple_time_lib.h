//
// Created by redystum on 02/11/2023.
//

#ifndef SIMPLE_TIME_SIMPLE_TIME_LIB_H
#define SIMPLE_TIME_SIMPLE_TIME_LIB_H

#include <stdbool.h>

/// A struct to hold a date and time
/// @param  year
/// @param month
/// @param day
/// @param hour
/// @param minute
/// @param second
typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} datetime;

/// Returns the current unix time
/// @return time in seconds since 1970
int unix_time();

/// Returns the current date and time
/// @return datetime struct
datetime current_datetime();

/// Returns the date and time as a formatted string
/// @param datetime struct
/// @param format string \n
/// %Y: year \n
/// %M: month \n
/// %D: day \n
/// %h: hour \n
/// %m: minute \n
/// %s: second \n
/// (default: %Y-%M-%D %h:%m:%s)
/// @return string
char *datetime_to_string(datetime dt, const char *format);

/// Returns the unix time as a formatted string
/// @param unix time in seconds since 1970
/// @return datetime struct
datetime unix_to_datetime(int unix);

/// Returns the unix time as a formatted string
/// @param unix time in seconds since 1970
/// @param format string \n
/// %Y: year \n
/// %M: month \n
/// %D: day \n
/// %h: hour \n
/// %m: minute \n
/// %s: second \n
/// (default: %Y-%M-%D %h:%m:%s)
/// @return string
char *unix_to_string(int unix, const char *format);

/// Returns the current date and time as a formatted string
/// @param format string \n
/// %Y: year \n
/// %M: month \n
/// %D: day \n
/// %h: hour \n
/// %m: minute \n
/// %s: second \n
/// (default: %Y-%M-%D %h:%m:%s)
/// @return string
char *current_datetime_string(const char *format);

/// Converts a datetime struct to unix time
/// @param datetime struct
/// @return unix time in seconds since 1970
int datetime_to_unix(datetime dt);

/// Adds days to a unix time
/// @param unix time in seconds since 1970
/// @param days
/// @return unix time in seconds since 1970
int add_days(int unix, int days);

/// Adds months to a unix time
/// @param unix time in seconds since 1970
/// @param months
/// @return unix time in seconds since 1970
int add_months(int unix, int months);

/// Adds years to a unix time
/// @param unix time in seconds since 1970
/// @param years
/// @return unix time in seconds since 1970
int add_years(int unix, int years);

/// Adds hours to a unix time
/// @param unix time in seconds since 1970
/// @param hours
/// @return unix time in seconds since 1970
int add_hours(int unix, int hours);

/// Adds minutes to a unix time
/// @param unix time in seconds since 1970
/// @param minutes
/// @return unix time in seconds since 1970
int add_minutes(int unix, int minutes);

/// Adds seconds to a unix time
/// @param unix time in seconds since 1970
/// @param seconds
/// @return unix time in seconds since 1970
int add_seconds(int unix, int seconds);

/// Subtracts days from a unix time
/// @param unix time in seconds since 1970
/// @param days
/// @return unix time in seconds since 1970
int subtract_days(int unix, int days);

/// Subtracts months from a unix time
/// @param unix time in seconds since 1970
/// @param months
/// @return unix time in seconds since 1970
int subtract_months(int unix, int months);

/// Subtracts years from a unix time
/// @param unix time in seconds since 1970
/// @param years
/// @return unix time in seconds since 1970
int subtract_years(int unix, int years);

/// Subtracts hours from a unix time
/// @param unix time in seconds since 1970
/// @param hours
/// @return unix time in seconds since 1970
int subtract_hours(int unix, int hours);

/// Subtracts minutes from a unix time
/// @param unix time in seconds since 1970
/// @param minutes
/// @return unix time in seconds since 1970
int subtract_minutes(int unix, int minutes);

/// Subtracts seconds from a unix time
/// @param unix time in seconds since 1970
/// @param seconds
/// @return unix time in seconds since 1970
int subtract_seconds(int unix, int seconds);

/// Checks if a year is a leap year
/// @param year
/// @return true if leap year
bool is_leap_year(int year);

/// Checks if a datetime struct is valid
/// @param datetime struct
/// @return true if valid
bool is_valid_datetime(datetime dt);

/// Compares two datetime structs
/// @param datetime struct 1
/// @param datetime struct 2
/// @return true if equal
bool compare_datetime(datetime dt1, datetime dt2);

/// Compares two datetime structs with a margin of days
/// @param datetime struct 1
/// @param datetime struct 2
/// @param days
/// @return true if equal
bool compare_with_days_margin(datetime dt1, datetime dt2, int days);

/// Compares two datetime structs with a margin of months
/// @param datetime struct 1
/// @param datetime struct 2
/// @param months
/// @return true if equal
bool compare_with_months_margin(datetime dt1, datetime dt2, int months);

/// Compares two datetime structs with a margin of years
/// @param datetime struct 1
/// @param datetime struct 2
/// @param years
/// @return true if equal
bool compare_with_years_margin(datetime dt1, datetime dt2, int years);

/// Compares two datetime structs with a margin of hours
/// @param datetime struct 1
/// @param datetime struct 2
/// @param hours
/// @return true if equal
bool compare_with_hours_margin(datetime dt1, datetime dt2, int hours);

/// Compares two datetime structs with a margin of minutes
/// @param datetime struct 1
/// @param datetime struct 2
/// @param minutes
/// @return true if equal
bool compare_with_minutes_margin(datetime dt1, datetime dt2, int minutes);

/// Compares two datetime structs with a margin of seconds
/// @param datetime struct 1
/// @param datetime struct 2
/// @param seconds
/// @return true if equal
bool compare_with_seconds_margin(datetime dt1, datetime dt2, int seconds);

/// Compares two unix times with a margin of days
/// @param unix time 1
/// @param unix time 2
/// @param days
/// @return true if equal
bool compare_with_days_margin_unix(int unix1, int unix2, int days);

/// Compares two unix times with a margin of months
/// @param unix time 1
/// @param unix time 2
/// @param months
/// @return true if equal
bool compare_with_months_margin_unix(int unix1, int unix2, int months);

/// Compares two unix times with a margin of years
/// @param unix time 1
/// @param unix time 2
/// @param years
/// @return true if equal
bool compare_with_years_margin_unix(int unix1, int unix2, int years);

/// Compares two unix times with a margin of hours
/// @param unix time 1
/// @param unix time 2
/// @param hours
/// @return true if equal
bool compare_with_hours_margin_unix(int unix1, int unix2, int hours);

/// Compares two unix times with a margin of minutes
/// @param unix time 1
/// @param unix time 2
/// @param minutes
/// @return true if equal
bool compare_with_minutes_margin_unix(int unix1, int unix2, int minutes);

/// Compares two unix times with a margin of seconds
/// @param unix time 1
/// @param unix time 2
/// @param seconds
/// @return true if equal
bool compare_with_seconds_margin_unix(int unix1, int unix2, int seconds);

/// Returns the number of days between two datetime structs
/// @param datetime struct 1
/// @param datetime struct 2
/// @return number of days
int get_days_between_datetime(datetime dt1, datetime dt2);

/// Returns the number of months between two datetime structs
/// @param datetime struct 1
/// @param datetime struct 2
/// @return number of months
int get_months_between_datetime(datetime dt1, datetime dt2);

/// Returns the number of years between two datetime structs
/// @param datetime struct 1
/// @param datetime struct 2
/// @return number of years
int get_years_between_datetime(datetime dt1, datetime dt2);

/// Returns the number of hours between two datetime structs
/// @param datetime struct 1
/// @param datetime struct 2
/// @return number of hours
int get_hours_between_datetime(datetime dt1, datetime dt2);

/// Returns the number of minutes between two datetime structs
/// @param datetime struct 1
/// @param datetime struct 2
/// @return number of minutes
int get_minutes_between_datetime(datetime dt1, datetime dt2);

/// Returns the number of seconds between two datetime structs
/// @param datetime struct 1
/// @param datetime struct 2
/// @return number of seconds
int get_seconds_between_datetime(datetime dt1, datetime dt2);

/// Returns the number of days between two unix times
/// @param unix time 1
/// @param unix time 2
/// @return number of days
int get_days_between_unix(int unix1, int unix2);

/// Returns the number of months between two unix times
/// @param unix time 1
/// @param unix time 2
/// @return number of months
int get_months_between_unix(int unix1, int unix2);

/// Returns the number of years between two unix times
/// @param unix time 1
/// @param unix time 2
/// @return number of years
int get_years_between_unix(int unix1, int unix2);

/// Returns the number of hours between two unix times
/// @param unix time 1
/// @param unix time 2
/// @return number of hours
int get_hours_between_unix(int unix1, int unix2);

/// Returns the number of minutes between two unix times
/// @param unix time 1
/// @param unix time 2
/// @return number of minutes
int get_minutes_between_unix(int unix1, int unix2);

/// Returns the number of seconds between two unix times
/// @param unix time 1
/// @param unix time 2
/// @return number of seconds
int get_seconds_between_unix(int unix1, int unix2);

#endif //SIMPLE_TIME_SIMPLE_TIME_LIB_H
