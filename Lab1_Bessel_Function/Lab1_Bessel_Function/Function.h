#pragma once
#include <cmath>

class Function {
public:
	virtual double get_value(double x);
};

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

class FunctionSum : public Function {
private:
	Function* first;
	Function* second;
public:
	FunctionSum(Function* first, Function* second) {
		this->first = first;
		this->second = second;
	}

	double get_value(double x) {
		return this->first->get_value(x) +
			this->second->get_value(x);
	}
};

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

class FunctionPower : public Function {
private:
	double power;
	Function* fun;
public:
	FunctionPower(Function* fun, double power) {
		this->fun = fun;
		this->power = power;
	}

	double get_value(double x) {
		double value_to_power = this->fun->get_value(x);
		return pow(value_to_power, this->power);
	}
};

class Sin: public Function {
public:
	double get_value(double x) {
		return sin(x);
	}
};

class Cos : public Function {
public:
	double get_value(double x) {
		return cos(x);
	}
};

class Sinh : public Function {
public:
	double get_value(double x) {
		return sinh(x);
	}
};

class Constant : public Function {
private:
	double value;
public:
	Constant(double value) { 
		this->value = value; 
	}

	double get_value(double x) {
		return value;
	}
};
