#include "UtcTime.h"
#include <sys/time.h> // for getdayoftime
#include <stdio.h>
#define __STDC_FORMAT_MACROS // for PRId64
#include <inttypes.h> // for int64_t 

UtcTime::UtcTime() : microSecondsSinceEpoch_(0) { };

UtcTime::UtcTime(int64_t microseconds) : microSecondsSinceEpoch_(microseconds){ }

string UtcTime::toString() const
{
	char buf[32] = {0};
	int64_t seconds = microSecondsSinceEpoch_ / kMicroSecondsPerSecond;
	int64_t microseconds = microSecondsSinceEpoch_ % kMicroSecondsPerSecond;
	snprintf(buf, sizeof(buf)-1, "%" PRId64 "%.06" PRId64 " ", seconds, microseconds);
}

UtcTime UtcTime::now()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	int64_t seconds = tv.tv_sec;
	// return total microseconds
	return UtcTime(seconds * kMicroSecondsPerSecond + tv.tv_usec);
}




