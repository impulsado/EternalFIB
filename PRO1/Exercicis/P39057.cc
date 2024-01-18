#include<bits/stdc++.h>
using namespace std;

int main ()  {
    // Definir format de la sortida de l'area (6 digits depres del punt decimal)
    cout.setf(ios::fixed);
    cout.precision(6);

    int usr_num;
    double area;
    string usr_desc;

    cin >> usr_num;

    while (usr_num > 0) {
        cin >> usr_desc;
        if (usr_desc == "rectangle") {
            double base, altura;
            cin >> base >> altura;

            area = base * altura;
        }

        if (usr_desc == "circle") {
            double radius;
            cin >> radius;

            area = radius * radius * M_PI;
        }

        cout << area << endl;
        usr_num = usr_num - 1;
    }
}