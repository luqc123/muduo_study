#include "EventLoop.h"

#include "../base/UtcTime.h"
#include "../base/UtcTime.cc"
#include "Channel.h"
#include "Poller.h"
#include "TimerQueue.h"

using namespace muduo;
using namespace muduo::net;

EventLoop::EventLoop()
		: poller_(Poller::newDefaultPoller()),
		  timerQueue_(new TimerQueue),
		  quit_(false)
{
	init();
}

EventLoop::~EventLoop()
{ }
		  
void EventLoop::loop()
{
	while(!quit_)
	{
		poller_->poll(1000);	
	}
}

void EventLoop::quit()
{
	quit_ = true;
}

void EventLoop::addChnnel(Channel* channel)
{
	assert(channel->getLoop() == this);
}

void EventLoop::removeChannel(Channel* Channel)
{
	assert(Channel->getLoop() == this);
}


void EventLoop::init()
{
	
}

TimerId EventLoop::runAt(const UtcTime& time, const TimerCallback& cb)
{
	return timerQueue_->schedule(cb, time, 0.0);
}

TimerId EventLoop::runAfter(double delay, const TimerCallback& cb)
{
	UtcTime time(addTime(UtcTime::now(), delay));
	return runAt(time, cb);
}

TimerId EventLoop::runEvery(double interval, const TimerCallback& cb)
{
	UtcTime time(addTime(UtcTime::now(), interval));
	return timerQueue_->schedule(cb, time, interval);
}


