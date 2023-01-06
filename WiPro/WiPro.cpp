#include "WiPro.h"  //Einbetten aller verwendeter Klassen


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
    cout << "z4 = z1 * z2 = " << z4.realGetter() << " + " << z4.imagGetter() << "*i" << endl;
    cout << "z5 = (z1 + z2) = " << z5.realGetter() << " + " << z5.imagGetter() << "*i" << endl;
    cout << "z6 = (z1 + z2)*2 = " << z6.realGetter() << " + " << z6.imagGetter() << "*i" << endl;
    cout << "z7 = (z2 + z3) * z1 = " << z7.realGetter() << " + " << z7.imagGetter() << "*i" << endl;
    cout << "z8 = 5 + z1 = " << z8.realGetter() << " + " << z8.imagGetter() << "*i" << endl;
    cout << "z9 = -z1 + z2 = " << z9.realGetter() << " + " << z9.imagGetter() << "*i" << endl;

    

    //Aufrufen der Rechnerklasse über JuliaCalculator.h
    JuliaCalculator calculator1(MyComplex(-2.0,-1.0), MyComplex(1.0,1.0), 750, 500, 2, 200, 2.0, MyComplex(0.0, 0.0));
    calculator1.calculateFixedStart();

    GnuData data("test.tmp");
    data.setDataPoints(&calculator1);

    GnuPlotter::plotData(data);

    
}