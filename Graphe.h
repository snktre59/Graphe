#pragma once
#include "Sommet.h"
#include <iostream>
#include <vector>

using namespace std;

class Graphe {

private:

	vector<Sommet*> tabSommets;
	bool isSommetIn(Sommet * a);

public:
	//Constructeur
	Graphe();
	//Récupères un sommet selon nom
	Sommet* getSommet(string name);
	//Définit une liaison entre les deux sommets
	void setNewArc(Sommet* predecesseur, Sommet* successeur);
	//retourne le nombre de sommets inclus dans le graphe
	int getNbSommets();
	//Ajoute un sommet au graphe
	void setNewSommet(Sommet* a);
	//Génère un sommet et l'ajoute au graphe
	void setNewSommet(string name);
	//Supprime le sommet
	void delSommet(Sommet* a);
	//Supprime le sommet avec le nom
	void delSommet(string name);
	//Affiche les sommet du graphe
	void afficherSommets();
	//Retourne l'ensemble des sommets du graphe
	vector<Sommet*> getTabSommets();
	//Retourne le sommet à l'index
	Sommet* getTabIndexSommets(int i);
	//Retourne vrai si les sommets sont connectés, faux sinon
	bool estConnecte(Sommet* a, Sommet* b);
	//Affiche si a est prédécesseur de b, ou b est prédécesseur de a
	void estPredecesseur(Sommet* a, Sommet* b);
	//Affiche si a est successeur de b, ou b est successeur de a
	void estSuccesseur(Sommet* a, Sommet* b);
	//Retourne le degré entrant d'un sommet à l'index i
	int getDegreEntrant(int i);
	//Retourne le degré sortant d'un sommet à l'index i
	int getDegreSortant(int i);
	// Enregistre le graphe dans un fichier
	void enregistrerGraphe(Graphe g, string nomFichier);

    //Faire
};




