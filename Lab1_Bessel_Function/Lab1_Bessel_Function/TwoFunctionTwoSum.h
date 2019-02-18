#pragma once
#include "TwoFunction.h"
#include "FunctionFactory.h"

enum ArgIndex { FIRST, SECOND };

/*
This class represents this kind of function:
arg_id = FIRST - > f(x, y) = a(x) + b(x, y)
arg_id = SECOND - > f(x, y) = a(y) + b(x, y)
*/
class TwoFunctionTwoSum : public TwoFunction {
private:
	TwoFunction* two_fun;
	Function* fun;
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

	Function* set_arg1(double arg1) {
		Function* new_fun = this->two_fun->set_arg1(arg1);
		if (this->arg_id == ArgIndex::FIRST) {
			double fun_value = this->fun->get_value(arg1);
			Function* constant = FunctionFactory::constant(fun_value);
			return FunctionFactory::sum(constant, new_fun);
		}
		else {
			return FunctionFactory::sum(this->fun, new_fun);
		}
	}

	Function* set_arg2(double arg2) {
		Function* new_fun = this->two_fun->set_arg2(arg2);
		if (this->arg_id == ArgIndex::SECOND) {
			double fun_value = this->fun->get_value(arg2);
			Function* constant = FunctionFactory::constant(fun_value);
			return FunctionFactory::sum(constant, new_fun);
		}
		else {
			return FunctionFactory::sum(this->fun, new_fun);
		}
	}
};