#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>

class Exception_Negative_Deposit : public std::exception {
public:
    const char* what() const throw();
};

class Exception_Overdraw : public std::exception {
public:
    const char* what() const throw();
};

class Exception_Negative_Withdraw : public std::exception {
public:
    const char* what() const throw();
};

#endif
