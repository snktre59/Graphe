//
// Created by Nicolas PAMART on 24/09/15.
//

#ifndef GRAPHESV2_SOMMET_H
#define GRAPHESV2_SOMMET_H

#include <iostream>
#include <vector>

using namespace std;


class Sommet {

private:
    string nom;
    vector<Sommet> predecesseurs;
    vector<Sommet> successeurs;

public:

    Sommet(string nom);

    bool operator==(Sommet const& a) const;

    bool estPredecesseur(Sommet a);

    bool estSuccesseur(Sommet a);

    /** GETTERS **/
    string getNom();

    vector<Sommet> getTabPredecesseurs();

    vector<Sommet> getTabSuccesseurs();

    Sommet getSucesseur(int i);

    Sommet getPredecesseur(int i);

    /** SETTERS **/

    void setPredecesseur(Sommet& a);

    void setSuccesseur(Sommet& a);

    void setNom(std::string nom);


};


#endif //GRAPHESV2_SOMMET_H
