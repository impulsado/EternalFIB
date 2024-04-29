#include <iostream>
#include <string>

using namespace std;
template <typename T>  // Això permet tindre tipus qualsevol (polimorfic)

class Stack {

private:
    struct Item {
        T value;
        Item* next;
    };
    // Point to the top of the stack. Its value is NULL if the stack is empty.
    Item* ptopitem;
    // Size (i.e., num elements in the stack)
    int _size;

    Item* copyItems(const Item* pitem) {
        if (pitem==NULL) return NULL;

        // ?? Com es que sap el tamany o quin es el tamany que reserva ??
        Item* pitemcopy = new Item();  // Reservar espai per a guardar el Item.
        pitemcopy->value = pitem->value;  // Guardar el valor al nou espai reservat.
        pitemcopy->next = copyItems(pitem->next);  // Copia de forma recursiva els elements de la llista
        return pitemcopy;
    }

    void deleteItems(Item* pitem) {
        // Base Case
        if (pitem==NULL) return;

        // General Case
        deleteItems(pitem->next);  // Va a l'element del final i elimina cap a l'inici 
        delete pitem;  // ?? Com funciona això ??
    }


public:

    int size() {
        return _size;  // Té '_' perquè és privat. Cosa d'història de programació
        // "__" privat del sistema
    }

    bool empty() {
        return _size==0;
        /* Equivalències
        return ptopitem == NULL;
        return size() == 0; // Però el compilador és intel·ligent i farà la de _size == 0;
        */
    }

    Stack() {
        ptopitem = NULL;
        _size = 0;
    }

    // Fer còpia del stack que rebo
    Stack(const Stack& s) {
        ptopitem = copyItems(s.ptopitem);
        // Un stack pots accedir a camps privats però si és desde un altre lloc (Classe,funcions,...) ja no.
        _size = s._size;
    }

    // Retornar la memòria que has fet servir (allocatar)
    ~Stack() {
        deleteItems(ptopitem);
    }

    void push(T value) {
        // 1. Alocatar nou item
        Item* pitemvalue = new Item();
        // 2. Copiar valor del nou item
        pitemvalue->value = value;
        // 3. Linkem nou item amb el top antic
        pitemvalue->next = ptopitem;
        // 4. Modifiquem el top item perque sigui aquest nou valor
        ptopitem = pitemvalue;
        // 5. Sumem el size per actualitzar la mida
        _size++;
    }

    void pop() {
        if (empty()) cerr << "Error: Cannot top an empty stack";
        else {
            // 1. Punter temporal al següent de la llista donat que el top l'eliminarem
            Item* ptr = ptopitem->next;
            // 2. Eliminem el top
            delete ptopitem;
            // 3. Assignem el nou top
            ptopitem = ptr;
            // 4. Controlem el size donat que hem eliminat un item
            _size--;
        }
    }

    T top() {
        if (empty()) {
            // cerr no li importa el buffer de sortida perquè al ser un error surt automàticament.
            // cout no i es fa servir per sortides regulars, no errors.
            // tots dos surten per la terminal així que a ulls pràctics són el mateix.
            cerr << "Error: Cannot top an empty stack";
        }
        else {
            return ptopitem;
        }
    }

    Stack& operator=(Stack s) {
        if (this == &s) return *this;  // Això és per quan diuen "s = s;" i aquí no fa falta fer res
        deleteItems(ptopitem);
        ptopitem = copyItems(s.ptopitem);
        _size = s._size;
        return *this;  //Aqui no retornem el punter sino el valor com a tal així que no és "incorrecte"
    }
};