#pragma once
#include "../Functions/Function.h"
#include "../MetaFunctions/FunctionSum.h"
#include "../MetaFunctions/FunctionComposition.h"
#include "../MetaFunctions/FunctionPower.h"
#include "../MetaFunctions/FunctionMultiplication.h"
#include "../Functions/Const.h"

class FunctionFactory {
private:
	FunctionFactory() {};
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

	static Function* constant(double value) {
		return new Constant(value);
	}

};