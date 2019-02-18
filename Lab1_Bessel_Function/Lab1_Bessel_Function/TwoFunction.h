#pragma once
#include "Function.h"
#include "TwoFunctionFactory.h"

class TwoFunction {
	friend class TwoFunctionFactory;
protected:
	Function* fun1;
	Function* fun2;
public:
	virtual double get_value(double arg1, double arg2);

	virtual Function* set_arg1(double arg1);

	virtual Function* set_arg2(double arg2);
};