#include "Parser.h"
#include <regex>

using namespace std;

namespace flowshop {
    vector<Job3M> Parser::toJobs(const string& s) {
        vector<Job3M> jobs; // Vecteur pour stocker les objets Job3M cr��s

        // D�finition de l'expression r�guli�re pour capturer les dur�es des jobs
        regex rxJob(R"(<(\d+(\.\d+)?),(\d+(\.\d+)?),(\d+(\.\d+)?)>)");

        smatch m; // Variable pour stocker les r�sultats de la recherche regex
        string str = s; // Copie de la cha�ne d'entr�e pour la manipulation

        // Boucle tant qu'il y a des correspondances dans la cha�ne
        while (regex_search(str, m, rxJob)) {

            // Cr�ation d'un objet Job3M avec les dur�es extraites de la correspondance
            jobs.push_back(Job3M(stod(m[1].str()), stod(m[3].str()), stod(m[5].str())));

            // Avancer dans `str` pour trouver les prochaines correspondances
            str = m.suffix().str();
        }
        return jobs;
    };
}
