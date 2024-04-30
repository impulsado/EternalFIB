// 2.82s
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    string command;
    map<int,int> values;
    int first_index = 0;
    int last_index = -1;  // Per si fan de primeres un push_back el guardi en values[0]
    
    while (cin >> command) {
        if (command == "v.push_back(") {
            int num;
            string ending;
            cin >> num; cin >> ending; // Això consumeix el ");"
            last_index++;
            values[last_index] = num;
        } 
        else if (command == "v.push_front(") {
            int num;
            string ending;
            cin >> num; cin >> ending; // Això consumeix el ");"
            first_index--;
            values[first_index] = num;
        } 
        else if (command == "v.pop_front();") {
            if (first_index<=last_index) {
                values.erase(first_index);
                first_index++;
            }
        } 
        else if (command == "v.pop_back();") {
            if (last_index>=first_index) {
                values.erase(last_index);
                last_index--;
            }
        } 
        else if (command == "v.resize(") {
            int newsize;
            string ending;
            cin >> newsize; cin >> ending; // Això consumeix el ");"
            
            int currentSize = last_index - first_index + 1;
            if (newsize < currentSize) {
                last_index = first_index + newsize - 1;
            } else if (newsize > currentSize) {
                int old_last_index = last_index+1;
                last_index = first_index + newsize - 1;
                // Ficar a 0 les key que ºvagin fins a la mida nova (si es que estaven inicialitzades)
                for(auto it = values.lower_bound(old_last_index); it!=values.lower_bound(last_index); it++) {
                    it->second=0;
                }
            }
        } 
        else if (command == "cout<<v[") {
            int index;
            string ending;
            cin >> index; cin >> ending; // Això consumeix el "];"
            cout << values[first_index+index] << endl;
        } 
        else if (command == "cout<<v;") {
            cout << values[first_index];
            for (int i = first_index+1; i<=last_index; i++) {
                auto it = values.find(i);
                if (it!= values.end()) cout << ',' << it->second;
                else cout << ',' << 0;
            }
            cout << endl;
        } 
        else if (command == "v[") {
            int index, num;
            string mid, ending;
            cin >> index; cin >> mid; cin >> num; cin >> ending; // Això consumeix el ";"
            values[first_index+index] = num;
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