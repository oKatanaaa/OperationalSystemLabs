#pragma once

#include <cmath>
#include "headers/Functions/Function.h"
#include "headers/Utils/Integrator.h"
#include "headers/Factories/FunctionFactory.h"
#include "headers/Functions/Identity.h"
#include "headers/Factories/TwoFunctionFactory.h"
#include "headers/Functions/Sin.h"
#include "headers/Functions/Cos.h"
#include "headers/Functions/Sinh.h"
#include "headers/Functions/Exp.h"

class SphercialBesselFun: public Function {
public:
	enum Kind { FIRST, SECOND };

	SphercialBesselFun(Kind kind, int order) {
	    this->order = order;
		this->kind = kind; 
		if(kind == Kind::FIRST)
			this->alpha = (double)order + 0.5;
		else
			this->alpha = (double)order*(-1) + -0.5;
		create_bessel_fun();
	}

	double get_value(double x) {
		if(this->kind == Kind::FIRST)
			 this->bessel_fun->get_value(x);
		else
			if((this->order & 1) == 0)
				return (-1)*this->bessel_fun->get_value(x);
			else
				return this->bessel_fun->get_value(x);
	}

private:
	Kind kind;
	int order;
	double alpha;
	Function* bessel_fun;

	void create_bessel_fun();
};

void SphercialBesselFun::create_bessel_fun() {
	// Build functions within the integral

	// BUILD FIRST PART - ALPHA

	// order*t
	// order is predefined constant!
	Function* _order = FunctionFactory::constant(this->alpha);
	Function* _t = new Identity();
	Function* _order_t = FunctionFactory::multiply(_order, _t);

	// (-1)*x*sin(t)
	Function* _x = new Identity();
	Function* _minus_one = FunctionFactory::constant(-1);
	Function*_minus_x = FunctionFactory::multiply(_minus_one, _x);

	Function* _sin_t = new Sin();
	TwoFunction* _x_sin_t = TwoFunctionFactory::multiply(_minus_x, _sin_t);

	// order*t - x*sin(t) = inner(x, t)
	TwoFunction* _inner_x_t = TwoFunctionFactory::two_twosum(_x_sin_t, _order_t, ArgIndex::SECOND);

	// cos(inner(x, t))
	Function* _wrapper_cos = new Cos();
	TwoFunction* _cos_inner_x_t = TwoFunctionFactory::wrap(_inner_x_t, _wrapper_cos);

	// integral by t of cos(inner(x, t)) from 0 up to PI
	double _left_x = 0;
	double _right_x = M_PI;
	Function* _integral1_x = TwoFunctionFactory::parameter_integral(_cos_inner_x_t, _left_x, _right_x, ArgIndex::SECOND);

	// (1 / PI) * integral1(x) = ALPHA
	Function* _one_by_pi = FunctionFactory::constant(1 / M_PI);
	Function* ALPHA = FunctionFactory::multiply(_one_by_pi, _integral1_x);

	// BUILD SECOND PART - BETA
	// -(1)*order*t
	Function* _minus_order_t = FunctionFactory::multiply(_minus_one, _order_t);
	
	// (-1)*x*sinh(t) = lefter(x, t)
	Function* _sinh_t = new Sinh();
	TwoFunction* _lefter_x_t = TwoFunctionFactory::multiply(_minus_x, _sinh_t);

	// lefter(x, t) + (-1)*order*t = power(x, t)
	TwoFunction* _power_x_t = TwoFunctionFactory::two_twosum(_lefter_x_t, _minus_order_t, ArgIndex::SECOND);

	// exp(power(x, t)) = exp(x, t)
	Function* _wrapper_exp = new Exp();
	TwoFunction* _exp_x_t = TwoFunctionFactory::wrap(_power_x_t, _wrapper_exp);

	// integral by t of exp(x, t) from 0 up to INFINITY
	_left_x = 0;
	_right_x = INFINITY;
	Function* _integral2_x = TwoFunctionFactory::parameter_integral(_exp_x_t, _left_x, _right_x, ArgIndex::SECOND);

	
	// (-1)*sin(order*PI)/PI = mupltiplyer
	double _multiplier = -1 * sin(this->alpha * M_PI) / M_PI;
	Function* _multiplier_fun = FunctionFactory::constant(_multiplier);

	// (-1)*sin(order*PI)/PI * integral2(x) = BETA
	Function* BETA = FunctionFactory::multiply(_multiplier_fun, _integral2_x);

	// ALPHA + BETA = GENERAL_BESSEL_FUN
	Function* GENERAL_BESSEL_FUN = FunctionFactory::sum(ALPHA, BETA);

	// PI / 2
	double _division = M_PI / 2;
	Function* _division_const = FunctionFactory::constant(_division);

	// 1 / x
	Function* _one_by_x = FunctionFactory::power(_x, -1);

	// sqrt(PI / (2*x))
	Function* _inner = FunctionFactory::multiply(_division_const, _one_by_x);
	Function* _sqrt = FunctionFactory::power(_inner, 0.5);

	// sqrt(PI / (2*x)) * GENERAL_BESSEL_FUN = SPHERICAL_BESSEL_FUN
	Function* SPHERICAL_BESSEL_FUN = FunctionFactory::multiply(_sqrt, GENERAL_BESSEL_FUN);
	this->bessel_fun = SPHERICAL_BESSEL_FUN;
}
