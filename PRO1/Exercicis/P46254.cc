//Distància entre dos punts
#include <iostream>
#include <cmath>
using namespace std;

struct Punt {
    double x,y;
};

double distancia(const Punt& a, const Punt& b) {
    double d;
    d = (b.x - a.x)*(b.x - a.x) + (b.y - a.y)*(b.y - a.y);
    d = sqrt(d);
    return d;
}

/* NOTA: Entrega sense main perque aquest només és de probes*/
int main () {
    int p1X, p1Y, p2X, p2Y;
    Punt p1,p2;
    double dist;

    while (cin >> p1X >> p1Y >> p1X >> p2Y) {
        p1.x = p1X; p1.y = p1Y;
        p2.x = p2X; p2.y = p2Y;

        dist = distancia(p1,p2);

        cout << dist << endl;
    }
}