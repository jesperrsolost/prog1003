/**
 * Oppgave 12 i heftet
 * 
 * Ferdig: Nei
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

/**
 * Hovedprogrammet:
*/
int main(){
    
    vector <Kunde*> kunder;
    char kommando = lesChar("\nKommando");

    do {
        
        kommando = lesChar("\nLese inn ny kunde?");
    } while (kommano != 'Q');
    return 0;
}

/**
 * Setter dynamisk kontoer til å peke på en float-vector
 * som er n lang, og alle elementene initieres til 0.0F 
*/
Kunde::Kunde(const int n){
    
}

/**
 * Sletter alt det som objektet har sagt new om mens det har levd 
*/
Kunde::~Kunde(){

}

/**
 * Spørr om kundens navn og beløpet som står inne på hver av de
 * aktuelle kontoene 
*/
void Kunde::lesData(){
    
}

/**
 * Skriver navnet og innestående beløp på alle aktuelle kontoer
*/
void Kunde::skrivData(){

}


