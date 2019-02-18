#define _USE_MATH_DEFINES
#include <iostream>
#include "SphercialBesselFun.h"
#include <cmath>

using namespace std;



int main() {
	Function* fun = new SphercialBesselFun(SphercialBesselFun::Kind::FIRST, 0);
	cout << fun->get_value(M_PI/2);
	system("pause");
	return 0;
}