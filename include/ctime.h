/*!
 * @file time.h
 * @brief provides utility functions for retrieving current time in a variety of
 * formats
 * @details it is intended to provide a package that is somewhat similar to
 * Golang
 * @details time package for working with timestamps, and time durations
 */

#include <stddef.h>

/*!
 * @brief defines the current local system time
 */
#define NOW (localtime(&(time_t){time(NULL)}))

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * @brief returns the current unix timestamp as an integer
 * @details returns the equivalent of `date +%s`
 */
int ctime_unix();

/*!
 * @brief like ctime_unix except returns timestamp in nanoseconds
 * @note from
 * https://stackoverflow.com/questions/361363/how-to-measure-time-in-milliseconds-using-ansi-c/36095407#36095407
 */
long int ctime_unix_nano();

/*!
 * @brief returns current timestamp in "year month date" format
 * @details writes to output param timestamp in format of 2014-12-25
 * @param output buffer to write to
 * @param output for better memory efficiency use a stack allocated array
 * @param output_len the length of the output buffer
 */
void ctime_ymd(char *output, size_t output_len);

/*!
 * @brief returns timestamp in standard date time
 * @details writes to output param teimstamp in format of Sun Oct 17 04:41:13
 * 2010
 * @param output buffer to write to
 * @param output for better memory efficiency use a stack allocated array
 * @param output_len the length of the output buffer
 */
void ctime_std(char *output, size_t output_len);

#ifdef __cplusplus
}
#endif