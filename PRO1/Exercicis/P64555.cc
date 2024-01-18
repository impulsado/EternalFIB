#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Coordenada {
    int x,y;
    int dist;
};

bool customFilter(const Coordenada& p1,const Coordenada& p2) {
    /* 
    dist > x > y 
    */
    if (p1.dist!=p2.dist) return p1.dist<p2.dist;
    else if (p1.x!=p2.x) return p1.x<p2.x;
    else return p1.y<p2.y;
}

int calcDist (int xOG, int yOG, Coordenada& usr_coordenada) {
    /*
    dist = |xc-x|+|yc-y| on xc i yc són les OG
    */
    int calc1 = xOG-usr_coordenada.x;
    if (calc1<0) calc1 *= (-1);

    int calc2 = yOG-usr_coordenada.y;
    if (calc2<0) calc2 *= (-1);

    return calc1+calc2;
}

void showDistances(vector<Coordenada>& Coordenades) {
    int last_dist = -1;

    for (int i = 0; i<Coordenades.size(); i++) {
        if (Coordenades[i].dist!=last_dist) {
            last_dist = Coordenades[i].dist;
            cout << "punts a distancia " << last_dist << endl;
        }
        cout << Coordenades[i].x << ' ' << Coordenades[i].y << endl;
    }
}

int main () {
    // Demanar datos Coordenada Origen
    int xOG, yOG;
    cin >> xOG >> yOG;

    // Demanar Coordenades
    int usr_quant;
    cin >> usr_quant;
    vector<Coordenada> Coordenades(usr_quant);
    for (int i = 0; i<usr_quant; i++) {
        cin >> Coordenades[i].x >> Coordenades[i].y;
        // Calcular distancia a l'orgien
        Coordenades[i].dist = calcDist(xOG, yOG, Coordenades[i]);
    }

    // Ordenar coordenades
    sort(Coordenades.begin(), Coordenades.end(), customFilter);

    // Mostrar coordenades
    showDistances(Coordenades);
}