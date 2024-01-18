#include <iostream>
using namespace std;

struct Temps {
    int hora, minut, segon;
};

void un_segon(const Temps& t, Temps& t1, Temps& t2) {
    // AUGMENTAR
    t1.segon = t.segon+1;
    if (t1.segon==60) {
        t1.segon = 0; t1.minut++;
        if (t1.minut==60) {
            t1.minut = 0; t1.hora++;
            if (t1.hora==24) {
                t1.hora = 0;
            }
        }
    }

    // DISMINUIR
    t2.segon = t.segon-1;
    if (t2.segon==-1) {
        t2.segon = 59; t2.minut--;
        if (t2.minut==-1) {
            t2.minut = 59; t2.hora--;
            if (t2.hora==-1) {
                t2.hora = 23;
            }
        }
    }
}

int main () {
    int usr_hora, usr_min, usr_seg;

    while (cin >> usr_hora >> usr_min >> usr_seg) {
        Temps t_usr,t1,t2;
        
        t_usr.hora = t1.hora = t2.hora = usr_hora; 
        t_usr.minut = t1.minut = t2.minut = usr_min; 
        t_usr.segon = t1.segon = t2.segon = usr_seg;

        un_segon(t_usr,t1,t2);
        cout << t1.hora << ' ' << t1.minut << ' ' << t1.segon << endl;
        cout << t2.hora << ' ' << t2.minut << ' ' << t2.segon << endl;
    }
}