/**
 * Oppgave 7 i heftet
 * 
 * Ferdig: Nei
 * 
 * @file HEF07.cpp
 * @author Jesper Ruud Soløst
 * 
 * @date 30.01.2024
*/
#include <iostream>
#include <string>
#include "LesData2.h"

using namespace std;

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

}

// ---------------------------------------------------------------------------

/**
 * Leser inn og fyller s med en hel tekstlinje (ikke bare ett enkeltord).
 * Det skal ikke godtas at brukeren kun skriver ‘\n’ – dvs. en tom tekst
*/
void les(string & s){

}

/**
 * Får fylt alle structens datamedlemmer med rimelige verdier.
 * Bruk den nye LesData2.h til å lese alle tallene.
*/
void les(Klokkeslett & klokkeslett){

}

/**
 * Skriver structens datamedlemmer på formen: TT-MM-SS
 * gjerne med innledende ‘0’ (null) foran alle en-sifrede tall.
*/
void skriv(const Klokkeslett klokkeslett){

}