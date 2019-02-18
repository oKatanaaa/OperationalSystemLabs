#pragma once
#include "Function.h"

class Identity : public Function {
public:
	double get_value(double x) {
		return x;
	}
};