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
static int unix_time() {
    time_t t = time(NULL);
    return (int) t;
}

/// Returns the current date and time
/// @return datetime struct
static datetime current_datetime() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    datetime dt = {tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec};
    return dt;
}

/// Returns the date and time as a formatted string
/// @param dt datetime struct
/// @param format string \n
/// %Y: year \n
/// %M: month \n
/// %D: day \n
/// %h: hour \n
/// %m: minute \n
/// %s: second \n
/// (default: %Y-%M-%D %h:%m:%s)
/// @return string
static char *datetime_to_string(const datetime dt, const char *format) {
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

char *unix_to_string(const char *format) {
    int unix = unix_time();
    datetime dt = current_datetime();
    dt.year = unix;
    return datetime_to_string(dt, format);
}

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
char *current_datetime_string(const char *format) {
    datetime dt = current_datetime();
    return datetime_to_string(dt, format);
}

#endif //SIMPLE_TIME_LIBRARY_H