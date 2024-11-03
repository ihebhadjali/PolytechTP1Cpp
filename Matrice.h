#pragma once
#include <vector>
#include <string>
#include <sstream>

namespace math
{

    // D�finition d'une classe template pour repr�senter une matrice
    template <class T>
    class Matrice
    {
    private:
        // Repr�sentation de la matrice comme un vecteur de vecteurs
        std::vector<std::vector<T>> _mat;

    public:
        // Constructeur de la matrice, prenant le nombre de lignes et de colonnes
        Matrice(unsigned li, unsigned co) : _mat(li, std::vector<T>(co))
        {
            // Si le nombre de lignes ou de colonnes est z�ro, redimensionner � 1x1
            if (li == 0 || co == 0) {
                _mat.resize(1, std::vector<T>(1));
            }
        }

        // M�thode pour convertir la matrice en cha�ne de caract�res
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

        // Op�rateur d'indexation pour acc�der et modifier un �l�ment
        T& operator()(unsigned li, unsigned co) { return _mat.at(li).at(co); }

        // Op�rateur d'indexation pour acc�der � un �l�ment (version constante)
        T operator()(unsigned li, unsigned co) const { return _mat.at(li).at(co); }

        // Op�rateur pour additionner deux matrices
        Matrice operator+(const Matrice<T>& m) const
        {
            Matrice<T> res(*this); // Cr�e une copie de la matrice actuelle
            for (unsigned i = 0; i < getLignes(); i++)
            {
                for (unsigned j = 0; j < getColonnes(); j++)
                {
                    res(i, j) = res(i, j) + m(i, j);
                }
            }
            return res;
        }

        // Op�rateur pour multiplier deux matrices
        Matrice<T> operator*(const Matrice<T>& m) const
        {
            // Cr�e une matrice r�sultat de dimensions appropri�es
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

        // M�thode pour obtenir le nombre de lignes
        unsigned getLignes() const { return _mat.size(); }

        // M�thode pour obtenir le nombre de colonnes
        unsigned getColonnes() const { return _mat[0].size(); }
    };

}
