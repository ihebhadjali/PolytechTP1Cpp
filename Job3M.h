#pragma once
#include<vector>
#include<string>
#include"Matrice.h"
#include"Rmax.h"

using namespace std;
using namespace math;

namespace flowshop {
	class Job3M
	{
	private:
		std::vector<double> _durees;
	public:
		Job3M(double t1, double t2, double t3);
		double getDureeMachine(int i) const;
		double operator[](int i) const;
		double& operator[](int i);
		string toString() const;
		Matrice<Rmax> getMatrice() const;
	};
}

