#include <iostream>
#include <vector>
using namespace std;

bool mateixos_digits(int x, int y, int b) {
    bool candidat = true;
    vector<int> vNums(b,0);
    vector<int> vRes(b,0);
    int multi = x*y;

    while (multi!=0) {
        if (x!=0) vNums[x%b]++;
        if (y!=0) vNums[y%b]++;
        if (multi!=0) vRes[multi%b]++;
        x = x/b;
        y = y/b;
        multi = multi/b;
    }

    for (int i = 0; i<vNums.size(); i++) {
        if (vNums[i]!=vRes[i]) candidat = false;
    }

    return candidat;
}

void escriu(int n, int b) {
    vector<int> vNum;
    int digit;

    while (n!=0) {  // Guardar en vector (però està al revés)
        vNum.push_back(n%b);
        n = n/b;
    }

    for (int i = vNum.size()-1; i>=0; i--) {
        digit = vNum[i]%b;
        if (digit<10) cout << digit;
        else cout << char('A' + (digit-10));
    }
}

int main () {
    bool mateixos, candidat;
    int num1, num2, multi;

    while (cin >> num1 >> num2) {
        mateixos = candidat = false; // RESET
        cout << "solucions per a " << num1 << " i " << num2 << endl;
        for (int b = 2; b<=16; b++) {
            mateixos = mateixos_digits(num1,num2,b);
            if (mateixos) {
                multi = num1*num2;
                escriu(num1,b);
                cout << " * ";
                escriu(num2,b);
                cout << " = ";
                escriu(multi,b);
                cout << " (base " << b << ")" << endl;
                candidat = true;
            }
        }
        if (not candidat) cout << "cap" << endl;
        cout << endl;
    }
}