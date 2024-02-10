/**
 *   Programeksempel nr 6 - St�rre programeksempel.
 *
 *   Eksemplet viser/vektlegger referanseoverf�ring, string og vector,
 *   men ogs� litt overloading av funksjoner og en god del bruk av pekere.
 *
 *   Programmet holder orden p� en person sin boksamling ved � kunne:
 *     - legge inn en ny bok
 *     - skriv alt om en gitt bok
 *     - skrive ut alle b�kene vha. peker            |  For � vise overloading
 *     - skrive ut alle b�kene vha. struct-variabel  |    av funksjoner.
 *     - sette en bok som lest
 *     - fjerne en gitt bok
 *
 *****************************************************************************
 *      NB:      NB:      NB:      NB:      NB:      NB:      NB:      NB:
 *   N�r en parameter IKKE er CONST, fordi originalen skal endres/oppdateres,
 *   vil det heretter prim�rt bli brukt REFERANSEOVERF�RING
 *   (og IKKE PEKER til elementet).
 *   Er den derimot CONST, og det er noe som PEKER til elementet,
 *   s� vil elementet bli medsendt ENTEN som en PEKER, ELLER OMGJORT
 *   til en vanlig variabel/struct/objekt (jfr. XXXXXXXXXX nedenfor).
 *
 *****************************************************************************
 *
 *   @file     EKS_06.CPP
 *   @author   Frode Haug, NTNU
 */


#include <iostream>                //  cout, cin
#include <iomanip>                 //  setw
#include <string>                  //  string
#include <vector>                  //  vector
#include "LesData2.h"              //  Verkt�ykasse for lesing av diverse data
using namespace std;


/**
 *  Bok (med tittel, forfatter, antall sider og om lest eller ei).
 */
struct Bok {
    string tittel,
           forfatter;
    int    antallSider;
    bool   lest;
};


void bokLesData(Bok & bok);             //     XXXXXXXXXX
void bokLest(Bok & bok);                //     XXXXXXXXXX
void bokSkrivData(const Bok* bok);      //     XXXXXXXXXX
void bokSkrivData(const Bok bok);
void fjernBok();
void lestBok();
void nyBok();
void skrivAlleBoker1();
void skrivAlleBoker2();
void skrivBok();
void skrivMeny();
void slettAlt();


vector <Bok*> gBokene;       ///<  Alle b�kene i oversikten/datastrukturen.
                             //    NB:  Trenger n� ikke lengre 'gAntallBoker',
                             //         da gBokene.size() er dette antallet.

/**
 *  Hovedprogrammet:
 */
int main()  {
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
 *  @param   bok  - Structen som f�r sine datamedlemmer innlest/fylt
 */
void bokLesData(Bok & bok) {
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
void bokLest(Bok & bok) {
    cout << "\n\tBoken er markert/satt som 'Lest'.\n";
    bok.lest = true;
}


/**
 *  Overloaded funksjon som skriver en structs data (peker som parameter).
 *
 *  @param   bok  - PEKER til structen hvis data utskrives p� skjermen
 */
void bokSkrivData(const Bok* bok)  {
   cout << "\t\t\"" << bok->tittel << "\" av " << bok->forfatter
        << ",  " << bok->antallSider << " sider - "
        << ((!bok->lest) ? "IKKE " : "") << "lest\n";
}


/**
 *  Overloaded funksjon som skriver structdata (struct-variabel som paramtr).
 *
 *  @param   bok  - Struct-VARIABEL hvis data utskrives p� skjermen
 */
void bokSkrivData(const Bok bok)  {
   cout << "\t\t\"" << bok.tittel << "\" av " << bok.forfatter
        << ",  " << bok.antallSider << " sider - "
        << ((!bok.lest) ? "IKKE " : "") << "lest\n";
}


/**
 *  �nsket boknummer slettes, og bakerste flyttes til den slettedes plass.
 */
void fjernBok() {
    int nr = lesInt("\tFjerne bok nr", 1, gBokene.size());  //  �nsket nr.
    delete gBokene[nr-1];                      // Sletter aktuell bok!
    gBokene[nr-1] = gBokene[gBokene.size()-1]; // Bakerst flyttes til plassen.
    gBokene.pop_back();                        // Siste PEKER slettes ogs�!
}


/**
 *  �nsket boknummer markeres som lest.
 *
 *  @see   boklest(...)
 */
void lestBok() {
    bokLest(*gBokene[lesInt("\tLest bok nr", 1, gBokene.size())-1]);
}


/**
 *  Ny bok legges inn i datastrukturen (vectoren 'gBokene').
 *
 *  @see   bokLesData(...)
 */
void nyBok() {
    Bok* nyBok = new Bok;         //  Oppretter en ny Bok-struct.
    cout << "\nNy bok:\n";
    bokLesData(*nyBok);           //  Alle dens data leses inn.
    gBokene.push_back(nyBok);     //  Legges bakerst i vectoren.
    cout << "\n\tNy bok innlagt har nr." << gBokene.size() << '\n';
}


/**
 *  Overloaded funksjon som skriver alle b�kene vha PEKER.
 *
 *  @see   bokSkrivData(const Bok* bok)
 */
void skrivAlleBoker1() {
    for (int i = 0;  i < gBokene.size();  i++) {
        cout << "\tBok nr." << setw(2) << i+1 << ":\n";
        bokSkrivData(gBokene[i]);
    }
}


/**
 *  Overloaded funksjon som skriver alle b�kene vha STRUCT-VARIABEL.
 *
 *  @see   bokSkrivData(const Bok bok)
 */
void skrivAlleBoker2() {
    for (int i = 0;  i < gBokene.size();  i++) {
        cout << "\tBok nr." << setw(2) << i+1 << ":\n";
        bokSkrivData(*gBokene[i]);
    }
}


/**
 *  Skriver alt en ETT �nsket boknummer.
 *
 *  @see   bokSkrivData(const Bok* bok)
 */
void skrivBok() {
    bokSkrivData(gBokene[lesInt("\tSe bok nr", 1, gBokene.size())-1]);

//     Eller med bruk av '*':  Dermed kalles den andre OVERLOADEDE funksjonen:
//         bokSkrivData(*gBokene[lesInt("\tSe bok nr", 1, gBokene.size())-1]);
}


/**
 *  Skriver programmets menyvalg/muligheter p� skjermen.
 */
void skrivMeny() {
    cout << "\nF�lgende kommandoer er tilgjengelig:\n"
         << "\tN - Ny bok\n"
         << "\tS - Skriv EN gitt bok\n"
         << "\t1 - skriv alle b�kene vha. peker\n"
         << "\t2 - skriv alle b�kene vha. struct-variabel\n"
         << "\tL - Lest en bok\n"
         << "\tF - Fjern en gitt bok\n"
         << "\tQ - Quit / avslutt\n";
}


/**
 *  Sletter/fjerner ALLE tilpekte structer (Bok), og alle pekerne i vectoren.
 */
void slettAlt() {
                              //  EN m�te (av mange) � fjerne ALT i vectoren:
    while (!gBokene.empty()) {              //  S� lenge PEKERE i vectoren:
        delete gBokene[gBokene.size()-1];   //  Sletter den SISTE TILPEKTE.
        gBokene.pop_back();                 //  Sletter/fjerner SELVE PEKEREN.
    }
/*                            //  En annen (og enklere?) m�te:
  for (int i = 0; i < gBokene.size(); i++)  // Sletter ALLE b�kene/struct'ene:
      delete gBokene[i];
  gBokene.clear();                        //  Fjerner ALLE PEKERNE i vectoren.
*/
    cout << "\n\nvectoren er tom - antallet er: " << gBokene.size() << "\n\n";
}
