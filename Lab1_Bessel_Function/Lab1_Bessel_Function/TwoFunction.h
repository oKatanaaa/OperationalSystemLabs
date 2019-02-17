#pragma once
#include "Function.h"
#include "TwoFunctionFactory.h"

class TwoFunction {
	friend TwoFunctionFactory;
protected:
	Function* fun1;
	Function* fun2;

	double arg1;
	double arg2;

	bool arg1_is_set;
	bool arg2_is_set;
public:
	virtual double get_value(double, double);

	virtual Function* set_arg1(double arg1);

	virtual Function* set_arg2(double arg2);
};