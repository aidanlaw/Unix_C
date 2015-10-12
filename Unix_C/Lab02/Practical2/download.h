
/* replaced by download_stats.c and download_stats.h */

#include <time.h>

#define ELAPSED_TIME(time, startTime) ((time)-(startTime))
#define PERCENT_COMPLETE(bytes, totalBytes) ((bytes)/(totalBytes)*100)
#define DOWNLOAD_SPEED(time, startTime, bytes) ( (bytes)/(ELAPSED_TIME(time, startTime)) )
#define TOTAL_TIME(time, startTime, bytes, totalBytes) ((totalBytes)/(DOWNLOAD_SPEED(time, startTime, bytes)))
#define REMAINING_TIME(time, startTime, bytes, totalBytes) ( (TOTAL_TIME(time, startTime, bytes, totalBytes)) - (ELAPSED_TIME(time, startTime)))
