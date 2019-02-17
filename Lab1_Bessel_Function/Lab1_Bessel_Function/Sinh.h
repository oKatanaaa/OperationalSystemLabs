#pragma once
#include "Function.h"

class Sinh : public Function {
public:
	double get_value(double x) {
		return sinh(x);
	}
};