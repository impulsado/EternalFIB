#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> VI;

int fer_num(const VI& vsol, int index) {
    int num = 0;
    int potencia = 1;

    while (index >= 0) {
        num += potencia*vsol[index];
        potencia *= 10;
        index--;
    }

    return num;
}

bool hi_ha_divisor(const VI& vdivisors, const int& num) {
    for (int divisor : vdivisors) if (num%divisor == 0) return true;

    return false;
}

void solve(const VI& vdivisors, VI& vsol, int index) {
    if (index == vsol.size()) {
        for (int num : vsol) cout << num;
        cout << endl;
        return;
    }

    for (int digit = 0; digit <= 9; digit++) {
        vsol[index] = digit;
        int num = fer_num(vsol, index);
        if (hi_ha_divisor(vdivisors, num)) continue;
        solve(vdivisors, vsol, index+1);
    }
}

int main(void) {
    int usr_n, usr_num_divisors;
    while (cin >> usr_n >> usr_num_divisors) {
        VI vsol(usr_n);
        VI vdivisors(usr_num_divisors);
        for (int i = 0; i<usr_num_divisors; i++) cin >> vdivisors[i];

        int index = 0;
        solve(vdivisors, vsol, index);
        cout << "----------" << endl;
    }
}