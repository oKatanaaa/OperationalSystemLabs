#pragma once
#include "../TwoFunction/TwoFunction.h"
#include "../Functions/Function.h"
#include "../Factories/FunctionFactory.h"

class TwoFunctionSum : public TwoFunction {
	friend class TwoFunctionFactory;
public:
	TwoFunctionSum(Function* fun1, Function* fun2) {
		this->fun1 = fun1;
		this->fun2 = fun2;
	}

	double get_value(double arg1, double arg2) {
		return this->fun1->get_value(arg1) + this->fun2->get_value(arg2);
	}

	Function* set_arg1(double arg1) {
		double value_fun1 = this->fun1->get_value(arg1);
		Function* constant_value_fun1 = FunctionFactory::constant(value_fun1);
		return FunctionFactory::sum(constant_value_fun1, this->fun2);
	}

	Function* set_arg2(double arg2) {
		double value_fun2 = this->fun1->get_value(arg2);
		Function* constant_value_fun2 = FunctionFactory::constant(value_fun2);
		return FunctionFactory::sum(this->fun1, constant_value_fun2);
	}
};
