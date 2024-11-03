#include<vector>
#include"Parser.h"
#include"Sequence.h"

using namespace flowshop;

int main() {
	vector<Job3M> v = Parser::toJobs("<4.5,5,6><1,2.5,3><7,8,9.5><10,12.5,3>");
	Sequence S(v);
	cout << S.toString() << endl;
	S.add(Job3M(2, 9.1, 3));
	cout << S.toString() << endl;
	cout << S.getChargeMachine(0) << endl;
	
}
