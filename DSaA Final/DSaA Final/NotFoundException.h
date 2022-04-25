#pragma once
#ifndef _NOT_FOUND_EXEP
#define _NOT_FOUND_EXEP

#include <stdexcept>
#include <string>

using namespace std;

class NotFoundException : public logic_error
{
public:
	NotFoundException(const string& message = "") :
		logic_error("Not Found Exception: " + message) {};

};
#endif