#include <iostream>
#include "Graphe.h"
#include "Sommet.h"

using namespace std;

int main() {
    // Instanciation du graphe
    Graphe g;

    // Instanciation de sommets au graphe
    Sommet A("A");
    Sommet B("B");
    Sommet C("C");
    Sommet D("D");
    Sommet E("E");

    // Définition des prédecesseurs et successeurs du sommet A
    A.setSuccesseur(B);
    A.setPredecesseur(C);
    A.setPredecesseur(D);

    // Définition des prédecesseurs et successeurs du sommet A
    B.setPredecesseur(A);
    B.setPredecesseur(E);
    B.setSuccesseur(C);

    // Définition des prédecesseurs et successeurs du sommet A
    C.setPredecesseur(B);
    C.setPredecesseur(D);
    C.setSuccesseur(A);
    C.setSuccesseur(E);
    C.setSuccesseur(D);

    // Définition des prédecesseurs et successeurs du sommet A
    D.setPredecesseur(C);
    D.setSuccesseur(A);
    D.setSuccesseur(D);

    // Définition des prédecesseurs et successeurs du sommet A
    E.setPredecesseur(C);
    E.setSuccesseur(B);
    E.getTabPredecesseurs();


    g.setNewSommet(&A);
    g.setNewSommet(&B);
    g.setNewSommet(&C);
    g.setNewSommet(&D);
    g.setNewSommet(&E);

    // Affiche la liste des sommet présents sur le graphe
    g.afficherSommets();

    // Test si le sommet C est le predecesseur du sommet D
    g.estPredecesseur(C, D);

    // Enregistrement du graphe au format .TXT avec pour nom la valeur passée en second paramètre
    g.enregistrerGraphe(g, "Testi");
    return 0;
}