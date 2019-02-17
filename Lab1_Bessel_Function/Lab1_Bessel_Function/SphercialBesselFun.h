#pragma once
#include "Function.h"
#include "Integrator.h"
#include "FunctionFactory.h"
#include "Identity.h"
#include "TwoFunctionFactory.h"
#include "Sin.h"

class SphercialBesselFun: public Function {
public:
	enum Kind { FIRST, SECOND };

	SphercialBesselFun(Kind kind, double order) { 
		this->kind = kind; 
		this->order = order;
		create_bessel_fun();
	}

	double get_value(double x);

private:
	Kind kind;
	double order;
	Function* bessel_fun;

	void create_bessel_fun();
};

void SphercialBesselFun::create_bessel_fun() {
	// Build functions within the integral
	// order*t
	// order is predefined constant!
	Function* _order = FunctionFactory::constant(this->order);
	Function* _t = new Identity();
	Function* _t_order = FunctionFactory::multiply(_order, _t);
	// x*sin(t)
	Function* _x = new Identity();
	Function* _sin = new Sin();
	TwoFunction* _x_sin = TwoFunctionFactory::multiply(_x, _sin);
	// order*t - x*sin(t)
	TwoFunction
}