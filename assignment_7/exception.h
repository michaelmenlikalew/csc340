#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_

#include <exception>

class No_Parent_Exception : public std::exception {
public:
    const char* what() const throw();
};

#endif
