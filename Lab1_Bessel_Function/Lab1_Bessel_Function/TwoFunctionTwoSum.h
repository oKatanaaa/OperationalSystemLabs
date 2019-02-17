#pragma once
#include "TwoFunction.h"

class TwoFunctionTwoSum : public TwoFunction {
private:
	TwoFunction* two_fun;
	Function* fun;

	enum ArgIndex { FIRST, SECOND };
	ArgIndex arg_id;
public:
	TwoFunctionTwoSum(TwoFunction* two_fun, Function* fun, ArgIndex arg_id) {
		this->two_fun = two_fun;
		this->fun = fun;
		this->arg_id = arg_id;
	}

	double get_value(double arg1, double arg2) {
		double fun_value;
		if (this->arg_id == ArgIndex::FIRST)
			fun_value = this->fun->get_value(arg1);
		else
			fun_value = this->fun->get_value(arg2);

		return fun_value +
			this->two_fun->get_value(arg1, arg2);
	}
};