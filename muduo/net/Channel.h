#ifndef MUDUO_NET_CHANNEL_H
#define MUDUO_NET_CHANNEL_H

#include <boost/noncopyable.hpp>
#include "Socket.h"

namespace muduo
{
namespace net
{

class EventLoop;

class Channel : boost::noncopyable
{
public:
	Channel(EventLoop* loop, Socket sock);
	~Channel();

	void handle(int revents);

	EventLoop* getLoop() { return loop_; }

private:
	EventLoop* loop_;
	Socket sock_;
	int events_;
};

}
}

#endif
