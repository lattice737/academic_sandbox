/** @file PrecondViolatedExcept.h */

#ifndef PRECOND_VIOLATED_EXCEPT_
#define PRECOND_VIOLATED_EXCEPT_

#include <stdexcept>
#include <string>

using namespace std;

class PrecondViolatedExcept: public logic_error {
    public:
        PrecondViolatedExcept(const string& message = "");
};

#endif