#ifndef MUDUO_NET_TIMERQUEUE_H
#define MUDUO_NET_TIMERQUEUE_H

#include <list>

#include <boost/function.hpp>
#include <boost/noncopyable.hpp>

#include "../base/UtcTime.h" // for UtcTime

namespace muduo
{
namespace net
{
class Timer;
class TimerId;

class TimerQueue : boost::noncopyable
{
public:
	typedef boost::function<void()> TimerCallback;
	
	TimerQueue();
	~TimerQueue();
	
	void tick(UtcTime now);

	// schedules the callback to be run at given time
	// repeat if internal > 0.0
	TimerId schedule(const TimerCallback& cb, UtcTime at, double internal);

	void cancel(TimerId timerId);

private:
	typedef std::list<Timer*> Timers;
	Timers timer_;
};

}
}


#endif
