#include <iostream>
#include "Graphe.h"
#include "Sommet.h"

using namespace std;

int main() {
    Graphe g;
    Sommet A("A");
    Sommet B("B");
    Sommet C("C");
    Sommet D("D");
    Sommet E("E");

    A.setSuccesseur(B);
    A.setPredecesseur(C);
    A.setPredecesseur(D);

    B.setPredecesseur(A);
    B.setPredecesseur(E);
    B.setSuccesseur(C);

    C.setPredecesseur(B);
    C.setPredecesseur(D);
    C.setSuccesseur(A);
    C.setSuccesseur(E);
    C.setSuccesseur(D);

    D.setPredecesseur(C);
    D.setSuccesseur(A);
    D.setSuccesseur(D);

    E.setPredecesseur(C);
    E.setSuccesseur(B);
    E.getTabPredecesseurs();

    g.setNewSommet(&A);
    g.setNewSommet(&B);
    g.setNewSommet(&C);
    g.setNewSommet(&D);
    g.setNewSommet(&E);

    g.afficherSommets();

    g.estPredecesseur(C, D);

    g.enregistrerGraphe(g, "Testi");
    return 0;
}