#pragma once
#include "Function.h"

class Identity : public Function {
public:
	Identity() {};
	double get_value(double x) {
		return x;
	}
};