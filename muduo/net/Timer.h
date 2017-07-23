#ifndef MUDUO_TIMER_H
#define MUDUO_TIMER_H

#include <map>

#include <boost/function.hpp>
#include <boost/noncopyable.hpp>

#include "../base/UtcTime.h"

namespace muduo
{
namespace net
{
	// Iternal class for timer event
	class Timer : boost::noncopyable
	{
	public:
		// define a function template which return void and accept void
		typedef boost::function<void()> TimerCallback;	
		// 在初始化列表中初始化const
		Timer(const TimerCallback& cb, UtcTime at, double interval) : 
			// 初始化顺序和private里边声明的顺序一致
			cb_(cb),
			expiration_(at),
			interval_(interval),
			repeat_(interval > 0.0)
		{ }

		void run() const
		{
			cb_();	
		}
		
		UtcTime expiration() const { return expiration_; }
		bool repeat() const { return repeat_; }
		
		void restart(UtcTime now);

	private:
		const TimerCallback cb_;
		UtcTime expiration_;
		const double interval_;
		const bool repeat_;
	};
}	
}
#endif
