#include <iostream>

using namespace std;

template <typename T > class Arbre {
private :
    struct node_arbre {
        T info ;
        node_arbre * segE ;
        node_arbre * segD ;
    };
    node_arbre * primer_node ;
    static void esborra_node_arbre ( node_arbre * m );

public :
    // Pre: p.i. = A
    // Post: el p.i. és A escorat
    void escora () {
        int pes = 0;
        int mida = 0;
        escora_rec(primer_node, pes, mida);
    }

    // Pre: cert
    // Post: la jerarquia de nodes a partir d'n està escorada
    static void escora_rec (node_arbre* n, int& pes, int& mida) {
        // === CAS BASE
        if (n==nullptr) pes = mida = 0;
        else {
            int pesE, pesD, midaE, midaD;
            escora_rec(n->segE, pesE, midaE);
            escora_rec(n->segD, pesD, midaD);
            if (pesD<pesE or (pesD==pesE and midaD<midaE)) {
                node_arbre* aux;
                aux = n->segE;
                n->segE = n->segD;
                n->segD = aux;
            }
            pes = n->info + pesE + pesD;
            mida = 1 + midaE + midaD;
        }
    }
};