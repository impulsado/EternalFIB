#include <QLabel>

class MyQLabel : public QLabel {
    Q_OBJECT

    public:
        MyQLabel(QWidget *parent);

    public slots:
        void ChangeColorESTAT();
        void incrementarComptadorNoCamion();
        void incrementarComptadorCamion();
        void updateNum(int value);
    
    signals:
        void actualitzarComptador(int counter);
        void actualitzarSuma(int amount);

    private:
        // "static" pq. d'aquesta forma tots els labels la poden veure (GLOBAL)
        static QColor currentColor;
        static int suma;

        // NOTA: Cada label té un counter diferent a la resta, així que no fa falta que sigui especific de cada vehicle
        int vehicle_counter = 0;
    };