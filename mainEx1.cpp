#include <iostream>
#include "Rmax.h"
#include "Matrice.h"

using namespace math;
using namespace std;

int main() {
    Rmax a(2), b(1), c;

    // Affichage des résultats des opérations Rmax
    cout << (a + b) << endl; // Addition : max(2, 1) = 2
    cout << (a * b) << endl; // Multiplication : 2 + 1 = 3
    cout << c << endl; // Affiche epsilon
    cout << "eps=" << Rmax::epsilon() << endl; // Appelle la méthode de classe pour afficher epsilon

    // Création de matrices de type Rmax

    Matrice<Rmax> M1(2, 2), s(1, 2); // M1 est une matrice 2x2, s est une matrice 1x2
    // Initialisation des éléments de la matrice M1
    M1(0, 0) = 2; M1(0, 1) = 3; M1(1, 1) = 4; // M1 = [[2, 3], [eps, 4]]
    // Initialisation des éléments de la matrice s
    s(0, 0) = 1; s(0, 1) = 4; // s = [[1, 4]]

    // Affichage de la représentation sous forme de chaîne de la matrice M1
    cout << M1.toString() << endl; // Affiche la matrice M1 sous la forme [2 3; eps 4]
    // Affichage du produit de la matrice s et de M1
    cout << (s * M1).toString() << endl; // Affiche [3 8]
    // Affichage du produit de s et M1 deux fois
    cout << (s * M1 * M1).toString() << endl; // Affiche [5 12]

    // Exemple introductif de l'utilisation des matrices

    Matrice<Rmax> A(2, 2), B(2, 2); // Création de deux matrices 2x2
    // Initialisation des éléments de la matrice A
    A(0, 0) = 1.5; A(1, 0) = 2; A(1, 1) = 3.2; // A = [[1.5, eps], [2, 3.2]]
    // Initialisation des éléments de la matrice B
    B(0, 0) = 0; B(0, 1) = 1; B(1, 1) = 2; // B = [[0, 1], [eps, 2]]

    // Affichage de la somme des matrices A et B
    cout << (A + B).toString() << endl; // Affiche la somme A + B
    // Affichage du produit des matrices A et B
    cout << (A * B).toString() << endl; // Affiche le produit A * B

    return 0; // Fin du programme
}
