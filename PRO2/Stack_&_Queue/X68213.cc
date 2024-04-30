#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// -1 --> Afegir llibre a la N categoria
void addBook(vector< stack<string> >& categories) {
    int cat;
    string titol;
    cin >> titol >> cat;
    categories[cat-1].push(titol);
}

// -2 --> Retirar X llibres de la N categoria
void removeBooks(vector< stack<string> >& categories) {
    int cat, quant;
    cin >> quant >> cat;
    for (int i = 0; i<quant; i++) categories[cat-1].pop();
}

// -3 --> Mostrar llibres de la N categoria
void showBooks(vector< stack<string> >& categories) {
    int cat;
    cin >> cat;
    cout << "Pila de la categoria " << cat << endl;
    stack<string> temp = categories[cat-1];
    while (!temp.empty()) cout << temp.top() << endl, temp.pop();
    cout << endl;
}

int main () {
    // Crear vector mida N de stacks
    int usr_quant_cat;
    cin >> usr_quant_cat;
    vector< stack<string> > categories(usr_quant_cat);

    int usr_op;
    while (cin >> usr_op) {
        if (usr_op==-1) addBook(categories);
        else if (usr_op==-2) removeBooks(categories);
        else if (usr_op==-3) showBooks(categories);
        else break;
    }
}
