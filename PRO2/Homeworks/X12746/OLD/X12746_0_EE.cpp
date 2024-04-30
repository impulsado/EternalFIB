// 4.75s
#include <iostream>
#include <string>
#include <map>

using namespace std;


int main() {
    string command;
    map<int,int> mapa;
    int first_index = 0;
    int last_index = -1;  // Per si fan de primeres un push_back el guardi en mapa[0]
    
    while (cin >> command) {
        if (command == "v.push_back(") {
            int num;
            string ending;
            cin >> num; cin >> ending; // Això consumeix el ");"
            last_index++;
            mapa[last_index] = num;
        } 
        else if (command == "v.push_front(") {
            int num;
            string ending;
            cin >> num; cin >> ending; // Això consumeix el ");"
            first_index--;
            mapa[first_index] = num;
        } 
        else if (command == "v.pop_front();") {
            if (first_index<last_index) first_index++;
        } 
        else if (command == "v.pop_back();") {
            if (last_index>first_index) last_index--;
        } 
        else if (command == "v.resize(") {
            int newsize;
            string ending;
            cin >> newsize; cin >> ending; // Això consumeix el ");"
            
            int actualsize = last_index-first_index+1;
            if (actualsize<newsize) {
                last_index += (newsize-actualsize);
            }
            else if (actualsize>newsize) last_index = first_index+newsize-1;
            else continue; // Son iguals no fa falta fer res 
        } 
        else if (command == "cout<<v[") {
            int index;
            string ending;
            cin >> index; cin >> ending; // Això consumeix el "];"
            cout << mapa[first_index+index] << endl;
        } 
        else if (command == "cout<<v;") {
            cout << mapa[first_index];
            for (int i = first_index+1; i<=last_index; i++) cout << ',' << mapa[i];
            cout << endl;
        } 
        else if (command == "v[") {
            int index, num;
            string mid, ending;
            cin >> index; cin >> mid; cin >> num; cin >> ending; // Això consumeix el ";"
            mapa[first_index+index] = num;
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