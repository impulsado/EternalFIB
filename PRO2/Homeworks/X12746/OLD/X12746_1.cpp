#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    string command;
    map<int,int> mapa;
    int offset = 0;
    int size = 0;
    
    while (cin >> command) {
        if (command == "v.push_back(") {
            int num;
            string ending;
            cin >> num; cin >> ending; // Això consumeix el ");"
            mapa[offset+size] = num;
            size++;
        } 
        else if (command == "v.push_front(") {
            int num;
            string ending;
            cin >> num; cin >> ending; // Això consumeix el ");"
            offset--;
            mapa[offset] = num;
            size++;
        } 
        else if (command == "v.pop_front();") {
            if (size>0) {
                mapa.erase(offset);
                offset++;
                size--;
            }
        } 
        else if (command == "v.pop_back();") {
            if (size>0) {
                mapa.erase(offset+size-1);
                size--;
            }
        } 
        else if (command == "v.resize(") {
            int newsize;
            string ending;
            cin >> newsize; cin >> ending; // Això consumeix el ");"
            
            while (size > newsize) {
                if (size > 0) {
                    mapa.erase(offset + size - 1);
                    size--;
                }
            }
            // Si se aumenta el tamaño, simplemente ajustamos 'size' sin insertar ceros.
            if (newsize > size) {
                size = newsize;
            }
        } 
        else if (command == "cout<<v[") {
            int index;
            string ending;
            cin >> index; cin >> ending; // Això consumeix el "];"
            if (index < size) {
                if (mapa.find(offset + index) != mapa.end()) {
                    cout << mapa[offset + index] << endl;
                } else {
                    cout << "0" << endl;
                }
            }
        } 
        else if (command == "cout<<v;") {
            for (int i = 0; i < size; i++) {
                if (i > 0) cout << ",";
                if (mapa.find(offset + i) != mapa.end()) {
                    cout << mapa[offset + i];
                } else {
                    cout << "0";
                }
            }
            cout << endl;
        } 
        else if (command == "v[") {
            int index, num;
            string mid, ending;
            cin >> index; cin >> mid; cin >> num; cin >> ending; // Això consumeix el ";"
            mapa[offset + index] = num;
        } 
        else if (command == "//") {
            string comment;
            getline(cin, comment);
            cout << "//" << comment << endl;
        } 
        else {
            cout << "Wrong command '" << command << "'" << endl;
            string discard;
            getline(cin, discard);
        }
    }
}