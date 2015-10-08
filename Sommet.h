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
    // Nom du Sommet
    string nom;

    // Tableau des prédecesseurs du sommet
    vector<Sommet> predecesseurs;

    // Tableau des successeurs du sommet
    vector<Sommet> successeurs;

public:

    /**
     * Constructeur de la classe Sommet
     * Pramètres : Nom a attribuer au sommet
     */
    Sommet(string nom);

    /**
     * Redéfinition de la méthode de comparaison
     * Pramètres : Un sommet
     * Retour : true si le sommet passé en paramètre a le même nom que le sommet (this)
     */
    bool operator==(Sommet const& a) const;

    /**
     * Vérifie si le sommet passé en paramètre est un prédecesseur du sommet (this)
     * Pramètre : Le sommet que l'on veut tester
     * Retour : true si le sommet passé en paramètre est un prédecesseur du sommet (this)
     */
    bool estPredecesseur(Sommet a);

    /**
     * Vérifié si le sommet passé en paramètre est un successeur du sommet (this)
     * Paramètre : Le sommet que l'on veut tester
     * Retour : true si le sommet passé en paramètre est un successeur du sommet (this)
     */
    bool estSuccesseur(Sommet a);

    /** GETTERS **/

    /**
     * Retourne le nom du sommet
     */
    string getNom();

    /**
     * Retourne le tableau des prédecesseurs du sommet
     */
    vector<Sommet> getTabPredecesseurs();

    /**
     * Retourne le tableau des successeurs du sommet
     */
    vector<Sommet> getTabSuccesseurs();

    /**
     * Retourne le sommet successeur du sommet à l'index i
     */
    Sommet getSucesseur(int i);

    /**
     * Retourne le sommet prédecesseur du sommet à l'index i
     */
    Sommet getPredecesseur(int i);

    /** SETTERS **/

    /**
     * Défini un sommet en tant que prédecesseur
     */
    void setPredecesseur(Sommet& a);

    /**
     * Défini un sommet en tant que successeur
     */
    void setSuccesseur(Sommet& a);

    /**
     * Défini le nom du sommet
     */
    void setNom(string nom);


};


#endif //GRAPHESV2_SOMMET_H
