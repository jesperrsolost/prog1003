/**
 * Oppgave 4 i heftet
 * Ferdig: Ja
 * 
 * @file HEF04.cpp
 * @author Jesper Ruud Soløst
 * 
 * @date 29.01.2024
*/
#include <iostream>                                     // cout, cin
#include <iomanip>                                      // setw

using namespace std; 

struct Tid {
    int time,
        minutt,
        sekund;
};

Tid storst(const struct Tid tid1, const struct Tid tid2);

/**
 * Hovedprogrammet:
*/
int main(){
    Tid tid1 = { 1, 1, 1},
        tid2 = { 2, 2, 2},
        tid3 = { 3, 3, 3},
        tid4 = { 4, 4, 4},
        svar;
    svar = storst(tid1, tid2);
    svar = storst(svar, tid3);
    svar = storst(svar, tid4);
    cout << svar.time << ':' << svar.minutt << ':' << svar.sekund
         << " er det seneste tidspunktet av verdiene i structen.";
    return 0;
}

/**
 * Funksjon som finner ut av hvilken av de to parametrene som er 
 * størst/senest/høyest, og returnerer denne.
 * @return 
*/
Tid storst(const Tid tid1, const Tid tid2){
    int tot1 = (tid1.time * 3600) + (tid1.minutt * 60) + tid1.sekund,
        tot2 = (tid2.time * 3600) + (tid2.minutt * 60) + tid2.sekund;
    return ((tot1 >= tot2) ? tid1 : tid2);
}