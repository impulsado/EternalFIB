#include <QLineEdit>

class MyQLineEdit: public QLineEdit {
    Q_OBJECT

    public:
        MyQLineEdit(QWidget *parent);

    public slots:
        // En aquest cas no envia res, simplement captura
        void SelfCaptureReturn();
    
    signals:
        void sendReturnText(const QString &text);
};