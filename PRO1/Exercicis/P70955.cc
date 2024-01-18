#include<bits/stdc++.h>
using namespace std;

int main () {
    int years = 0, days = 0, hours = 0, minutes = 0, seconds = 0;

    cin >> years >> days >> hours >> minutes >> seconds;

    cout << (seconds)+(minutes*60)+(hours*3600)+(days*86400)+(years*31536000) << endl;
}