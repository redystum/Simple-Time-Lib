#include "library.h"

#include <stdio.h>
#include <time.h>

int main() {
    int unix = unix_time();
    printf("unix_time: %d\nform time.h : %lld", unix,  time(NULL));
    datetime dt = current_datetime();
    printf("current datetime: %d-%d-%d %d:%d:%d\n", dt.year, dt.month,
           dt.day, dt.hour, dt.minute, dt.second);
    printf("\n\n%s\n", current_datetime_string("%D-%M-%Y random text %h:%m: aaa%s %Y---%M-%D te%Mxt"));
    datetime dt2 = unix_to_datetime(unix);
    printf("unix to datetime: %d-%d-%d %d:%d:%d\n", dt2.year, dt2.month,
           dt2.day, dt2.hour, dt2.minute, dt2.second);
    printf("\nformatted unix to str %s", unix_to_string(unix, "%D-%M-%Y random text %h:%m: aaa%s %Y---%M-%D te%Mxt"));
    printf("\n datetime to unix: %d", datetime_to_unix(dt));
    return 0;
}
