#include "library.h"

#include <stdio.h>
#include <time.h>

int main() {
    printf("unix_time: %d\nform time.h : %lld", unix_time(), time(NULL));
    datetime dt = current_datetime();
    printf("current datetime: %d-%d-%d %d:%d:%d\n", dt.year, dt.month,
           dt.day, dt.hour, dt.minute, dt.second);
    printf("\n\n%s\n", current_datetime_string("%D-%M-%Y random text %h:%m: aaa%s %Y---%M-%D te%Mxt"));
    return 0;
}
