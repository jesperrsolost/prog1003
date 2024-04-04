#include "byer.h"
#include <iostream>

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
*/
void Byer::skrivAlleByer(){
    std::cout << "PLACEHOLDER";
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