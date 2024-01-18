#include<bits/stdc++.h>
using namespace std;

int main () {
    double usr_num1;
    int usr_num1_floor;
    int usr_num1_ceil;
    int usr_num1_round;

    cin >> usr_num1;

    usr_num1_floor = floor(usr_num1);
    int usr_num1_floor_fix = (int) usr_num1_floor;
    usr_num1_ceil = ceil(usr_num1);
    int usr_num1_ceil_fix = (int) usr_num1_ceil;
    usr_num1_round = round(usr_num1);
    int usr_num1_round_fix = (int) usr_num1_round;


    cout <<fixed<< usr_num1_floor_fix << " ";
    cout <<fixed<< usr_num1_ceil_fix << " ";
    cout <<fixed<< usr_num1_round_fix << endl;

    return(0);
}