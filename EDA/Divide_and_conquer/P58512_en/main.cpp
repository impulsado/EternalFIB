#include <iostream>
using namespace std;

/*
Prof. Oak = m + f*days  // Interés simple
Bank = m*(1 + r/100)^days  // Interés compost

Sabem que resposta està entre 1 i 10^7
Anem al mig i comprovem i fem "binary search"
*/

long double power(long double base, int exp) {
    long double result = 1;
    while (exp>0) {
        if (exp%2 == 1) result = (base*result);
        base = (base*base);
        exp /= 2;
    }
    return result;
}

int minDays(double m, double f, double r) {
    int min = 1, max = 10000000;  // 10000000
    long double interes = (1 + r/100);
    
    while (min<=max) {
        int days = min + (max-min)/2;
        long double bank = m*power(interes,days);
        long double prof = m+(f*days);

        if (prof>bank) min = days+1;
        else if (prof<bank) max = days-1;
        else return days;
    }

    return min;
}

int main() {
    double money, charge_daily, rate;

    while (cin >> money >> charge_daily >> rate) {
        cout << minDays(money, charge_daily, rate) << endl;
    }
}