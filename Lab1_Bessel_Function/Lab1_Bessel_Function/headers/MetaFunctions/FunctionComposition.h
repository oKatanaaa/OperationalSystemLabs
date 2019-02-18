#pragma once
#include "../Functions/Function.h"

class FunctionComposition : public Function {
private:
	Function* inner;
	Function* outer;
public:
	FunctionComposition(Function* inner, Function* outer) {
		this->inner = inner;
		this->outer = outer;
	}

	double get_value(double x) {
		double inner_value = this->inner->get_value(x);
		return this->outer->get_value(inner_value);
	};
};