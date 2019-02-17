#pragma once
#include "TwoFunction.h"
#include "Function.h"
#include "FunctionFactory.h"
#include "TwoFunctionMultiplication.h"

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
};