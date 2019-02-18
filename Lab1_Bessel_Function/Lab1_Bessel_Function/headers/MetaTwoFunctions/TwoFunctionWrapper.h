#pragma once
#include "../TwoFunction/TwoFunction.h"
#include "../Factories/FunctionFactory.h"
#include "../Functions/Function.h"

class TwoFunctionWrapper : public TwoFunction {
private:
	Function* wrapper_fun;
	TwoFunction* two_fun;
public:
	TwoFunctionWrapper(Function* wrapper_fun, TwoFunction* two_fun) {
		this->wrapper_fun = wrapper_fun;
		this->two_fun = two_fun;
	}

	double get_value(double arg1, double arg2) {
		double two_fun_value = this->two_fun->get_value(arg1, arg2);
		return this->wrapper_fun->get_value(two_fun_value);
	}

	Function* set_arg1(double arg1) {
		Function* new_fun = this->two_fun->set_arg1(arg1);
		return FunctionFactory::composite(new_fun, this->wrapper_fun);
	}

	Function* set_arg2(double arg2) {
		Function* new_fun = this->two_fun->set_arg2(arg2);
		return FunctionFactory::composite(new_fun, this->wrapper_fun);
	}
};