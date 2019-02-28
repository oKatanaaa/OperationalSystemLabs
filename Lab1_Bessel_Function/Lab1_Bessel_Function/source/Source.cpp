
#include <iostream>
#include "headers/Functions/SphercialBesselFun.h"
#include <cmath>

using namespace std;



int main() {
    int kind;
    int order;
    cout << "Enter kind(1, 2): ";
    cin >> kind;
    cout << "Enter order: ";
    cin >> order;
    Function* fun;
    if(kind == 1)
        fun = new SphercialBesselFun(SphercialBesselFun::Kind::FIRST, order);
    if(kind == 2)
	    fun = new SphercialBesselFun(SphercialBesselFun::Kind::SECOND, order);
	double x;
	cout << "Enter x: ";
	cin >> x;
	cout << "Answer: " << fun->get_value(x);
	system("read -p 'Press Enter to continue...' var");
	return 0;
}