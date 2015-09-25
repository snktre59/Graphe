//
// Created by Nicolas PAMART on 24/09/15.
//

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

void Graphe::afficherSommets(){
    for (int i=0; i < this->tabSommets.size();i++){
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

bool Graphe::estConnecte(Sommet a, Sommet b) {
    return a.estPredecesseur(b) || a.estSuccesseur(b);
}

void Graphe::estPredecesseur(Sommet a, Sommet b){
    if(a.estPredecesseur(b)){
        cout << a.getNom() << " est le prédécesseur de " << b.getNom() << endl;
    } else {
        cout << a.getNom() << " n'est pas le prédécesseur de " << b.getNom() << endl;;
    }
}

void Graphe::estSuccesseur(Sommet a, Sommet b){
    if(a.estSuccesseur(b)){
        cout << a.getNom() << " est le successeur de " << b.getNom() << endl;
    } else {
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
    string const repertoire("/Users/nicolas/Desktop/C++/GraphesV2/");
    string const repertoireFichier(repertoire + nomFichier + ".txt");
    ofstream flux(repertoireFichier);

    if (flux) {
        flux << "Graphe : " << nomFichier << endl;
        flux << "Liste des sommets : " << endl;
        for(int i = 0 ; i < this->getNbSommets() ; i++){
            flux << this->getTabSommets()[i]->getNom();
        }
            flux << endl;
        flux << "Prédécesseurs : " << endl;
        for(int j = 0 ; j < this->getNbSommets() ; j++){
            flux << this->getTabSommets()[j]->getNom() << " : " << this->getTabSommets()[j]->getTabPredecesseurs().size() << endl;
        }
        flux << "Degré entrant : " << endl;
        for(int k = 0 ; k < this->getNbSommets() ; k++){
            flux << this->getTabSommets()[k]. << " : " << this->getTabSommets()[k]->getTabSuccesseurs().size() << endl;
        }
    } else {
        cout << "Un problème est survenu lors de l'écriture du fichier" << endl;
    }
}
