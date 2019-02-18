#pragma once
#include "Function.h"

class Constant : public Function {
private:
	double value;
public:
	Constant(double value) {
		this->value = value;
	}

	double get_value(double x) {
		return value;
	}
};
