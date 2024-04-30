#include<iostream>
#include<stack>
using namespace std;

int main () {
    char usr_char;
    int pos = 0, error_pos = 0;
    bool is_valid = true;
    stack<char> parentesis;

    while (cin >> usr_char and usr_char!='.') {
        pos++;

        // Deixar que l'usari acabi l'entrada de dades
        if (!is_valid) continue;
        
        // Afegir
        if (usr_char=='(' or usr_char=='[') parentesis.push(usr_char); 
        // Treure
        else if (!parentesis.empty() and (usr_char==')' or usr_char==']')) {  
            if ((usr_char==')' and parentesis.top()=='(')) parentesis.pop();
            else if ((usr_char==']' and parentesis.top()=='[')) parentesis.pop();
            else is_valid = false, error_pos = pos;
        }
        // Ordre incorrecte ")("
        else {
            is_valid = false;
            error_pos = pos;
        }
    }

    // Si no marca error pero la pila no esta buida es que hi ha parentesis oberts restants
    if (!parentesis.empty() and is_valid) is_valid = false, error_pos = pos;

    // Mostrar resultats
    if (is_valid) cout << "Correcte" << endl;
    else cout << "Incorrecte " << error_pos << endl;
}