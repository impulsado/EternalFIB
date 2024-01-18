#include<bits/stdc++.h>
using namespace std;

int main () {
    int hours = 0, minutes = 0, seconds = 0;

    cin >> hours >> minutes >> seconds;

    // Algoritme
    seconds++;
    if (seconds > 59) seconds = 0, minutes++;
    if (minutes > 59) minutes = 0, hours++;
    if (hours > 23) hours = 0;

    // Mostrar Resultat
    // CUIDADO perque setfill necessita ' NO "
    cout << setw(2) << setfill('0') <<  hours << ":";
    cout << setw(2) << setfill('0') <<  minutes << ":";
    cout << setw(2) << setfill('0') <<  seconds << endl;
}