
#include <iostream>
#include "headers/Functions/SphercialBesselFun.h"
#include <cmath>

using namespace std;



int main() {
	Function* fun = new SphercialBesselFun(SphercialBesselFun::Kind::SECOND, 0);
	cout << "Answer: " << fun->get_value(M_PI/2);
	system("read -p 'Press Enter to continue...' var");
	return 0;
}