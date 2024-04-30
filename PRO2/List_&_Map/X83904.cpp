#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

int main () {
    map<string, set<int> > mStudentsAndActivities;
    string students_last_name;
    int num_activities;
    
    // Create map with all student's last names
    // Implicitly creates an empty set for the student
    while (cin >> students_last_name and students_last_name!=".") mStudentsAndActivities[students_last_name];

    // Insert to the 'set' the activity id. It will be unique so duplicated entries doesn't matter
    cin >> num_activities;
    for (int id = 0; id<num_activities; id++) {
        while (cin >> students_last_name and students_last_name!=".") mStudentsAndActivities[students_last_name].insert(id);
    }

    cout << "Totes les activitats:";
    
    set<string> lazyStudents;
    for (map<string, set<int> >::iterator it1 = mStudentsAndActivities.begin(); it1!=mStudentsAndActivities.end(); it1++) {
        if (it1->second.size()==num_activities) cout << ' ' << it1->first;
        else if (it1->second.empty()) lazyStudents.insert(it1->first);
    }
    cout << endl;
    cout << "Cap activitat:";
    for (set<string>::iterator it2 = lazyStudents.begin(); it2!=lazyStudents.end(); it2++) cout << ' ' << *it2;
    cout << endl;
}