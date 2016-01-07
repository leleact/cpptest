#ifndef _VARLIB_SOCKET_EXCEPTION_H
#define _VARLIB_SOCKET_EXCEPTION_H
#include <exception>
#include <errno.h>
#include <string.h>

namespace varlib {

class socketException : public std::exception {
public:
	socketException(int error) :m_errno(error) { }

	virtual const char *what() const noexcept {
		return strerror(m_errno);
	}
private:
	int m_errno;
};

}

#endif
