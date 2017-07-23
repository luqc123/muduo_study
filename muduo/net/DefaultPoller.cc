#include "Poller.cc"
#include "PollPoller.cc"

Poller* Poller::newDefaultPoller()
{
	// 返回一个子类型的指针
	return new PollPoller;
}



