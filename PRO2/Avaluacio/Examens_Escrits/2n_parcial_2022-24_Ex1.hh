#include <iostream>

using namespace std;

template <class T > class Llista {
private :
    struct node_llista {
        T info ;
        int freq ; // camp afegit
        node_llista* seg;
        node_llista* ant;
    };
    int longitud;
    node_llista* primer_node;
    node_llista* ultim_node;
    node_llista* act;
public :
    int esborrar(const T& valor, int quantitat) {
        act = nullptr;
        node_llista* n;
        n = primer_node;
        bool trobat = false;
        while (n != nullptr and not trobat) {
            if (n->info == valor) trobat = true;
            else n = n->seg;
        }
        int esborrats;
        if (n == nullptr) esborrats = 0;
        else {
            int queden;
            if (n->freq >= quantitat) esborrats = quantitat;  // Tot i que aqui hauria de ser ">" i no ">="
            else esborrats =  n->freq;
            queden = n->freq - esborrats;
            if (queden == 0) { // Cal esborrar el node
                if (longitud == 1) primer_node = ultim_node = nullptr;
                else if (n == primer_node) {
                    primer_node = primer_node->seg;
                    primer_node->ant = nullptr;
                }
                else if (n == ultim_node) {
                    ultim_node = ultim_node->ant;
                    ultim_node->seg = nullptr;
                }
                else {
                    n->ant->seg = n->seg;
                    n->seg->ant = n->ant;
                }
                delete n;
                longitud--;
            }
            else {
                n->freq = queden;
                node_llista* aux = primer_node; // Cercar on posar el node
                while ((aux!=nullptr) and (aux->freq < n->freq)) {
                    aux = aux->seg;
                }
                if (aux != n->seg) {  // Cal moure el node
                    // Deseganxar el node
                    if (n == primer_node) {
                        primer_node = n->seg;
                        primer_node->ant = nullptr;
                    }
                    else {
                        n->ant->seg = n->seg;
                        n->seg->ant = n->ant;
                    }
                    // Enganxar el node
                    if (aux == nullptr) {
                        // ultim_node->ant->seg = n; 
                        // Això és incorrecte. Imagina que la llista té 1 element, estaries intentant accedir al camp `seg` d'un nullptr.
                        
                        n->ant = ultim_node;
                        ultim_node->seg = n;
                        ultim_node = n;
                        n->seg = nullptr;  // o "ultim_node->seg = nullptr;" també seria correcte
                    }
                    else {
                        // num1 <-> aux =ENGANXAR=> num1 <-> n <-> aux
                        aux->ant->seg = n;
                        n->seg = aux;
                        n->ant = aux->ant;
                        aux->ant = n;
                    }
                }
            }
        }
        return esborrats;
    }
};