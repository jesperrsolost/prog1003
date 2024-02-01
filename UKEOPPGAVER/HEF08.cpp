/**
 * Oppgave 8 i heftet
 * 
 * Ferdig: Ja
 * 
 * @file HEF08.cpp
 * @author Jesper Ruud Soløst
 * 
 * @date 01.02.2024
*/

#include <iostream>
#include <string>
#include <vector>
#include "LesData2.h"

using namespace std;

struct Kamp {
    string hjemmeNavn,
           borteNavn;
    int    hjemmeMaal,
           borteMaal;
};

void kampLesData(Kamp & kamp);
void kampSkrivData(const Kamp* kamp);

vector <Kamp*> gKampene;

/**
 * Hovedprogrammet:
*/
int main(){
    char svar;
    
    do{
        Kamp* nyKamp = new Kamp;
        cout << "\nData om kamp:\n";
        kampLesData(*nyKamp);
        gKampene.push_back(nyKamp);
        cout << "\n\tNy kamp lagt til har nr. " << gKampene.size() << "\n";

        svar = lesChar("Lese inn data for ny kamp? (j/n): ");
    } while (svar == 'J');

    for (int i = 0; i < gKampene.size(); i++){
        cout << "\n\tKamp nr. " << setw(2) << i + 1 << ":\n";
        kampSkrivData(gKampene[i]);
    }

    for (int i = 0; i < gKampene.size(); i++){
        delete gKampene[gKampene.size()-1];
    }
    gKampene.clear(); 
}

/**
 * Hver kamp sine data leses inn
 * 
 * @param kamp - Structen som får sine datamedlemmer innlest/fylt
*/
void kampLesData(Kamp & kamp){
    cout << "Hjemmelag: "; getline(cin, kamp.hjemmeNavn);
    cout << "Bortelag : "; getline(cin, kamp.borteNavn);
    kamp.hjemmeMaal = lesInt("Poeng til hjemmelag", 0, 100);
    kamp.borteMaal = lesInt("Poeng til bortlag  ", 0, 100);
}

/**
 * Skriver ut alle de lagrede kampene sine data
 * 
 * @param kamp - Structen som får sine datamedlemmer skrevet ut
*/
void kampSkrivData(const Kamp* kamp){
    cout << "\t" << kamp->hjemmeNavn << " mot " << kamp->borteNavn << "\n"
         << "\t" << kamp->hjemmeMaal << " - " << kamp->borteMaal << "\n";
}
