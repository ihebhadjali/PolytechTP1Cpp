#include "Job3M.h"

using namespace math;

namespace flowshop {

	// Constructeur initialisant
	Job3M::Job3M(double t1, double t2, double t3) : _durees{ t1, t2, t3 } {};

	// Retourne la durée associée à une machine spécifique
	double Job3M::getDureeMachine(int i) const {
		return _durees[i];
	};

	// Accesseur en lecture pour une durée via l'opérateur []
	double Job3M::operator[](int i) const {
		if (i >= 0 && i < 3)
			return _durees[i];
		else
			throw "indice invalide"; // Lance une exception en cas d'indice invalide
	}

	// Accesseur en écriture pour une durée via l'opérateur []
	double& Job3M::operator[](int i) {
		if (i >= 0 && i < 3)
			return _durees[i];
		else
			throw "indice invalide"; // Lance une exception en cas d'indice invalide
	}

	// Retourne une représentation en chaîne de caractères des durées sous la forme "< d1, d2, d3 >"
	string Job3M::toString() const{
		stringstream ss;
		ss << " < " << _durees[0];
		for (int i = 1; i < _durees.size(); i++)
			ss << " , " << _durees[i];
		ss << ">";
		return ss.str();
	}

	Matrice<Rmax> Job3M::getMatrice() const {
		double d1 = _durees[0];
		double d2 = _durees[1];
		double d3 = _durees[2];

		// Initialise une matrice 3x3 pour les calculs en algèbre (max, +)
		Matrice<Rmax> mat(3, 3);

		// Remplissage de la matrice
		mat(0, 0) = d1;
		mat(0, 1) = d1 + d2;
		mat(0, 2) = d1 + d2 + d3;
		mat(1, 0) = 0;
		mat(1, 1) = d2;
		mat(1, 2) = d2 + d3;
		mat(2, 0) = -d2;
		mat(2, 1) = 0;
		mat(2, 2) = d3;

		return mat;
	}
}
