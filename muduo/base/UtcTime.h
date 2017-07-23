#ifndef	MUDUO_BASE_UTCTIME_H
#define MUDUO_BASE_UTCTIME_H

#include "Types.h"

namespace muduo{

class UtcTime
{
public:
	UtcTime();
	explicit UtcTime(int64_t microseconds);

	string toString() const;

	bool valid() const { return microSecondsSinceEpoch_ > 0; }

	bool before(UtcTime rhs) const
	{
		return microSecondsSinceEpoch_ < rhs.microSecondsSinceEpoch_;	
	}

	bool after(UtcTime rhs) const
	{
		return microSecondsSinceEpoch_ > rhs.microSecondsSinceEpoch_;	
	}

	bool equal(UtcTime rhs) const
	{
		return microSecondsSinceEpoch_ == rhs.microSecondsSinceEpoch_;	
	}

	int64_t microSecondsSinceEpoch() const { return microSecondsSinceEpoch_; }

	// get time of now
	static UtcTime now();
	static UtcTime invalid();
	static const int kMicroSecondsPerSecond = 1000 * 1000;

private:
	int64_t  microSecondsSinceEpoch_;
};

inline bool operator<(UtcTime lhs, UtcTime rhs)
{
	return lhs.before(rhs);
}

inline bool operator==(UtcTime lhs, UtcTime rhs)
{
	return lhs.equal(rhs);
}

// Get time difference of two timestamps result in seconds
inline double timeDifference(UtcTime high, UtcTime low)
{
	int64_t diff = high.microSecondsSinceEpoch() - low.microSecondsSinceEpoch();
	return static_cast<double>(diff/UtcTime::kMicroSecondsPerSecond);
}

// add seconds to given timestamp
inline UtcTime addTime(UtcTime timestamp,double seconds)
{
	int64_t delta = static_cast<int64_t>(seconds * UtcTime::kMicroSecondsPerSecond);
	return UtcTime(static_cast<int64_t>(timestamp.microSecondsSinceEpoch() + delta));
}


}

#endif
