#ifndef MUDUO_NET_SOCKET_H
#define MUDUO_NET_SOCKET_H


namespace muduo
{

//Tcp networking.
namespace net
{
// Wrapper of socket file descriptor.	
class Socket
{
public:
	explicit Socket(int sockfd) : sockfd_(sockfd) { }

	int fd() const { return sockfd_; }	

	// Enable/disable TCP_NODELAY (disable/enable Nagle's Algorithm)
	void setTcpNoDelay(bool on);

private:
	int sockfd_;
};	
}
}


#endif
