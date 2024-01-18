#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Point {
    double x, y, z;
};

struct Particle {
    Point p, v;
    double m;
};

Point sum(Point p1, Point p2) {
    return {p1.x + p2.x, p1.y + p2.y, p1.z + p2.z};
}

Point mul(double a, Point p) {
    return {a * p.x, a * p.y, a * p.z};
}

void printDouble(double d) {
    if (abs(d) < 1e-7) cout << 0.0;
    else cout << d;
}

void readParticules(vector<Particle>& particules, int& usr_num_particules, double& massaTotal, Point& desplacament, Point& velocitat) {
    massaTotal = 0; desplacament = {0,0,0}; velocitat = {0,0,0};
    for (int i = 0; i<usr_num_particules; i++) {
        cin >> particules[i].p.x >> particules[i].p.y >> particules[i].p.z;
        cin >> particules[i].v.x >> particules[i].v.y >> particules[i].v.z;
        cin >> particules[i].m;
        massaTotal += particules[i].m;
        desplacament = sum(desplacament, mul(particules[i].m, particules[i].p));
        velocitat = sum(velocitat, mul(particules[i].m, particules[i].v));
    }
    desplacament = mul(1.0 / massaTotal, desplacament);
    velocitat = mul(1.0 / massaTotal, velocitat);

}

void updateAndPrint(vector<Particle>& particules, int& usr_num_instants, Point& desplacament, Point& cm, Point& velocitat) {
    double tempsTotal = 0;

    for (int i = 0; i<usr_num_instants; i++) {
        double usr_instant;
        cin >> usr_instant;
        tempsTotal += usr_instant;

        // Calcular pos del CM cada t1+...+tn
        cm = sum(desplacament, mul(tempsTotal,velocitat));

        // Mostrar CM cada t1+...+tn
        printDouble(cm.x); cout << ' '; printDouble(cm.y); cout << ' '; printDouble(cm.z); cout << '\n';
    }

    // Mostrar posició final de cada particula
    for (int i = 0; i<particules.size(); i++) {
        Point posFinal = sum(particules[i].p, mul(tempsTotal, particules[i].v));
        printDouble(posFinal.x); cout << ' '; printDouble(posFinal.y); cout << ' '; printDouble(posFinal.z); cout << '\n';
    }

    // Salt final
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(5);

    int usr_num_particules, usr_num_instants;
    while (cin >> usr_num_particules >> usr_num_instants) {
        vector<Particle> particules(usr_num_particules);
        double massaTotal;
        Point desplacament, cm, velocitat;
        readParticules(particules, usr_num_particules, massaTotal, desplacament, velocitat);
        updateAndPrint(particules, usr_num_instants, desplacament, cm, velocitat);
    }

    return 0;
}