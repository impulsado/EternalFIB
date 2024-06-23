#include <iostream>
#include <map>
#include <set>
using namespace std;

int main () {
    map<string,set<string>> alumnesdeasig;
    map<string,set<string>> asigdealumnes;
    string command, name, assig;

    while (cin >> command) {
        if (command == "ENROLL") {
            cin >> name >> assig;
            alumnesdeasig[assig].insert(name);
            asigdealumnes[name].insert(assig);
        }
        else if (command == "QUIT") {
            cin >> name >> assig;
            // Eliminar Alumne d'una assig
            auto it1 = alumnesdeasig[assig].find(name);
            if (it1!=alumnesdeasig[assig].end()) alumnesdeasig[assig].erase(it1);

            // Eliminar Assig d'un alumne
            auto it2 = asigdealumnes[name].find(assig);
            if (it2!=asigdealumnes[name].end()) asigdealumnes[name].erase(it2);
        }
        else if (command == "SUBJECTSOFSTUDENT") {
            cin >> name;
            if (!asigdealumnes[name].empty()) {
                auto it2 = asigdealumnes[name].begin();
                cout << *it2;
                it2++;
                while (it2!=asigdealumnes[name].end()) {
                    cout << ' ' << *it2;
                    it2++;
                }
            }
            cout << endl;
        }
        else if (command == "STUDENTSOFSUBJECT") {
            cin >> assig;
            if (!alumnesdeasig[assig].empty()) {
                auto it1 = alumnesdeasig[assig].begin();
                cout << *it1;
                it1++;
                while (it1!=alumnesdeasig[assig].end()) {
                    cout << ' ' << *it1;
                    it1++;
                }
            }
            cout << endl;
        }
    }
}