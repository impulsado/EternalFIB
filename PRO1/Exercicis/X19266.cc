#include <bits/stdc++.h>
using namespace std;

int main () {
    int hora1, hora2, min1, min2;

    cin >> hora1 >> min1 >> hora2 >> min2;

    int horas, minutos;

    if (min1 > min2) {
        minutos = 60 - (min1 - min2);
        if (hora1 > hora2) {
            horas = 24 - (hora1 - hora2) - 1;
        } else if (hora1 < hora2) {
            horas = hora2 - hora1 - 1;
        } else {  // hora1 == hora2
            horas = 23;
        }
    } else if (min1 < min2) {
        minutos = min2 - min1;
        if (hora1 > hora2) {
            horas = 24 - (hora1 - hora2) - 1;
        } else if (hora1 < hora2) {
            horas = hora2 - hora1;
        } else {  // hora1 == hora2
            horas = 23;
        }
    } else {  // min1 == min2
        minutos = 0;
        if (hora1 > hora2) {
            horas = 24 - (hora1 - hora2);
        } else if (hora1 < hora2) {
            horas = hora2 - hora1;
        } else {  // hora1 == hora2
            horas = 0;
        }
    }

    if (horas < 10) cout << "0";
    cout << horas << ":";

    if (minutos < 10) cout << "0";
    cout << minutos << endl;

    return 0;
}