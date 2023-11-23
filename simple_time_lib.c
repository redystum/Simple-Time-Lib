//
// Created by rffar on 23/11/2023.
//

#include <stdio.h>
#include <time.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>

#include "simple_time_lib.h"

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
    if (!is_valid_datetime(dt)) return NULL;

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
    if (!is_valid_datetime(dt)) return -1;

    if (dt.year < 1970) {
        return -1;
    }
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

bool is_leap_year(const int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

bool is_valid_datetime(const datetime dt) {
    if (dt.year < 0 || dt.month <= 0 || dt.month > 12 || dt.day <= 0 || dt.day > 31 || dt.hour < 0 || dt.hour > 23 ||
        dt.minute < 0 || dt.minute > 59 || dt.second < 0 || dt.second > 59) {
        return false;
    }

    if (dt.month == 2) {
        if (is_leap_year(dt.year)) {
            return dt.day <= 29;
        } else {
            return dt.day <= 28;
        }
    }

    if (dt.month == 4 || dt.month == 6 || dt.month == 9 || dt.month == 11) {
        return dt.day <= 30;
    }

    return true;
}

bool compare_datetime(const datetime dt1, const datetime dt2) {
    return dt1.year == dt2.year && dt1.month == dt2.month && dt1.day == dt2.day && dt1.hour == dt2.hour &&
           dt1.minute == dt2.minute && dt1.second == dt2.second;
}

bool compare_with_days_margin(const datetime dt1, const datetime dt2, const int days) {
    int unix1 = datetime_to_unix(dt1);
    int unix2 = datetime_to_unix(dt2);
    return unix1 - days * 86400 <= unix2 && unix1 + days * 86400 >= unix2;
}

bool compare_with_months_margin(const datetime dt1, const datetime dt2, const int months) {
    int unix1 = datetime_to_unix(dt1);
    int unix2 = datetime_to_unix(dt2);
    return unix1 - months * 2592000 <= unix2 && unix1 + months * 2592000 >= unix2;
}

bool compare_with_years_margin(const datetime dt1, const datetime dt2, const int years) {
    int unix1 = datetime_to_unix(dt1);
    int unix2 = datetime_to_unix(dt2);
    return unix1 - years * 31536000 <= unix2 && unix1 + years * 31536000 >= unix2;
}

bool compare_with_hours_margin(const datetime dt1, const datetime dt2, const int hours) {
    int unix1 = datetime_to_unix(dt1);
    int unix2 = datetime_to_unix(dt2);
    return unix1 - hours * 3600 <= unix2 && unix1 + hours * 3600 >= unix2;
}

bool compare_with_minutes_margin(const datetime dt1, const datetime dt2, const int minutes) {
    int unix1 = datetime_to_unix(dt1);
    int unix2 = datetime_to_unix(dt2);
    return unix1 - minutes * 60 <= unix2 && unix1 + minutes * 60 >= unix2;
}

bool compare_with_seconds_margin(const datetime dt1, const datetime dt2, const int seconds) {
    int unix1 = datetime_to_unix(dt1);
    int unix2 = datetime_to_unix(dt2);
    return unix1 - seconds <= unix2 && unix1 + seconds >= unix2;
}

bool compare_with_days_margin_unix(const int unix1, const int unix2, const int days) {
    return unix1 - days * 86400 <= unix2 && unix1 + days * 86400 >= unix2;
}

bool compare_with_months_margin_unix(const int unix1, const int unix2, const int months) {
    return unix1 - months * 2592000 <= unix2 && unix1 + months * 2592000 >= unix2;
}

bool compare_with_years_margin_unix(const int unix1, const int unix2, const int years) {
    return unix1 - years * 31536000 <= unix2 && unix1 + years * 31536000 >= unix2;
}

bool compare_with_hours_margin_unix(const int unix1, const int unix2, const int hours) {
    return unix1 - hours * 3600 <= unix2 && unix1 + hours * 3600 >= unix2;
}

bool compare_with_minutes_margin_unix(const int unix1, const int unix2, const int minutes) {
    return unix1 - minutes * 60 <= unix2 && unix1 + minutes * 60 >= unix2;
}

bool compare_with_seconds_margin_unix(const int unix1, const int unix2, const int seconds) {
    return unix1 - seconds <= unix2 && unix1 + seconds >= unix2;
}

int get_days_between_datetime(const datetime dt1, const datetime dt2) {
    int unix1 = datetime_to_unix(dt1);
    int unix2 = datetime_to_unix(dt2);
    return (unix1 - unix2) / 86400;
}

int get_months_between_datetime(const datetime dt1, const datetime dt2) {
    int unix1 = datetime_to_unix(dt1);
    int unix2 = datetime_to_unix(dt2);
    return (unix1 - unix2) / 2592000;
}

int get_years_between_datetime(const datetime dt1, const datetime dt2) {
    int unix1 = datetime_to_unix(dt1);
    int unix2 = datetime_to_unix(dt2);
    return (unix1 - unix2) / 31536000;
}

int get_hours_between_datetime(const datetime dt1, const datetime dt2) {
    int unix1 = datetime_to_unix(dt1);
    int unix2 = datetime_to_unix(dt2);
    return (unix1 - unix2) / 3600;
}

int get_minutes_between_datetime(const datetime dt1, const datetime dt2) {
    int unix1 = datetime_to_unix(dt1);
    int unix2 = datetime_to_unix(dt2);
    return (unix1 - unix2) / 60;
}

int get_seconds_between_datetime(const datetime dt1, const datetime dt2) {
    int unix1 = datetime_to_unix(dt1);
    int unix2 = datetime_to_unix(dt2);
    return unix1 - unix2;
}

int get_days_between_unix(const int unix1, const int unix2) {
    return (unix1 - unix2) / 86400;
}

int get_months_between_unix(const int unix1, const int unix2) {
    return (unix1 - unix2) / 2592000;
}

int get_years_between_unix(const int unix1, const int unix2) {
    return (unix1 - unix2) / 31536000;
}

int get_hours_between_unix(const int unix1, const int unix2) {
    return (unix1 - unix2) / 3600;
}

int get_minutes_between_unix(const int unix1, const int unix2) {
    return (unix1 - unix2) / 60;
}

int get_seconds_between_unix(const int unix1, const int unix2) {
    return unix1 - unix2;
}
