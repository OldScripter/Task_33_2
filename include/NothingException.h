#ifndef TASK_33_2_NOTHINGEXCEPTION_H
#define TASK_33_2_NOTHINGEXCEPTION_H
#include <exception>
#include <iostream>

class NothingException : public std::exception {
    const char * what() const noexcept override;
};

#endif //TASK_33_2_NOTHINGEXCEPTION_H