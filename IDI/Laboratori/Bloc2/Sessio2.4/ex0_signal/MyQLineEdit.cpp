#include "MyQLineEdit.h"

MyQLineEdit::MyQLineEdit(QWidget *parent) : QLineEdit(parent) {

}

void MyQLineEdit::SelfCaptureReturn() {
    // Obtindre el text del control i enviar-la al nostre signal
    emit sendReturnText(text());
}