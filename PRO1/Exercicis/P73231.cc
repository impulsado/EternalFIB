#include <iostream>
using namespace std;

int max4(int a, int b, int c, int d) {
    int result, maxim;

    if (a>=b) {
      if (a>=c) maxim = a; else maxim = c;
    } else {
      if (b>=c) maxim = b; else maxim = c;
    }
    
    if (maxim>=d) result = maxim; else result = d;

    return result;
}


int main() {
    int a, b, c, d;
    while (cin >> a >> b >> c >> d) {
        cout << max4(a, b, c, d) << endl;
    }
    return 0;   
}
