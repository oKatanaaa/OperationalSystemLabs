#pragma once
#include <cmath>
#include "Function.h"

class Integrator {
private:
	Function* function;
	double delta = 10e-4;
public:
	Integrator(Function* function) { this->function = function; };
	double integrate(double left_x, double right_x);
};

double Integrator::integrate(double left_x, double right_x) {
	if (right_x == INFINITY)
		right_x = 10e6;

	if (left_x == -INFINITY)
		left_x = -10e6;

	double value = 0;
	double x = left_x;
	while (x < right_x) {
		double delta_value = this->function->get_value(x) * this->delta;
		if (abs(delta_value) < 10e-12)
			break;

		value += delta_value;
		x += delta;
	}
	return value;
}