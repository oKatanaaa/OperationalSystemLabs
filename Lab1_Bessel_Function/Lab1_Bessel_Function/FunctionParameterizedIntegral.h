#pragma once
#include "Function.h"
#include "TwoFunction.h"
#include "Integrator.h"

class FunctionParameterizedIntegral : Function {
private:
	TwoFunction* fun;
	
	double left_x;
	double right_x;
	
	enum ArgToIntegrate { FIRST, SECOND };
	ArgToIntegrate arg_to_integrate;
public:
	FunctionParameterizedIntegral(TwoFunction* fun, double left_x, double right_x, 
		ArgToIntegrate arg_to_integrate) {
		this->fun = fun;
		this->left_x = left_x;
		this->right_x = right_x;
		this->arg_to_integrate = arg_to_integrate;
	}

	double get_value(double x) {
		Function* new_fun;

		if (this->arg_to_integrate == ArgToIntegrate::FIRST)
			new_fun = this->fun->set_arg1(x);
		else
			new_fun = this->fun->set_arg2(x);

		return Integrator::integrate(new_fun, this->left_x, this->right_x, 10e-3);
	}
};