#pragma once
#include "Function.h"

class FunctionPower : public Function {
private:
	double power;
	Function* fun;
public:
	FunctionPower(Function* fun, double power) {
		this->fun = fun;
		this->power = power;
	}

	double get_value(double x) {
		double value_to_power = this->fun->get_value(x);
		return pow(value_to_power, this->power);
	}
};