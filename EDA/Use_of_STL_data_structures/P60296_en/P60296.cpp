#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

bool custom(const pair<string, int>& p1, const pair<string, int>& p2) {
    if (p1.second!=p2.second) return p1.second>p2.second;
    else return p1.first<p2.first;
}


int main() {
    string usr_op;
    map<string, pair<bool,int>> players;

    // Read data about the game
    while (cin >> usr_op) {
        string player_name1, player_name2;

        if (usr_op == "LOGIN") {
            cin >> player_name1;
            if (players.find(player_name1) == players.end()) {
                players[player_name1].first = true;
                players[player_name1].second = 1200;
            }
            else players[player_name1].first = true;
        }
        else if (usr_op == "LOGOUT") {
            cin >> player_name1;
            if (players.find(player_name1) != players.end()) players[player_name1].first = false;
        }
        else if (usr_op == "PLAY") {
            cin >> player_name1 >> player_name2;
            
            // Check both at least exist
            if (players.find(player_name1) == players.end()) {
                cout << "player(s) not connected" << endl;
                continue;
            }
            else if (players.find(player_name2) == players.end()) {
                cout << "player(s) not connected" << endl;
                continue;
            }
            
            // Check if they are connected
            if (!players[player_name1].first) {
                cout << "player(s) not connected" << endl;
                continue;  
            }
            else if (!players[player_name2].first) {
                cout << "player(s) not connected" << endl;
                continue;  
            }

            players[player_name1].second += 10;
            if (players[player_name2].second>=1210) players[player_name2].second -= 10;
        }
        else if (usr_op == "GET_ELO") {
            cin >> player_name1;
            
            if (players.find(player_name1) != players.end()) {
                cout << player_name1 << ' ' << players[player_name1].second << endl;
            }
            else cout << "player(s) not connected" << endl;
        }
    }

    // Calculate the ranking
    vector<pair<string, int>> ranking(players.size());
    int i = 0;
    for (auto player : players) {
        ranking[i].first = player.first;  // name
        ranking[i].second = player.second.second;  // elo
        i++;
    }
    sort(ranking.begin(), ranking.end(), custom);

    // Show ranking
    cout << endl;
    cout << "RANKING" << endl;
    for (int i = 0; i<players.size(); i++) {
        cout << ranking[i].first << ' ' << ranking[i].second << endl;
    }
}