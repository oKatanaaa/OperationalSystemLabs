#pragma once
#include "Function.h"
#include <cmath>

class Exp : public Function {
public:
	double get_value(double x) {
		return exp(x);
	}
};