#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct Assignatura {
    string nom;                 // Nom de l’assignatura
    double nota;                // Entre 0 i 10, -1 indica NP
};

struct Alumne {
    string nom;                 // Nom de l’alumne
    int dni;                    // DNI de l’alumne
    vector<Assignatura> ass;    // Llista d’assignatures de l’alumne
};

double nota(const vector<Alumne>& alums, int dni, string nom) {
    for (int i = 0; i<alums.size(); i++) {
        if (alums[i].dni==dni) {
            vector<Assignatura> assignatures;
            assignatures = alums[i].ass;
            for (int j = 0; j<assignatures.size(); j++) {
                if (assignatures[j].nom==nom) return assignatures[j].nota;
            }
        }
    }
    return -1;
}

double mitjana(const vector<Assignatura>& ass) {
    int counter = 0;
    double suma = 0;

    for (int i = 0; i<ass.size(); i++) {
        double nota = ass[i].nota;
        if (nota!=-1) suma += nota, counter++;
    }
    
    return suma/counter;
}

void compta(const vector<Alumne>& alums, int dni, string nom, int& com) {
    com = 0;

    // Agafar la nota que han de superar
    double nota_main = nota(alums,dni,nom);

    // Mirar la mitja de cada alumne
    for (int i = 0; i<alums.size(); i++) {
        double nota = mitjana(alums[i].ass);
        if (nota>nota_main) com++;
    }
    cout << com << endl;
}

int main() {
  int n;
  cin >> n;
  vector<Alumne> stu(n);
  Alumne stud;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> stud.nom >> stud.dni >> x;
    vector<Assignatura> subj(x);
    Assignatura sub;
    for (int j = 0; j < x; ++j) {
      cin >> sub.nom >> sub.nota;
      subj[j] = sub;
    }
    stud.ass = subj;
    stu[i] = stud;
  }
  int counter;
  int dni;
  string nom;
  while (cin >> dni and cin >> nom) {
    compta(stu,dni,nom,counter);
  }
}