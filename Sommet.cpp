//
// Created by Nicolas PAMART on 24/09/15.
//

#include "Sommet.h"
#include <iostream>
#include <vector>

using namespace std;

Sommet::Sommet(string nom) {
    this->nom = nom;
    std::cout << "Le point " << this->nom << " a été instancié." << std::endl;
}

/** GETTERS **/
string Sommet::getNom(){
    return this->nom;
}

vector<Sommet> Sommet::getTabPredecesseurs(){
    return this->predecesseurs;
}

vector<Sommet> Sommet::getTabSuccesseurs(){
    return this->successeurs;
}

Sommet Sommet::getSucesseur(int i){
    return this->successeurs[i];
}

Sommet Sommet::getPredecesseur(int i){
    return this->predecesseurs[i];
}

/** SETTERS **/

void Sommet::setPredecesseur(Sommet& a) {
    if(!estPredecesseur(a)) {
        this->predecesseurs.push_back(a);
    }
}

void Sommet::setSuccesseur(Sommet& a) {
    if(!estSuccesseur(a)){
        this->successeurs.push_back(a);
    }
}

/** BOOLEANS **/

bool Sommet::estPredecesseur(Sommet a){
    for (vector<Sommet>::iterator i=this->predecesseurs.begin(); i != this->predecesseurs.end(); i++){
        if (*i == a){
            return true;
        }
    }
    return false;
}
bool Sommet::estSuccesseur(Sommet a){
    for (vector<Sommet>::iterator i=this->successeurs.begin(); i != this->successeurs.end(); i++){
        if (*i == a){
            return true;
        }
    }
    return false;
}

/** SURCHARGE D'OPERATEUR **/

bool Sommet::operator==(Sommet const& a) const {
    return a.nom == this->nom;
}