#include "ui_Form.h"

class MyForm : public QWidget {
    Q_OBJECT
    
    public:
        MyForm(QWidget *parent = 0);
    
    private:
        Ui::MyForm ui;
};