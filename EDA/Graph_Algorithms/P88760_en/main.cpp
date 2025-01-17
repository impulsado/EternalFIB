#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

struct pedra {
    double x, y;
    double r;
    int salts = -1;
    char lletra = 'r';
};

void askData(vector<pedra>& pedres) {
    double x,y,r;
    for (int i = 0; i<pedres.size(); i++) {
        cin >> x >> y >> r;
        pedra temp;
        temp.x = x; temp.y = y; temp.r = r;
        if (i == 0) temp.lletra = 's';
        else if (i == pedres.size()-1) temp.lletra = 'e';
        pedres[i] = temp;
    }
}

bool ok_dist(const pedra& p1, const pedra& p2, const double& d) {
    double dist = sqrt((p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y));
    double dist_real = dist-p2.r-p1.r;
    if (dist_real<=d) return true;
    else return false;
}

int bfs(vector<pedra>& pedres, const double& d) {
    pedres[0].salts = 0;
    queue<pedra> q;
    q.push(pedres[0]);
    
    while (!q.empty()) {
        pedra actual = q.front();
        q.pop();

        for (int j = pedres.size()-1; j>=0; j--) {
            pedra& vei = pedres[j];  // Eficiencia
            if (ok_dist(actual, vei, d) && vei.salts == -1) {
                vei.salts = actual.salts + 1;
                q.push(vei);
                if (vei.lletra == 'e') return vei.salts;
            }
        }
    }

    return -1;
}

int main() {
    int n;
    double d;

    while (cin >> n >> d) {
        vector<pedra> pedres(n);
        askData(pedres);
        
        int dist = bfs(pedres, d);
        if (dist == -1) cout << "Xof!" << endl;
        else cout << dist << endl;
    }
}