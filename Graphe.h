//
// Created by Nicolas PAMART on 24/09/15.
//

#ifndef GRAPHESV2_GRAPHE_H
#define GRAPHESV2_GRAPHE_H

#include "Sommet.h"
#include <iostream>
#include <vector>

using namespace std;

class Graphe {

private:

    vector<Sommet*> tabSommets;

public:
    Graphe();
    int getNbSommets();
    void setNewSommet(Sommet* a);
	void setNewSommet(string name);
    void afficherSommets();
    vector<Sommet*> getTabSommets();
    Sommet getTabIndexSommets(int i);
    bool estConnecte(Sommet a, Sommet b);
    void estPredecesseur(Sommet a, Sommet b);
    void estSuccesseur(Sommet a, Sommet b);
    int getDegreEntrant(int i);
    int getDegreSortant(int i);
    void enregistrerGraphe(Graphe g, std::string nomFichier);
};


#endif //GRAPHESV2_GRAPHE_H
