/**
 * Eksprementering med lesing og skriving fra filer
*/

#include <iostream>
#include <fstream> 
#include <string>
#include <vector>
#include "LesData2.h"

using namespace std;

/**
 * Klasse for en Counter-Strike gjenstand
*/
class Gjenstand {

};

void skrivMeny();

/**
 * Hovedprogrammet:
*/
int main(){
    char kommando;

    kommando = lesChar("Kommando");

    skrivMeny();

    while (kommando != 'Q'){

        kommando = lesChar("Kommando");
    }
    return 0;
}

/**
 * Funksjon for skriving av meny
*/
void skrivMeny(){
    cout << "\n"
         << "+ - Legg til gjenstand";
}