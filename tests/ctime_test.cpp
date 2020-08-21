#include <stdio.h>
#include <string.h>
#include "ctime.h"

int main(void) {
    printf("%d\n", ctime_unix());
    printf("%li\n", ctime_unix_nano());
    char output[128];
    memset(output, 0, 128);
    ctime_ymd(output, 128);
    printf("%s\n", output);
    ctime_std(output, 128);
    printf("%s\n", output);
}