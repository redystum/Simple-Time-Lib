//
// Created by redystum on 02/11/2023.
//

#ifndef SIMPLE_TIME_LIBRARY_H
#define SIMPLE_TIME_LIBRARY_H

#include <stdio.h>
#include <time.h>
#include <malloc.h>
#include <string.h>

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


int unix_time() {
    time_t t = time(NULL);
    return (int) t;
}

datetime current_datetime() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    datetime dt = {tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec};
    return dt;
}

char *datetime_to_string(const datetime dt, const char *format) {
    if (format == NULL || format[0] == '\0') {
        char *str = malloc(20 * sizeof(char));
        sprintf(str, "%d-%d-%d %d:%d:%d", dt.year, dt.month, dt.day, dt.hour, dt.minute, dt.second);
        return str;
    }

    char *str = malloc(strlen(format) * sizeof(char));
    int i = 0;
    int j = 0;
    while (format[i] != '\0') {
        if (format[i] == '%') {
            switch (format[i + 1]) {
                case 'Y':
                    j += sprintf(str + j, "%d", dt.year);
                    break;
                case 'M':
                    j += sprintf(str + j, "%d", dt.month);
                    break;
                case 'D':
                    j += sprintf(str + j, "%d", dt.day);
                    break;
                case 'h':
                    j += sprintf(str + j, "%d", dt.hour);
                    break;
                case 'm':
                    j += sprintf(str + j, "%d", dt.minute);
                    break;
                case 's':
                    j += sprintf(str + j, "%d", dt.second);
                    break;
                default:
                    str[j] = format[i];
                    j++;
                    break;
            }
            i += 2;
        } else {
            str[j] = format[i];
            i++;
            j++;
        }
    }

    str[j] = '\0';
    return str;
}

datetime unix_to_datetime(const int unix) {
    time_t t = unix;
    struct tm tm = *localtime(&t);
    datetime dt = {tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec};
    return dt;
}

char *unix_to_string(const int unix, const char *format) {
    datetime dt = unix_to_datetime(unix);
    return datetime_to_string(dt, format);
}

char *current_datetime_string(const char *format) {
    datetime dt = current_datetime();
    return datetime_to_string(dt, format);
}

int datetime_to_unix(const datetime dt) {
    struct tm tm = {dt.second, dt.minute, dt.hour, dt.day, dt.month - 1, dt.year - 1900};
    time_t t = mktime(&tm);
    return (int) t;
}

int add_days(const int unix, const int days) {
    datetime dt = unix_to_datetime(unix);
    dt.day += days;
    return datetime_to_unix(dt);
}

int add_months(const int unix, const int months) {
    datetime dt = unix_to_datetime(unix);
    dt.month += months;
    return datetime_to_unix(dt);
}

int add_years(const int unix, const int years) {
    datetime dt = unix_to_datetime(unix);
    dt.year += years;
    return datetime_to_unix(dt);
}

int add_hours(const int unix, const int hours) {
    datetime dt = unix_to_datetime(unix);
    dt.hour += hours;
    return datetime_to_unix(dt);
}

int add_minutes(const int unix, const int minutes) {
    datetime dt = unix_to_datetime(unix);
    dt.minute += minutes;
    return datetime_to_unix(dt);
}

int add_seconds(const int unix, const int seconds) {
    datetime dt = unix_to_datetime(unix);
    dt.second += seconds;
    return datetime_to_unix(dt);
}

int subtract_days(const int unix, const int days) {
    datetime dt = unix_to_datetime(unix);
    dt.day -= days;
    return datetime_to_unix(dt);
}

int subtract_months(const int unix, const int months) {
    datetime dt = unix_to_datetime(unix);
    dt.month -= months;
    return datetime_to_unix(dt);
}

int subtract_years(const int unix, const int years) {
    datetime dt = unix_to_datetime(unix);
    dt.year -= years;
    return datetime_to_unix(dt);
}

int subtract_hours(const int unix, const int hours) {
    datetime dt = unix_to_datetime(unix);
    dt.hour -= hours;
    return datetime_to_unix(dt);
}

int subtract_minutes(const int unix, const int minutes) {
    datetime dt = unix_to_datetime(unix);
    dt.minute -= minutes;
    return datetime_to_unix(dt);
}

int subtract_seconds(const int unix, const int seconds) {
    datetime dt = unix_to_datetime(unix);
    dt.second -= seconds;
    return datetime_to_unix(dt);
}


#endif //SIMPLE_TIME_LIBRARY_H
