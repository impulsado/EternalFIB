#include "MyQLabel.h"

// Constructor
// "QLabel(parent)" crida al constructor de la clase pare
MyQLabel::MyQLabel(QWidget *parent) : QLabel(parent) {
    // Sempre buit
}

// Slot personalitzar
void MyQLabel::SetCapText(const QString &text) {
    // Agafa el text i el fa majus --> El fica el text en el label # Buscat en internet
    setText(text.toUpper());
}