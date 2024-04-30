#include <queue>
#include "CuaIOParInt.hh"
using namespace std;

void distribuir (queue<ParInt>& Main, queue<ParInt>& Cua1, queue<ParInt>& Cua2) {
    int Cua1_counter, Cua2_counter;
    Cua1_counter = Cua2_counter = 0;
    
    while (!Main.empty()) {
        ParInt temp = Main.front();

        if (Cua1_counter<Cua2_counter) {
            Cua1.push(temp);
            Cua1_counter += temp.segon();  // Primer: Id; Segon: Temps
        } else {
            Cua2.push(temp);
            Cua2_counter += temp.segon();  // Primer: Id; Segon: Temps
        }
        
        Main.pop();  // Treure el temp que ja esta en una cua
    }
}

int main () {
    // Llegir tots els elements
    queue<ParInt> CuaPrincipal;
    llegirCuaParInt(CuaPrincipal);
    // Distribuir-los en dues cues
    queue<ParInt> Cua1, Cua2;
    distribuir(CuaPrincipal, Cua1, Cua2);
    // Escriure les dues cues
    escriureCuaParInt(Cua2);
    cout << endl;
    escriureCuaParInt(Cua1);
}