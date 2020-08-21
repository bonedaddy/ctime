#include <stdio.h>
#include <assert.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "ctime.h"
#include <string.h>

#pragma GCC diagnostic ignored "-Wunused-parameter"

void test_ctime_all(void **state) {
    printf("%d\n", ctime_unix());
    printf("%li\n", ctime_unix_nano());
    char output[128];
    memset(output, 0, 128);
    ctime_ymd(output, 128);
    printf("%s\n", output);
    ctime_std(output, 128);
    printf("%s\n", output);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_ctime_all)
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}