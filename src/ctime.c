#include "ctime.h"
#include <stddef.h>
#include <time.h>

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * @brief returns the current unix time as an integer
 * @details returns the equivalent of `date +%s`
 */
int ctime_unix() { return (int)time(NULL); }

/*!
 * @brief like ctime_unix except returns timestamp in nanoseconds
 * @note from
 * https://stackoverflow.com/questions/361363/how-to-measure-time-in-milliseconds-using-ansi-c/36095407#36095407
 */
long int ctime_unix_nano() {
  struct timespec ts;
  timespec_get(&ts, TIME_UTC);
  return (long int)ts.tv_sec * 1000000000L + ts.tv_nsec;
}

/*!
 * @brief returns current timestamp in "year month date" format
 * @details writes to output param timestamp in format of 2014-12-25
 * @param output buffer to write to
 * @param output for better memory efficiency use a stack allocated array
 * @param output_len the length of the output buffer
 */
void ctime_ymd(char *output, size_t output_len) {
  strftime(output, output_len, "%Y-%m-%d", NOW);
}

/*!
 * @brief returns timestamp in standard date time
 * @details writes to output param teimstamp in format of Sun Oct 17 04:41:13
 * 2010
 * @param output buffer to write to
 * @param output for better memory efficiency use a stack allocated array
 * @param output_len the length of the output buffer
 */
void ctime_std(char *output, size_t output_len) {
  strftime(output, output_len, "%c", NOW);
}

#ifdef __cplusplus
}
#endif