#pragma once
#include<string>
#include<vector>
#include"Job3M.h"

using namespace std;

namespace flowshop {
	class Parser
	{
	public:
		static vector<Job3M> toJobs(const string& s);
	};
}

