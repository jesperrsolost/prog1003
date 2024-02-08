/**
 * Oppgave 10 i heftet
 * 
 * Ferdig: Nei
 * 
 * @file HEF10.cpp
 * @author Jesper Ruud Soløst
 * 
 * @date 08.02.2024
*/

#include <iostream>                 // cout, cin
#include <iomanip>                  // setw
#include <string>                   // string
#include <vector>                   // vector
#include "LesData2.h"               // Verktøykasse for lesing av diverse data

using namespace std;

/**
 * Klasse Bok (med tittel, forfatter, antall sider og om lest eller ei).
*/
class Bok {
    private:
        string tittel,
               forfatter;
        int    antallSider;
        bool   lest;
    public:
        void lesData(Bok & bok);
        void lest(Bok & bok);
        void SkrivData(const Bok* bok);
        void SkrivData(const Bok bok);
};

vector <Bok*> gBokene;


/**
 * Hovedprogrammet:
*/
int main(){
char kommando;

    skrivMeny();
    kommando = lesChar("\nKommando");

    while (kommando != 'Q') {
        switch (kommando) {
           case 'N': nyBok();            break;
           case 'S': skrivBok();         break;
           case '1': skrivAlleBoker1();  break;
           case '2': skrivAlleBoker2();  break;
           case 'L': lestBok();          break;
           case 'F': fjernBok();         break;
           default:  skrivMeny();        break;
        }
        kommando = lesChar("\nKommando");
    }

    slettAlt();

    return 0;
}

/**
 *  Leser inn og fyller ALLE en Bok sine datamedlemmer.
 *
 *  @param   bok  - Structen som får sine datamedlemmer innlest/fylt
 */
void Bok::lesData(Bok & bok) {
    cout << "\tTittel:     ";       getline(cin, bok.tittel);
    cout << "\tForfatter:  ";       getline(cin, bok.forfatter);
    bok.antallSider = lesInt("\tAntall sider", 1, 2000);
    bok.lest = false;
}

/**
 *  Setter en Bok som lest.
 *
 *  @param   bok  - Structen som f�r 'lest' satt til 'true'
 */
void Bok::lest(Bok & bok){
    cout << "\n\tBoken er markert/satt som 'Lest'.\n";
    bok.lest = true;
}

/**
 *  Overloaded funksjon som skriver en structs data (peker som parameter).
 *
 *  @param   bok  - PEKER til structen hvis data utskrives p� skjermen
 */
void Bok::SkrivData(const Bok* bok)  {
   cout << "\t\t\"" << bok->tittel << "\" av " << bok->forfatter
        << ",  " << bok->antallSider << " sider - "
        << ((!bok->lest) ? "IKKE " : "") << "lest\n";
}

/**
 *  Overloaded funksjon som skriver structdata (struct-variabel som paramtr).
 *
 *  @param   bok  - Struct-VARIABEL hvis data utskrives p� skjermen
 */
void Bok::SkrivData(const Bok bok)  {
   cout << "\t\t\"" << bok.tittel << "\" av " << bok.forfatter
        << ",  " << bok.antallSider << " sider - "
        << ((!bok.lest) ? "IKKE " : "") << "lest\n";
}