/**
 * Oppgave 11 i heftet
 * 
 * Ferdig: Nei
 * 
 * @file HEF11.cpp
 * @author Jesper Ruud Soløst
 * 
 * @date 15.02.2024
*/

#include <iostream>
#include <string>
#include "LesData2.h"

using namespace std;

/**
 * 
*/
class Posisjon {
    private:
        int grad,                       // 0-90 eller 0-180
            minutt,                     // 0-59
            sekund;                     // 0-59
        char retning;                   // N / S / E / W
    public:
    Posisjon(){

    }
    void lesData(int gr, char r1, char r2){
        grad = gr; 
    }
    void skrivData(){

    }
};

/**
 * Klasse Skip som inneholder nr, navn, breddegrad og lengdegrad
*/
class Skip {
    private:
        int nr;
        string navn;
        Posisjon breddegrad;
        Posisjon lengdegrad;
    public:
    Skip(){
        
    }

    void lesData(){

    }

    void skrivData(){

    }
};

/**
 * Hovedprogrammet:
*/
int main(){

}