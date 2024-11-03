#pragma once
#include <iostream>

namespace math
{
    class Rmax
    {
    private:
        double _val;

    public:
        // Constructeur par d�faut
        Rmax();

        // Constructeur qui initialise _val avec une valeur donn�e
        Rmax(double v);

        // Constructeur de recopie, permet de cr�er un nouvel objet Rmax � partir d'un existant
        Rmax(const Rmax& v);

        // Destructeur, utilis� pour lib�rer les ressources
        ~Rmax();

        double getVal() const;
        void setVal(double v);
        static double epsilon();

        // Surcharge de l'op�rateur + pour additionner deux objets Rmax
        Rmax operator+(const Rmax& r) const;

        // Surcharge de l'op�rateur * pour multiplier deux objets Rmax
        Rmax operator*(const Rmax& r) const;
    };

    // Surcharge de l'op�rateur << pour permettre l'affichage de Rmax dans un flux de sortie
    std::ostream& operator<<(std::ostream& flot, const Rmax& r);
}
