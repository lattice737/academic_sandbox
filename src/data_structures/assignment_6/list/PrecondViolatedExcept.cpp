/** @file PrecondViolatedExcept.cpp */

#include "PrecondViolatedExcept.h"

PrecondViolatedExcept::PrecondViolatedExcept(const string& message) : logic_error("Precondition Violated Exception: " + message) {}