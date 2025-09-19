#include <QLabel>  // Include el Widget o Control que volem personalitzar

class MyQLabel: public QLabel // Dir de qui hereda (QLabel)
{
    Q_OBJECT  // Macro que diu al compilador que es un widget personalitzat
    
    public:
        MyQLabel(QWidget *parent);  // Fer el contstructor (Això sempre és així)
    public slots: // Aqui fiquem els nous slots (Funcio que s'executa arrel d'un trigger)
        
        // Slot que volem que rebi del lineedit (Podem veure en l'editor que reb)
        // Com que es un objecte s'ha de passar "Const" i per referencia "&" (Si fos int, string, ... no faria falta)
        void SetCapText(const QString &text);
};