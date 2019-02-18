#pragma once
#include "../Functions/Function.h"
#include "../Factories/TwoFunctionFactory.h"

class TwoFunction {
	friend class TwoFunctionFactory;
protected:
	Function* fun1;
	Function* fun2;
public:
	virtual double get_value(double arg1, double arg2) = 0;

	virtual Function* set_arg1(double arg1) = 0;

	virtual Function* set_arg2(double arg2) = 0;
};