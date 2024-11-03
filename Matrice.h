#pragma once
#include <vector>
#include <string>
#include <sstream>

namespace math
{

    // Définition d'une classe template pour représenter une matrice
    template <class T>
    class Matrice
    {
    private:
        // Représentation de la matrice comme un vecteur de vecteurs
        std::vector<std::vector<T>> _mat;

    public:
        // Constructeur de la matrice, prenant le nombre de lignes et de colonnes
        Matrice(unsigned li, unsigned co) : _mat(li, std::vector<T>(co))
        {
            // Si le nombre de lignes ou de colonnes est zéro, redimensionner à 1x1
            if (li == 0 || co == 0) {
                _mat.resize(1, std::vector<T>(1));
            }
        }

        // Méthode pour convertir la matrice en chaîne de caractères
        std::string toString() const
        {
            std::stringstream ss;
            ss << "[";
            for (unsigned i = 0; i < _mat.size(); i++)
            {
                for (unsigned j = 0; j < _mat[0].size(); j++)
                {
                    ss << _mat[i][j];
                    if (j != _mat[0].size() - 1) ss << " ";
                }
                if (i != _mat.size() - 1) ss << ";";
            }
            ss << "]";
            return ss.str();
        }

        // Opérateur d'indexation pour accéder et modifier un élément
        T& operator()(unsigned li, unsigned co) { return _mat.at(li).at(co); }

        // Opérateur d'indexation pour accéder à un élément (version constante)
        T operator()(unsigned li, unsigned co) const { return _mat.at(li).at(co); }

        // Opérateur pour additionner deux matrices
        Matrice operator+(const Matrice<T>& m) const
        {
            Matrice<T> res(*this); // Crée une copie de la matrice actuelle
            for (unsigned i = 0; i < getLignes(); i++)
            {
                for (unsigned j = 0; j < getColonnes(); j++)
                {
                    res(i, j) = res(i, j) + m(i, j);
                }
            }
            return res;
        }

        // Opérateur pour multiplier deux matrices
        Matrice<T> operator*(const Matrice<T>& m) const
        {
            // Crée une matrice résultat de dimensions appropriées
            Matrice<T> res(getLignes(), m.getColonnes());
            for (unsigned i = 0; i < res.getLignes(); i++)
            {
                for (unsigned j = 0; j < res.getColonnes(); j++)
                {
                    for (unsigned k = 0; k < getColonnes(); k++)
                    {
                        res(i, j) = res(i, j) + (*this)(i, k) * m(k, j);
                    }
                }
            }
            return res;
        }

        // Méthode pour obtenir le nombre de lignes
        unsigned getLignes() const { return _mat.size(); }

        // Méthode pour obtenir le nombre de colonnes
        unsigned getColonnes() const { return _mat[0].size(); }
    };

}
