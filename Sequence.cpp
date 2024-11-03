#include "Sequence.h"

namespace flowshop {
	// Constructeur par défaut
	Sequence::Sequence() {};

	// Constructeur prenant un vecteur de jobs
	Sequence::Sequence(const vector<Job3M>& js) : _jobs(js) {};

	// Méthode toString
	string Sequence::toString() const {
		stringstream ss;
		for (const Job3M& job : _jobs) {
			ss << job.toString() << " ";
		}
		return ss.str();
	};

	// Ajoute un job à la séquence
	void Sequence::add(Job3M job) {
		_jobs.push_back(job);
	};

	// Retourne la taille de la séquence
	unsigned Sequence::getSize() const {
		return _jobs.size();
	};

	// Calcule la charge totale pour une machine donnée
	double Sequence::getChargeMachine(unsigned i) const {
		double charge = 0;
		for (unsigned j = 0; j < 3; j++) {
			charge += _jobs[i].getDureeMachine(j); // Additionne la durée pour chaque machine
		}
		return charge;
	}

	// double Sequence::getMakespan() const{}

	// vector<double> Sequence::getProfil() const{}

	// Accède à un job
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
