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
const int MAXFORELESNINGER = 1;  ///< Max.antall forelesninger.

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

    for (int i = 0; i < MAXFORELESNINGER; i++) {
        cout << "Data om forelesning nr." << i+1 << "\n";
        forelesningLesData(&forelesninger[i]);
    }
    forelesningSkrivData(&forelesninger[0]);
    return 0;
}

/**
 * Leser inn og fyller alle structens seks data med rimelige verdier
*/
void forelesningLesData(Forelesning* f){
    cout << "Emne     : "; cin.getline(f->emne,STRLEN/2);
    cout << "Foreleser: "; cin.getline(f->foreleser,STRLEN);
    cout << "Sted     : "; cin.getline(f->sted,STRLEN/2);
    f->timeStart = lesInt("Time start: ", 0, 23);
    f->minuttStart = lesInt("Minutt start: ", 0, 59);
    f->timeSlutt = lesInt("Time slutt:", 0, 23);
    f->minuttSlutt = lesInt("Minutt slutt:", 0, 59);

}

/**
 * Skriver ut alle structenes seks data
*/
void forelesningSkrivData(const Forelesning* f){
    cout << f->emne << "\n" << f->foreleser << "\n";
}
