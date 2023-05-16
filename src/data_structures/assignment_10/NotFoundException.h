//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** Listing 7-5.
    @file NotFoundExcepti.h */

#ifndef NOT_FOUND_EXCEPTION_
#define NOT_FOUND_EXCEPTION_

#include <stdexcept>
#include <string>

class NotFoundException : public std::logic_error
{
public:
   NotFoundException(const std::string& message = "");
}; // end NotFoundExcepti 

/** Listing 7-6.
    @file NotFoundException.cpp */
#include "NotFoundException.h"  

NotFoundException::NotFoundException(const std::string& message)
         : std::logic_error("Not Found Exception: " + message)
{
}  // end constructor

// End of implementation file.

#endif
