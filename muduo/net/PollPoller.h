#ifndef MUDUO_NET_POLLPOLLER_H
#define MUDUO_NET_POLLPOLLER_H

#include "Poller.h"

#include <poll.h>

#include <vector>

namespace muduo
{
namespace net
{
// IO Multiplexing with poll(2)
class PollPoller : public Poller
{
public:
	virtual ~PollPoller();
	virtual void poll(int timeoutMs);

private:
	/*
		struct pollfd
		{
			int fd; // file descriptor
			short events; // request events
			short revents; // returned events	
		};
	*/
	typedef std::vector<struct pollfd> PollFdList;
	PollFdList pollfds_;
};

}
}

#endif
