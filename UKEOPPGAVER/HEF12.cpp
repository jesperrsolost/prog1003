/**
 * Oppgave 12 i heftet
 * 
 * Ferdig: Nei (Funksjonalitet fungerer, mangler kommentering)
 * 
 * @file HEF11.cpp
 * @author Jesper Ruud Soløst
 * 
 * @date 16.02.2024
*/

#include <iostream>                 // cout
#include <string>                   //
#include <vector>                   // vector
#include "LesData2.h"               // Verktøykasse for innlesing av data

using namespace std;

/**
 * Klasse med kundedata
*/
class Kunde {
    private:
        string navn;
        vector <float>* kontoer;            // Peker til kontoer og deres beløp
    public:
        Kunde(const int n);
        ~Kunde();
        void lesData();
        void skrivData();
};

vector <Kunde*> gKunder;

/**
 * Hovedprogrammet:
*/
int main(){
    Kunde* nyKunde;
    char kommando;

    do {
        cout << "\n\nAntall kontoer for kunde nr." << gKunder.size()+1;
        
        nyKunde = new Kunde(lesInt("", 1, 20));

        nyKunde->lesData();

        gKunder.push_back(nyKunde);

        kommando = lesChar("\nLese inn ny kunde? (J/n)");
    } while (kommando != 'N');

    cout << "\n\nSkriver ut kundenes data:\n";

    for (int i = 0; i < gKunder.size(); i++){
        cout << "Kunde nr." << i+1;
        gKunder[i]->skrivData();
        delete gKunder[i];
    }
    gKunder.clear();

    cout << "\n\n";

    return 0;
}

/**
 * Setter dynamisk kontoer til å peke på en float-vector
 * som er n lang, og alle elementene initieres til 0.0F 
*/
Kunde::Kunde(const int n){
    kontoer = new vector <float>(n);
    for (int i = 0; i < n; i++) {
        (*kontoer)[i] = 0.0F;
    }
}

/**
 * Sletter alt det som objektet har sagt new om mens det har levd 
*/
Kunde::~Kunde(){
    delete kontoer;
}

/**
 * Spørr om kundens navn og beløpet som står inne på hver av de
 * aktuelle kontoene 
*/
void Kunde::lesData(){
    cout << "Kundens navn: "; getline(cin, navn);
    for (int i = 0; i < kontoer->size(); i++) {
        cout << "Belop paa konto nr." << i+1;
        (*kontoer)[i] = lesFloat("", 0, 10000000);
    }
}

/**
 * Skriver navnet og innestående beløp på alle aktuelle kontoer
*/
void Kunde::skrivData(){
    cout << "Navn: " << navn << " har kontoer med folgende belop:";
    for (int i = 0; i < kontoer->size(); i++){
        cout << "\nKonto nr." << i+1 << ':' << (*kontoer)[i];
    }
}


