#pragma once
#include "Sommet.h"
#include <iostream>
#include <vector>

using namespace std;

class Graphe {

private:

	vector<Sommet*> tabSommets;
	bool isSommetIn(Sommet a);

public:
	Graphe();
	Sommet* getSommet(string name);
	void setNewArc(Sommet* predecesseur, Sommet* successeur);
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
	void enregistrerGraphe(Graphe g, string nomFichier);

    //Faire
};




