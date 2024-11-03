#pragma once
#include<vector>
#include"Job3M.h"

namespace flowshop {
	class Sequence
	{
	private:
		vector<Job3M> _jobs;
	public:
		Sequence();
		Sequence(const vector<Job3M>& js);
		string toString() const;
		void add(Job3M job);
		unsigned getSize() const;
		double getChargeMachine(unsigned i) const;
		//double getMakespan() const;
		//vector<double> getProfil() const;
		Job3M getJob(unsigned i) const;
		Job3M operator[](int i) const;
		Job3M& operator[](int i);
	};
}

