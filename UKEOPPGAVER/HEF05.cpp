/**
 * Oppgave 5 i heftet
 * 
 * @file HEF05.cpp
 * @author Jesper Ruud Soløst
 * 
 * @date 29.01.2024
*/

#include <iostream>                             // cout, cin
#include <iomanip> 
#include "LesData2.h"                           // lesInt, lesChar     

using namespace std;

const int STRLEN           = 40;  ///< Max.tekstlengde.
const int MAXFORELESNINGER = 10;  ///< Max.antall forelesninger.

struct Forelesning {
    char emne[STRLEN/2],
         foreleser[STRLEN],
         sted[STRLEN/2];
    int timeStart, minuttStart,
        timeSlutt, minuttSlutt;
};

void forelesningLesData(Forelesning* f);
void forelesningSkrivData(const Forelesning* f);

/**
 * Hovedprogrammet:
*/
int main(){
    Forelesning forelesninger[MAXFORELESNINGER];

    for (int i; i < MAXFORELESNINGER; i++){
        forelesningLesData(&forelesninger[i]);
    }
    return 0;
}

/**
 * Leser inn og fyller alle structens seks data med rimelige verdier
*/
void forelesningLesData(Forelesning* f){
    cout << "Emne     : "; cin.getline(f->emne,STRLEN/2);
    cout << "Foreleser: "; cin.getline(f->foreleser,STRLEN);
    cout << "Sted     : "; cin.getline(f->sted,STRLEN/2);
    f->timeStart = lesInt("Time start: ");
    f->minuttStart = lesInt("Minutt start: ");
    f->timeSlutt = lesInt("Time slutt:");
    f->minuttSlutt = lesInt("Minutt slutt:");

}

/**
 * Skriver ut alle structenes seks data
*/
void forelesningSkrivData(const Forelesning* f){

}
