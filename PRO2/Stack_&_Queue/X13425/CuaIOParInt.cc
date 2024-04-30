#include "CuaIOParInt.hh"

void llegirCuaParInt(queue<ParInt>& c) {
    ParInt a;
    while (a.llegir()) c.push(a);
}

void escriureCuaParInt(queue<ParInt> c) {
    while (!c.empty()) {
        c.front().escriure();
        c.pop();
    }
}