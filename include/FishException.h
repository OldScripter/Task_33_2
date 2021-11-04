#ifndef TASK_33_2_FISHEXCEPTION_H
#define TASK_33_2_FISHEXCEPTION_H
#include <exception>
#include <iostream>

class FishException:  public std::exception {
    const char * what() const noexcept override;
};

#endif //TASK_33_2_FISHEXCEPTION_H