#include "Sequence.h"

namespace flowshop {
	// Constructeur par d�faut
	Sequence::Sequence() {};

	// Constructeur prenant un vecteur de jobs
	Sequence::Sequence(const vector<Job3M>& js) : _jobs(js) {};

	// M�thode toString
	string Sequence::toString() const {
		stringstream ss;
		for (const Job3M& job : _jobs) {
			ss << job.toString() << " ";
		}
		return ss.str();
	};

	// Ajoute un job � la s�quence
	void Sequence::add(Job3M job) {
		_jobs.push_back(job);
	};

	// Retourne la taille de la s�quence
	unsigned Sequence::getSize() const {
		return _jobs.size();
	};

	// Calcule la charge totale pour une machine donn�e
	double Sequence::getChargeMachine(unsigned i) const {
		double charge = 0;
		for (unsigned j = 0; j < 3; j++) {
			charge += _jobs[i].getDureeMachine(j); // Additionne la dur�e pour chaque machine
		}
		return charge;
	}

	// double Sequence::getMakespan() const{}

	// vector<double> Sequence::getProfil() const{}

	// Acc�de � un job
	Job3M Sequence::getJob(unsigned i) const {
		return _jobs[i];
	}

	// Accesseur constant
	Job3M Sequence::operator[](int i) const {
		if (i >= 0 && i < _jobs.size())
			return _jobs[i];
		else throw "indice invalide";
	}

	// Accesseur modifiable
	Job3M& Sequence::operator[](int i) {
		if (i >= 0 && i < _jobs.size())
			return _jobs[i];
		else throw "indice invalide";
	}
}
