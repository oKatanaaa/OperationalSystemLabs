#pragma once
#include <cmath>
#include "headers/Functions/Function.h"

class Integrator {
public:
	static double integrate(Function* fun, double left_x, double right_x, double dx);
};

double Integrator::integrate(Function* fun, double left_x, double right_x, double dx) {
	if (right_x == INFINITY)
		right_x = 10e3;

	if (left_x == -INFINITY)
		left_x = -10e3;

	double value = 0;
	double x = left_x;
	while (x < right_x) {
		double delta_value = fun->get_value(x) * dx;
		//if (abs(delta_value) < 10e-22)
		//	break;

		value += delta_value;
		x += dx;
	}
	return value;
}