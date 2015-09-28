//#pragma once
//#include "stdafx.h"
#include "Graphe.h"
#include <fstream>

Graphe::Graphe() {
}

int Graphe::getNbSommets() {
	return this->tabSommets.size();
}

void Graphe::setNewSommet(Sommet* a) {
	this->tabSommets.push_back(a);
}

void Graphe::setNewSommet(string name){
	Sommet * nouveauSommetAvecUnNom;
	nouveauSommetAvecUnNom = new Sommet(name);
			this->tabSommets.push_back(nouveauSommetAvecUnNom);
}

void Graphe::setNewArc(Sommet* predecesseur, Sommet* successeur){
	if (isSommetIn(*predecesseur) && isSommetIn(*successeur)){
		cout << "Nouvel arc entre le sommet " << (*predecesseur).getNom() << " et le sommet " << (*successeur).getNom() << "." << endl;
		cout << "    " << predecesseur->getNom() << " -----> " << successeur->getNom() << endl;
		predecesseur->setSuccesseur(*successeur);
		successeur->setPredecesseur(*predecesseur);
	}
	else{
		cout << "Au moins l'un des sommets (" << predecesseur->getNom() << ", " << successeur->getNom() << ") n'est pas pr�sent dans le graphe, veuillez l'ajouter avant de d�finir l'arc." << endl;
	}

}
bool Graphe::isSommetIn(Sommet a){
	for (vector<Sommet *>::iterator i = this->tabSommets.begin(); i != this->tabSommets.end(); i++){
		if (**i == a){
			return true;
		}											
	}
	return false;
}

void Graphe::afficherSommets(){
	for (int i = 0; i < this->tabSommets.size(); i++){
		cout << this->tabSommets[i]->getNom() << ", ";
	}
	cout << endl;
}

vector<Sommet*> Graphe::getTabSommets(){
	return this->tabSommets;
}

Sommet Graphe::getTabIndexSommets(int i){
	return *this->tabSommets[i];
}

Sommet * Graphe::getSommet(string name){
	for (int i = 0; i < this->tabSommets.size(); i++){
		if (this->tabSommets[i]->getNom() == name) {
			return this->tabSommets[i];
		}
	}
	return NULL;
}

bool Graphe::estConnecte(Sommet a, Sommet b) {
	return a.estPredecesseur(b) || a.estSuccesseur(b);
}

void Graphe::estPredecesseur(Sommet a, Sommet b){
	if (a.estPredecesseur(b)){
		cout << a.getNom() << " est le prédécesseur de " << b.getNom() << endl;
	}
	else {
		cout << a.getNom() << " n'est pas le prédécesseur de " << b.getNom() << endl;;
	}
}

void Graphe::estSuccesseur(Sommet a, Sommet b){
	if (a.estSuccesseur(b)){
		cout << a.getNom() << " est le successeur de " << b.getNom() << endl;
	}
	else {
		cout << a.getNom() << " n'est pas le successeur de " << b.getNom() << endl;;
	}
}

int Graphe::getDegreEntrant(int i){
	return this->tabSommets[i]->getTabPredecesseurs().size();
}

int Graphe::getDegreSortant(int i) {
	return this->tabSommets[i]->getTabSuccesseurs().size();
}

void Graphe::enregistrerGraphe(Graphe g, string const nomFichier) {
	string const repertoire("/Users/nicolas/Desktop/C++/GraphesRepo/");
	string const repertoireFichier(repertoire + nomFichier + ".txt");
	ofstream flux(repertoireFichier);

	if (flux) {
		flux << "Graphe : " << nomFichier << endl;
		flux << "Liste des sommets : " << endl;
		for (int i = 0; i < this->getNbSommets(); i++){
			flux << this->getTabSommets()[i]->getNom();
		}
		flux << endl;
		flux << "Prédécesseurs : " << endl;
		for (int j = 0; j < this->getNbSommets(); j++){
			flux << this->getTabSommets()[j]->getNom() << " : " << this->getTabSommets()[j]->getTabPredecesseurs().size() << endl;
		}
		flux << "Degré entrant : " << endl;
		for (int k = 0; k < this->getNbSommets(); k++){
			flux << this->getTabSommets()[k]->getNom()  << " : " << this->getTabSommets()[k]->getTabSuccesseurs().size();
			flux << "(";
			for(int l = 0; l < this->getTabSommets()[k]->getTabSuccesseurs().size() ; l++){
				flux << this->getTabSommets()[k]->getTabPredecesseurs()[l].getNom();
			}
			flux << ")" << endl;
		}
		flux << "Degré sortant : " << endl;
		for (int k = 0; k < this->getNbSommets(); k++){
			flux << this->getTabSommets()[k]->getNom()  << " : " << this->getTabSommets()[k]->getTabPredecesseurs().size();
			flux << "(";
			for(int l = 0; l < this->getTabSommets()[k]->getTabPredecesseurs().size() ; l++){
				flux << this->getTabSommets()[k]->getTabPredecesseurs()[l].getNom();
			}
			flux << ")" << endl;
		}
	}
	else {
		cout << "Un problème est survenu lors de l'écriture du fichier" << endl;
	}
}
