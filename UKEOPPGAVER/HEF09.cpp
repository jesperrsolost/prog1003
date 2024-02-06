/**
 * Oppgave 9 i heftet
 * 
 * Ferdig: Ja
 * 
 * @file HEF09.cpp
 * @author Jesper Ruud Soløst
 * 
 * @date 06.02.2024
*/

#include <iostream>                  // cout
#include "LesData2.h"                // Verktøykasse for lesing av diverse data

using namespace std;

/**
 * Dato med dag, måned, år
*/
class Dato {
    private:

    int dag,
        maaned,
        aar;

    public:

    Dato(){ // Setter datamedlemmene til 1/1-2000 (1. januar 2000)
        dag = maaned = 1, aar = 2000;
    }

    Dato(int d, int m, int a){ // Setter datamedlemmene til parametrenes verdier
        dag = d, maaned = m, aar = a;
    }

    void lesData(){ // Leser datamedlemmenes verdier fra brukeren (<30 dager)
        dag    = lesInt("Dag   ", 1, 30);
        maaned = lesInt("Maaned", 1, 12);
        aar    = lesInt("Aar   ", 0, 3000);
    }

    void skrivData(){ // Skriver datoen på formen: DD/MM-AAAA (dag / måned - år)
        cout << "\t" << dag << '/' << maaned << '-' << aar << "\n";
    }

    bool sammeAar(const Dato dato){ // Returnerer bool til om eget aar er lik dato.aar
        return (aar == dato.aar);
    }

    bool sammeAarsdag(const Dato dato){ // Returnerer bool til om egen dag i året er lik med parameteren sin
        return (dag == dato.dag && maaned == dato.maaned);
    }

    bool tidligereEnn(const Dato dato){ // Returnerer bool om dato er tidligere
        return (dag + (maaned * 30) + (aar * 365) > 
                dato.dag + (dato.maaned * 30) + (dato.aar * 365));
    // SPØRSMÅL TIL TA: Er dette en god metode å bruke kontra det som er brukt
    // i løsningsforslag?
    }
};

/**
 * Hovedprogrammet:
*/
int main(){
    Dato dato(2,2,2000);
    Dato dato2;

    cout << "Data til dato2:\n";
    dato2.lesData();

    cout << "\n";

    cout << "Data:\n";
    dato.skrivData();
    dato2.skrivData();

    cout << "\n";

    cout << (dato.sammeAar(dato2) ? "\tDatoene har samme aar\n" : 
                                    "\tDatoene har ikke samme aar\n");

    cout << (dato.sammeAarsdag(dato2) ? "\tDatoene har samme aarsdag\n" :
                                  "\tDatoene har ikke samme aarsdag\n");

    cout << (dato.sammeAar(dato2) && dato.sammeAarsdag(dato2) ? 
    "\tDatoene er identisk\n" :
    "\tDatoene er ikke identisk\n");

    cout << "\n";

    cout << (dato.tidligereEnn(dato2) ? 
    "\tInnskrevet dato er tidligere enn dato2\n" :
    "\tInnskrevet dato er etter dato2\n"); 
    return 0;
}