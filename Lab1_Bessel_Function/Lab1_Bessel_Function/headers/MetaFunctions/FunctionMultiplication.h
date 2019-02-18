#pragma once
#include "../Functions/Function.h"

class FunctionMultiplication : public Function {
private:
	Function* first;
	Function* second;
public:
	FunctionMultiplication(Function* first, Function* second) {
		this->first = first;
		this->second = second;
	}

	double get_value(double x) {
		return this->first->get_value(x) *
			this->second->get_value(x);
	}
};

