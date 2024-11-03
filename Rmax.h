#pragma once
#include <iostream>

namespace math
{
    class Rmax
    {
    private:
        double _val;

    public:
        // Constructeur par défaut
        Rmax();

        // Constructeur qui initialise _val avec une valeur donnée
        Rmax(double v);

        // Constructeur de recopie, permet de créer un nouvel objet Rmax à partir d'un existant
        Rmax(const Rmax& v);

        // Destructeur, utilisé pour libérer les ressources
        ~Rmax();

        double getVal() const;
        void setVal(double v);
        static double epsilon();

        // Surcharge de l'opérateur + pour additionner deux objets Rmax
        Rmax operator+(const Rmax& r) const;

        // Surcharge de l'opérateur * pour multiplier deux objets Rmax
        Rmax operator*(const Rmax& r) const;
    };

    // Surcharge de l'opérateur << pour permettre l'affichage de Rmax dans un flux de sortie
    std::ostream& operator<<(std::ostream& flot, const Rmax& r);
}
