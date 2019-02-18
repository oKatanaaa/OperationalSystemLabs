#pragma once
#include "Function.h"

class Cos : public Function {
public:
	double get_value(double x) {
		return cos(x);
	}
};