/** Listing 7-5.
 @file NotFoundException.h */

#ifndef NOT_FOUND_EXCEPTION_
#define NOT_FOUND_EXCEPTION_

#include <stdexcept>
#include <string>

class NotFoundException : public std::logic_error{
    NotFoundException(const std::string& message="");
};

#endif