/**
 * Oppgave 4 i heftet
 * Ferdig: Nei
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
}

/**
 * Funksjon som finner ut av hvilken av de to parametrene som er 
 * størst/senest/høyest, og returnerer denne.
 * @return 
*/
struct Tid storst(const struct Tid tid1, const struct Tid tid2){

    return 
}