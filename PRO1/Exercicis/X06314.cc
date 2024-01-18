#include <iostream>
using namespace std;

int main () {
    bool is_first = true;
    int usr_num, main_num, last_num, counter, main_suma, suma;

    main_num = last_num = counter = main_suma = suma = 0;

    while (cin >> usr_num) {
        if (usr_num == 0 and is_first) {
            main_suma = suma; 
            main_num = last_num;
            is_first = false;
            suma = last_num = 0;
        }
        else if (usr_num == 0 and not is_first) {
            if ((main_suma == suma and main_num == last_num) or (suma == 0 and last_num == 0)) counter++;
            suma = last_num = 0; // reset
        } else {
            suma = suma + usr_num;
            last_num = usr_num;
        }
    }

    cout << counter << endl;
}