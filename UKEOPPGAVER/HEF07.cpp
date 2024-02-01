/**
 * Oppgave 7 i heftet
 * 
 * Ferdig: Ja
 * 
 * @file HEF07.cpp
 * @author Jesper Ruud Soløst
 * 
 * @date 01.02.2024
*/
#include <iostream>
#include <string>
#include "LesData2.h"

using namespace std;

const int MAXSTRUCTER = 2,                         ///< Maks antall structer.
          MAXTEKSTER  = 2;                         ///< Maks antall tekster.


struct Klokkeslett {
    int time,
        minutt,
        sekund;
};

void les(string & s);
void les(Klokkeslett & klokkeslett);
void skriv(const Klokkeslett klokkeslett);

/**
 * Hovedprogrammet:
*/
int main(){
    string tekster[MAXTEKSTER];
    Klokkeslett klokkesletter[MAXSTRUCTER];

    for (int i = 0; i < MAXTEKSTER; i++){
        cout << "Les inn tekst nr. " << i + 1 << ": ";
        les(tekster[i]);
    }

    cout << "\n\n";

    for (int i= 0; i < MAXSTRUCTER; i++){
        les(klokkesletter[i]);
    }

    cout << "\n\n";

    for (int i = 0; i < MAXTEKSTER; i++){
        cout << "Tekst nr. " << i + 1 << " er lik: " << tekster[i] << "\n\n";
    }

    for (int i = 0; i < MAXSTRUCTER; i++){
        skriv(klokkesletter[i]);
        cout << "\n\n";
    }
    
}

// ---------------------------------------------------------------------------

/**
 * Leser inn og fyller s med en hel tekstlinje (ikke bare ett enkeltord).
 * Det skal ikke godtas at brukeren kun skriver ‘\n’ – dvs. en tom tekst
*/
void les(string & s){
    do {
        getline(cin, s);
    } while (s.length() == 0);
} 

/**
 * Får fylt alle structens datamedlemmer med rimelige verdier.
 * Bruk den nye LesData2.h til å lese alle tallene.
*/
void les(Klokkeslett & klokkeslett){
    klokkeslett.time   = lesInt("Les inn time  ",0 ,24);
    klokkeslett.minutt = lesInt("Les inn minutt",0 ,59);
    klokkeslett.sekund = lesInt("Les inn sekund",0 ,59);
    cout << "\n\n";
}

/**
 * Skriver structens datamedlemmer på formen: TT-MM-SS
 * gjerne med innledende ‘0’ (null) foran alle en-sifrede tall.
*/
void skriv(const Klokkeslett klokkeslett){
    cout << "Klokkeslett: "
         << ((klokkeslett.time   < 10) ? "0" : "") << klokkeslett.time << ":"
         << ((klokkeslett.minutt < 10) ? "0" : "") << klokkeslett.time << ":"
         << ((klokkeslett.sekund < 10) ? "0" : "") << klokkeslett.time;
    
}