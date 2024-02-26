/**
 * Oppgave 10 i heftet
*//**
 * Oppgave 10 i heftet
 * 
 * Ferdig: Nei
 * 
 * Problem: Fjernbok og vis spesifikkbok
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
       void lesData(); 
       void skrivData();
       void bokLest();
};

void nyBok();
void skrivBok();
void skrivAlleBoker();
void lestBok();
void fjernBok();
void skrivMeny();
void slettAlt();

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
           case 'D': skrivAlleBoker();   break;
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
 * 
*/
void skrivBok(){
    gBokene[lesInt("\tSe bok nr",1,gBokene.size()-1)]->skrivData();
}

/**
 * 
*/
void nyBok(){
    Bok* nyBok = new Bok;
    cout << "\nNy bok:\n";
    nyBok->lesData();
    gBokene.push_back(nyBok);
    cout << "\n\tNy bok innlagt har nr. " << gBokene.size() << '\n';
}

/**
 *  Overloaded funksjon som skriver alle b�kene vha PEKER.
 *
 *  @see   bokSkrivData(const Bok* bok)
 */
void skrivAlleBoker() {
    for (int i = 0;  i < gBokene.size();  i++) {
        cout << "\tBok nr." << setw(2) << i+1 << ":\n";
        gBokene[i]->skrivData();
    }
}

/**
 * 
*/
void lestBok(){
    gBokene[lesInt("\tLest bok nr", 1, gBokene.size()-1)]->bokLest();
}

/**
 * 
*/
void fjernBok(){
    int nr = lesInt("\tFjerne bok nr", 1, gBokene.size());
    delete gBokene[nr-1];
    gBokene[nr-1] = gBokene[gBokene.size()-1];
    gBokene.pop_back();
}

/**
 *  Leser inn og fyller ALLE en Bok sine datamedlemmer.
 *
 *  @param   bok  - Objektet som får sine datamedlemmer innlest/fylt
 */
void Bok::lesData(){
    cout << "\tTittel:     "; getline(cin, tittel);
    cout << "\tForfatter:  "; getline(cin, forfatter);
    antallSider = lesInt("\tAntall sider",1,2000);
    lest = false;
}

/**
 *  Overloaded funksjon som skriver .
 *
 *  @param   bok  - Obj hvis data utskrives p� skjermen
 */
void Bok::skrivData(){
    cout << "\t\t\"" << tittel << "\" av " << forfatter
         << ",  " << antallSider << " sider - " 
         << ((!lest) ? "IKKE " : "") << "lest\n";
}

/**
 *  Setter en Bok som lest.
 */
void Bok::bokLest(){
    cout << "\n\tBoken er markert som 'Lest'.\n";
    lest = true;
}

/**
 *  Skriver programmets menyvalg/muligheter på skjermen.
 */
void skrivMeny() {
    cout << "\nF�lgende kommandoer er tilgjengelig:\n"
         << "\tN - Ny bok\n"
         << "\tS - Skriv EN gitt bok\n"
         << "\tD - Display alle bokene vha. peker\n"
         << "\tL - Lest en bok\n"
         << "\tF - Fjern en gitt bok\n"
         << "\tQ - Quit / avslutt\n";
}

/**
 *  Sletter/fjerner ALLE tilpekte structer (Bok), og alle pekerne i vectoren.
 */
void slettAlt(){
                              //  EN m�te (av mange) � fjerne ALT i vectoren:
    while (!gBokene.empty()) {              //  S� lenge PEKERE i vectoren:
        delete gBokene[gBokene.size()-1];   //  Sletter den SISTE TILPEKTE.
        gBokene.pop_back();                 //  Sletter/fjerner SELVE PEKEREN.
    }
    cout << "\n\nVectoren er tom - antallet er: " << gBokene.size() << "\n\n";
}