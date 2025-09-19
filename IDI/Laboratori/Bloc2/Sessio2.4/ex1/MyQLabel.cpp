#include "MyQLabel.h"

QColor MyQLabel::currentColor = Qt::red;
int MyQLabel::suma = 0;

MyQLabel::MyQLabel(QWidget *parent) : QLabel(parent) {

}

void MyQLabel::ChangeColorESTAT() {
    if (currentColor == Qt::red) {
        currentColor = Qt::green;
        setStyleSheet("color: #00FF00;");
    } else {
        currentColor = Qt::red;
        setStyleSheet("color: #FF0000;");
    }
}

void MyQLabel::incrementarComptadorNoCamion() {
    if (currentColor == Qt::red) return;
    vehicle_counter++;
    suma += 1;
    emit actualitzarComptador(vehicle_counter);
    emit actualitzarSuma(suma);
}

void MyQLabel::incrementarComptadorCamion() {
    if (currentColor == Qt::red) return;
    vehicle_counter++;
    suma += 4;
    emit actualitzarComptador(vehicle_counter);
    emit actualitzarSuma(suma);
}

void MyQLabel::updateNum(int value) {
    setNum(value);
}