#pragma once
#include <cmath>

class Function {
public:
	virtual double get_value(double x);
};







class FunctionParametrizedIntegral : public Function {
private:
	double left_x;
	double right_x;
	Function* fun;
public:
	FunctionParametrizedIntegral(double left_x, double right_x, Function* fun) {
		this->left_x = left_x;
		this->right_x = right_x;
		this->fun = fun;
	}

	double get_value(double x) {

	}
};







