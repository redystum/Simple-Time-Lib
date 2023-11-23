//
// Created by rffar on 23/11/2023.
//

#include "simple_time_lib.h"

#include <stdio.h>
#include <time.h>

int main() {
    int unix = unix_time();
    datetime dt = current_datetime();
    datetime dt2 = unix_to_datetime(unix);

    printf("unix_time: %d\nform time.h : %lld", unix,  time(NULL));
    printf("current datetime: %d-%d-%d %d:%d:%d\n", dt.year, dt.month, dt.day, dt.hour, dt.minute, dt.second);
    printf("\n\n%s\n", current_datetime_string("%D-%M-%Y random text %h:%m: aaa%s %Y---%M-%D te%Mxt"));
    printf("unix to datetime: %d-%d-%d %d:%d:%d\n", dt2.year, dt2.month, dt2.day, dt2.hour, dt2.minute, dt2.second);
    printf("\nformatted unix to str %s", unix_to_string(unix, "%D-%M-%Y random text %h:%m: aaa%s %Y---%M-%D te%Mxt"));
    printf("\ndatetime to unix: %d", datetime_to_unix(dt));
    printf("\n\n +60 days %d", add_days(unix, 60));
    printf("\n\n -60 days %d", subtract_days(unix, 60));
    printf("\n\n +60 hours %d", add_hours(unix, 60));
    printf("\n\n -60 hours %d", subtract_hours(unix, 60));

    if(is_leap_year(2020)) {
        printf("\n\n2020 is leap year");
    } else {
        printf("\n\n2020 is not leap year");
    }

    if(is_leap_year(2021)) {
        printf("\n\n2021 is leap year");
    } else {
        printf("\n\n2021 is not leap year");
    }

    datetime dt3 = {2020, 2, 29, 0, 0, 0};
    datetime dt_equal_to_3 = {2020, 2, 29, 0, 0, 0};
    datetime dt_not_equal_to_3 = {2020, 2, 28, 0, 0, 0};

    if(compare_datetime(dt3, dt_equal_to_3)) {
        printf("\n\n2020-2-29 is equal to 2020-2-29");
    } else {
        printf("\n\n2020-2-29 is not equal to 2020-2-29");
    }

    if(compare_datetime(dt3, dt_not_equal_to_3)) {
        printf("\n\n2020-2-29 is equal to 2020-2-28");
    } else {
        printf("\n\n2020-2-29 is not equal to 2020-2-28");
    }

    if (compare_with_days_margin(dt3, dt_not_equal_to_3, 1)) {
        printf("\n\n2020-2-29 is equal to 2020-2-28 with 1 day margin");
    } else {
        printf("\n\n2020-2-29 is not equal to 2020-2-28 with 1 day margin");
    }


    return 0;
}
