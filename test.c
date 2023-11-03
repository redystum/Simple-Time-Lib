#include "library.h"

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
    printf("\n datetime to unix: %d", datetime_to_unix(dt));
    printf("\n\n +60 days %d", add_days(unix, 60));
    printf("\n\n -60 days %d", subtract_days(unix, 60));
    printf("\n\n +60 hours %d", add_hours(unix, 60));
    printf("\n\n -60 hours %d", subtract_hours(unix, 60));

    return 0;
}
