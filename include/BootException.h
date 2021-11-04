#ifndef TASK_33_2_BOOTEXCEPTION_H
#define TASK_33_2_BOOTEXCEPTION_H
#include <exception>
#include <iostream>

class BootException: public std::exception  {
public:
    const char * what() const noexcept override;
};

#endif //TASK_33_2_BOOTEXCEPTION_H