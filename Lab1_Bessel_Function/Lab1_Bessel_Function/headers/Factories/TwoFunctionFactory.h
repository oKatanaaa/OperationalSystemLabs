#pragma once
#include "../TwoFunction/TwoFunction.h"
#include "../Functions/Function.h"
#include "FunctionFactory.h"
#include "../MetaTwoFunctions/TwoFunctionMultiplication.h"
#include "../MetaTwoFunctions/TwoFunctionTwoSum.h"
#include "../MetaTwoFunctions/TwoFunctionWrapper.h"
#include "../MetaFunctions/FunctionParameterizedIntegral.h"
#include "../MetaTwoFunctions/TwoFunctionSum.h"

class TwoFunctionFactory {
public:
	static TwoFunction* multiply(Function* fun1, Function* fun2) {
		return new TwoFunctionMultiplication(fun1, fun2);
	}

	static TwoFunction* sum(Function* fun1, Function* fun2) {
		return new TwoFunctionSum(fun1, fun2);
	}

	static TwoFunction* two_sum(TwoFunction* fun1, TwoFunction* fun2) {

	}

	/* 
	arg_id represents which argument fun is responsible for. Examples:
	arg_id = FIRST - > f(x, y) = two_fun(x, y) + fun(x)
	arg_id = SECOND - > f(x, y) = two_fun(x, y) + fun(y)
	*/
	static TwoFunction* two_twosum(TwoFunction* two_fun, Function* fun, ArgIndex arg_id) {
		return new TwoFunctionTwoSum(two_fun, fun, arg_id);
	}

	static TwoFunction* wrap(TwoFunction* two_fun, Function* wrapper_fun) {
		return new TwoFunctionWrapper(wrapper_fun, two_fun);
	}

	static Function* parameter_integral(TwoFunction* fun, double left_x, double right_x,
		ArgIndex arg_to_integrate) {
		return new FunctionParameterizedIntegral(fun, left_x, right_x, arg_to_integrate);
	}
};