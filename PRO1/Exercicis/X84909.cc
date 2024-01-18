#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

struct Slot {
    vector<string> listsubjects;
    vector<string> listteachers;
};

typedef vector<vector<Slot>> TableSlots;
typedef vector<vector<int>> iMatrix;

int getNumDay(string name) {
    if (name == "monday") return 0;
    else if (name == "tuesday") return 1;
    else if (name == "wednesday") return 2;
    else if (name == "thursday") return 3;
    else return 4;  // Friday
}

void processData(TableSlots& generalINFO, iMatrix& classCounter, iMatrix& uniqueTeacherCounter, int hora_min, int hora_max, int& counter) {
    for (int dia = 0; dia < 5; dia++) {
        for (int hora = hora_min; hora < hora_max; hora++) {
            vector<string>& professors = generalINFO[dia][hora].listteachers;
            sort(professors.begin(), professors.end());
            
            int professorsUnics = 0;
            string nomUltimProfe = "";
            for (int i = 0; i < professors.size(); i++) {
                const string& nom_profe = professors[i];

                if (nom_profe != nomUltimProfe) {
                    professorsUnics++;
                    nomUltimProfe = nom_profe;
                }
            }

            uniqueTeacherCounter[dia][hora] = professorsUnics;
            classCounter[dia][hora] = generalINFO[dia][hora].listsubjects.size();

            // Comptar quantes hores requereixen canvi.
            if (classCounter[dia][hora] > uniqueTeacherCounter[dia][hora]) {
                counter += classCounter[dia][hora] - uniqueTeacherCounter[dia][hora];
            }
        }
    }
}

void askInformation(TableSlots& generalINFO, int& hora_min, int& hora_max, iMatrix& classCounter, iMatrix& uniqueTeacherCounter, int& counter) {
    string assignatura, professor, dia;
    int hora_inici, hora_final, num_dia;

    while (cin >> assignatura >> professor >> dia >> hora_inici >> hora_final) {
        num_dia = getNumDay(dia);

        for (int hora = hora_inici; hora < hora_final; hora++) {
            generalINFO[num_dia][hora].listsubjects.push_back(assignatura);
            generalINFO[num_dia][hora].listteachers.push_back(professor);
        }

        if (hora_inici < hora_min) hora_min = hora_inici;
        if (hora_final > hora_max) hora_max = hora_final;
    }

    processData(generalINFO, classCounter, uniqueTeacherCounter, hora_min, hora_max, counter);
}

void showTable(iMatrix matriu, int primera_hora, int ultima_hora, string titol) {
    cout << "number of " << titol << " per slot:" << endl;
    cout << setw(2) << right << "h" << setw(10) << "monday" << setw(10) << "tuesday" << setw(10) << "wednesday" << setw(10) << "thursday" << setw(10) << "friday" << endl;

    for (int hour = primera_hora; hour < ultima_hora; hour++) {
        cout << setw(2) << right << hour;
        for (int day = 0; day < 5; day++) {
            cout << setw(10) << right << matriu[day][hour];
        }
        cout << endl;
    }
}

int main() {
    TableSlots generalINFO(5, vector<Slot>(24));
    iMatrix classCounter(5, vector<int>(24, 0));
    iMatrix uniqueTeacherCounter(5, vector<int>(24, 0));
    int primera_hora = 24, ultima_hora = 0; 
    int horesConflictives = 0;

    askInformation(generalINFO, primera_hora, ultima_hora, classCounter, uniqueTeacherCounter, horesConflictives);

    showTable(classCounter, primera_hora, ultima_hora, "subjects");
    showTable(uniqueTeacherCounter, primera_hora, ultima_hora, "teachers");

    cout << "number of replacements needed to avoid conflicts:" << endl << horesConflictives << endl;
    return 0;
}