#include "WiPro.h"  //Einbetten aller verwendeter Klassen
#pragma warning(disable:4996) //Unterdr�cken von Warnung bei Nutzung von Gnuplot

int main() //Hauptprogramm
{
    //Definieren der komplexen Zahlen wie Aufgabenstellung
    MyComplex z1(2, 7);
    MyComplex z2(42, -9);
    MyComplex z3(-11, 19);

    //Berechnen der vorgegebenen Berechnungen 
    MyComplex z4 = z1 * z2;
    MyComplex z5 = z1 + z2;
    MyComplex z6 = (z1 + z2) * 2;
    MyComplex z7 = (z2 + z3) * z1;
    MyComplex z8 = 5 + z1;
    MyComplex z9 = -z1 + z2;

    //Ausgeben der vorgegebenen Berechnungen
    cout << z4 << endl;
    cout << z5 << endl;
    cout << z6 << endl;
    cout << z7 << endl;
    cout << z8 << endl;
    cout << z9 << endl;


    //Aufrufen der Rechnerklasse �ber JuliaCalculator.h
    JuliaCalculator calculator1(MyComplex(-2.0,-1.0), MyComplex(1.0,1.0), 750, 500, 2, 200, 2.0, MyComplex(0.0, 0.0));
    calculator1.calculateFixedStart();

    GnuData data("test.tmp");
    data.setDataPoints(&calculator1);

    GnuPlotter::plotData(data);
}