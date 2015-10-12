
#include "download_stats.h"

int elapsedTime(int currentTime, int startTime)
{
    return ((currentTime)-(startTime));
}

double percentComplete(double bytes, double totalBytes)
{
    return (((bytes)/(totalBytes))*100);
}

double downloadSpeed(int currentTime, int startTime, double bytes)
{
    return ((bytes)/(elapsedTime(currentTime, startTime)));
}

double totalTime(int currentTime, int startTime, double bytes, double totalBytes)
{
    return ((totalBytes)/(downloadSpeed(currentTime, startTime, bytes)));
}

double remainingTime(int currentTime, int startTime, double bytes, double totalBytes)
{
    return ((totalTime(currentTime, startTime, bytes, totalBytes))-(elapsedTime(currentTime, startTime)));
}
