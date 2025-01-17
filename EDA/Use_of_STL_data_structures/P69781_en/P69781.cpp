#include <iostream>
#include <map>
#include <list>

using namespace std;

int main() {
    int x, y, n;
    
    while (cin >> x >> y >> n) {
        bool ovf = false;
        bool found = false;
        list<int> llistat;
        map<int, bool> existeix;
        
        existeix[n] = true;
        llistat.push_back(n);

        while (not found and not ovf) {
            if (n%2 == 0) n = n/2 + x;
            else n = 3*n + y;

            if (existeix[n]) found = true;
            else if (n>100000000) ovf = true;
            
            existeix[n] = true;
            llistat.push_back(n);
        }
        
        if (not ovf) {
            found = false;
            int counter = 0;
            for (auto it = llistat.begin(); it!=llistat.end() and not found; it++) {
                counter++;
                if (*it == n) found = true;
            }
            cout << llistat.size() - counter << endl;
        }
        else cout << n << endl;
    }
}