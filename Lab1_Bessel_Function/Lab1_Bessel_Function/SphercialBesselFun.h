#pragma once
#include "Function.h"
#include "Integrator.h"
#include "FunctionWorkbench.h"

class SphercialBesselFun: public Function {
public:
	enum Kind { FIRST, SECOND };

	SphercialBesselFun(Kind kind, int order) { 
		this->kind = kind; 
		this->order = order;
		create_bessel_fun();
	}

	double get_value(double x);

private:
	Kind kind;
	int order;
	Function* bessel_fun;

	void create_bessel_fun();
};

void SphercialBesselFun::create_bessel_fun() {

}