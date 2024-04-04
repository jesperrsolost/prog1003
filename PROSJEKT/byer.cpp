#include "byer.h"
#include <iostream>

using namespace std;

/**
 * Parameterløs constructor til klassen "Byer"
*/
Byer::Byer(){  }

/**
 * Destructor til klassen Byer
*/
Byer::~Byer(){  }

/**
 *                          "Byer skriv Alle"
 * Skriver ut på skjermen alle byenes/stedenes navn, landet det ligger i og 
 * antall attraksjoner i byen/på stedet. Alt på en linje pr.by/sted. 
 * (Format utskrift: <BY> <LAND> <nr attraksjoner>)
*/
void Byer::skrivAlleByer(){
    if (!byer.empty()) {
        cout << "\n\tAlle byer i datastrukturen:\n";
        for (const auto & val : byer) {     // Sånn det ble gjort for leger i  
            cout << '\t' << val.first;
            (val.second)->skrivAlle();
        }
    } else {
        cout << "\n\t\tDet er ingen byer i datastrukturen!\n";    
    }
    


}

/**
 * 
*/
void Byer::lesFraFil(){

}

/**
 * 
*/
void Byer::skrivTilFil(){

}

/**
 * 
*/
void Byer::handling(char vlg){
    switch (vlg) {
        case 'A': skrivAlleByer(); break;
    }
}