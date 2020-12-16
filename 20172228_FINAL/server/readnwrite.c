#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 * Read n bytes from a descriptor
 */

ssize_t readn(int fd, void* vptr, size_t n)
{
	ssize_t nleft;
	ssize_t nread;
	char* ptr;
	
	ptr = vptr;
	nleft = n;
	
	while(nleft > 0)
	{
		nread = read(fd, ptr, nleft);
		
		if(nread == -1)
		{
			return -1;
		}
		else if(nread == 0)
		{
			break;
		}
		nleft -= nread;
		ptr += nread;
	}
	return (n-nleft);
}

/*
 * Write n bytes to a descriptor 
 */

ssize_t writen(int fd, const void* vptr, size_t n)
{
	ssize_t nleft;
	ssize_t nwritten;
	const char* ptr;
	
	ptr = vptr;
	nleft = n;
	
	while(nleft > 0)
	{
		nwritten = write(fd, ptr, nleft);
		
		if(nwritten == -1)
		{
			return -1;
		}
		nleft -= nwritten;
		ptr += nwritten;
	}
	return n;
}