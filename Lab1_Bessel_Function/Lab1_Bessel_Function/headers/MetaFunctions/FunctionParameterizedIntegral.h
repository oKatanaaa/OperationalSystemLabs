#pragma once
#include "../Functions/Function.h"
#include "../TwoFunction/TwoFunction.h"
#include "headers/Utils/Integrator.h"
#include "../MetaTwoFunctions/TwoFunctionWrapper.h"

class FunctionParameterizedIntegral : public Function {
private:
	TwoFunction* fun;
	
	double left_x;
	double right_x;
	
	ArgIndex arg_to_integrate;
public:
	FunctionParameterizedIntegral(TwoFunction* fun, double left_x, double right_x, 
		ArgIndex arg_to_integrate) {
		this->fun = fun;
		this->left_x = left_x;
		this->right_x = right_x;
		this->arg_to_integrate = arg_to_integrate;
	}

	double get_value(double x) {
		Function* new_fun;

		if (this->arg_to_integrate == ArgIndex::FIRST)
			new_fun = this->fun->set_arg2(x);
		else
			new_fun = this->fun->set_arg1(x);

		return Integrator::integrate(new_fun, this->left_x, this->right_x, 10e-4);
	}
};