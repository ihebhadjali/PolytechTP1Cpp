#include "Parser.h"
#include <regex>

using namespace std;

namespace flowshop {
    vector<Job3M> Parser::toJobs(const string& s) {
        vector<Job3M> jobs; // Vecteur pour stocker les objets Job3M créés

        // Définition de l'expression régulière pour capturer les durées des jobs
        regex rxJob(R"(<(\d+(\.\d+)?),(\d+(\.\d+)?),(\d+(\.\d+)?)>)");

        smatch m; // Variable pour stocker les résultats de la recherche regex
        string str = s; // Copie de la chaîne d'entrée pour la manipulation

        // Boucle tant qu'il y a des correspondances dans la chaîne
        while (regex_search(str, m, rxJob)) {

            // Création d'un objet Job3M avec les durées extraites de la correspondance
            jobs.push_back(Job3M(stod(m[1].str()), stod(m[3].str()), stod(m[5].str())));

            // Avancer dans `str` pour trouver les prochaines correspondances
            str = m.suffix().str();
        }
        return jobs;
    };
}
