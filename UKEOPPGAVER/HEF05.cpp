/**
 * Oppgave 5 i heftet
 * 
 * Ferdig: Ja
 * 
 * @file HEF05.cpp
 * @author Jesper Ruud Soløst
 * 
 * @date 29.01.2024
*/

#include <iostream>                             // cout, cin
#include "LesData2.h"                           // lesInt, lesChar     

using namespace std;

const int STRLEN           = 40;  ///< Max.tekstlengde.
const int MAXFORELESNINGER = 2;  ///< Max.antall forelesninger.

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

    for (int i = 0; i < MAXFORELESNINGER; i++) {            // Leser inn data
        cout << "Data om forelesning nr." << i+1 << "\n";
        forelesningLesData(&forelesninger[i]);
    }
    
    for (int i = 0; i < MAXFORELESNINGER; i++){             // Skriver ut data
        cout << "Data om forelesning " << i+1 << ":\n";
        forelesningSkrivData(&forelesninger[i]);
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
    f->timeStart = lesInt("Time start: ", 0, 23);
    f->minuttStart = lesInt("Minutt start: ", 0, 59);
    f->timeSlutt = lesInt("Time slutt:", 0, 23);
    f->minuttSlutt = lesInt("Minutt slutt:", 0, 59);

    cout << "\n\n";
}

/**
 * Skriver ut alle structenes seks data
*/
void forelesningSkrivData(const Forelesning* f){
    cout  << "Emne     : " << f->emne << "\n" 
          << "Foreleser: " << f->foreleser << "\n"
          << "Sted     : " << f->sted << "\n"
          << "Tidspunkt: " << f->timeStart << ":" << f->minuttStart << " - "
          << f->timeSlutt << ":" << f->minuttSlutt;
    
    cout << "\n\n";
}
