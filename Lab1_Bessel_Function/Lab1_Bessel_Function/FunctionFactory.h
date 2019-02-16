#pragma once
#include "Function.h"

class FunctionFactory {
public:
	static Function* multiply(Function* first, Function* second) {
		return new FunctionMultiplication(first, second);
	}

	static Function* sum(Function* first, Function* second) {
		return new FunctionSum(first, second);
	}

	static Function* composite(Function* inner, Function* outer) {
		return new FunctionComposition(inner, outer);
	}

	static Function* power(Function* fun, double power) {
		return new FunctionPower(fun, power);
	}
};