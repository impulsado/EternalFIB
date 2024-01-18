#include<bits/stdc++.h>
using namespace std;

int main () {
    int usr_seconds, hours = 0, minutes = 0, seconds = 0;

    cin >> usr_seconds;

    // Algoritme
    if (usr_seconds >= 3600) hours = usr_seconds/3600;
    if (usr_seconds%3600 >= 60) minutes = (usr_seconds%3600)/60;
    seconds = (usr_seconds%3600)%60;

    // Mostrar Resultat
    cout << hours << " " << minutes << " " << seconds << endl;
}