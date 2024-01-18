#include<bits/stdc++.h>
using namespace std;

int check_horitzontal (char moviment) {
    int tmp_horitzontal=0;

    if (moviment=='e') tmp_horitzontal = 1;
    if (moviment=='o') tmp_horitzontal = -1;

    return tmp_horitzontal;
}

int check_vertical (char moviment) {
    int tmp_vertical=0;

    if (moviment=='n') tmp_vertical = -1;
    if (moviment=='s') tmp_vertical = 1;

    return tmp_vertical;
}

int main () {
    int x_pos=0, y_pos=0;
    char usr_movement;

    while (cin >> usr_movement) {
        if (usr_movement == 'e' or usr_movement == 'o') x_pos = x_pos + check_horitzontal(usr_movement);
        if (usr_movement == 'n' or usr_movement == 's') y_pos = y_pos + check_vertical(usr_movement);
    }

    cout << "(" << x_pos << ", " << y_pos << ")" << endl;
}