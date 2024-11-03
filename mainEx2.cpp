#include <iostream>
#include"Job3M.h"

using namespace std;
using namespace flowshop;
using namespace math;

int main() {
	Job3M J1(2, 4.5, 5);
	Job3M J2(3, 1, 7);
	cout << "J1=" << J1.toString() << endl; // <2,4.5,5>
	cout << "J2=" << J2.toString() << endl; // <3,1,7>
	cout << J1.getDureeMachine(0) << endl; //2
	cout << J1[1] << endl; //4.5
	Matrice<Rmax> mJ1 = J1.getMatrice();
	cout << "mJ1=" << mJ1.toString() << endl; //[2 6.5 11.5;0 4.5 9.5;-4.5 0 5]
}