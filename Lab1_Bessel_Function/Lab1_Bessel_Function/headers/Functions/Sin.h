#pragma once
#include "Function.h"

class Sin : public Function {
public:
	double get_value(double x) {
		return sin(x);
	}
};