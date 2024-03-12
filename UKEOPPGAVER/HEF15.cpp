/**
 * Oppgave 15 i heftet
 * 
 * Ferdig: Ja
 * 
 * @file HEF15.cpp
 * @author Jesper Ruud Soløst
 * 
 * @date 06.03.2024
*/

#include <iostream>
#include <string>
#include <vector>
#include "LesData2.h"
#include "LesData2.h"

using namespace std;

/**
 * Klasse Kjoretoy med regNr.
*/
class Kjoretoy {
    private:
        string regNr;
    public:
        virtual void lesData(){
            cout << "RegNr: "; getline(cin, regNr);
        }
        virtual void skrivData(){
            cout << "\nRegNr: " << regNr << '\n';
        }
        virtual bool tomt() const = 0;
};

/**
 * Subklasse Bil med antall passasjerer
*/
class Bil : public Kjoretoy {
    private:
        int antPassasjerer;
    public:
        virtual void lesData(){
            Kjoretoy::lesData();
            antPassasjerer = lesInt("Antall passasjerer", 0, 6);
        }
        virtual void skrivData(){
            Kjoretoy::skrivData();
            cout << "Antall passasjerer: " << antPassasjerer << '\n';
        }
        virtual bool tomt() const { return (antPassasjerer == 0); }
};

/**
 * Subklasse Vogntog med tonn last
*/
class Vogntog : public Kjoretoy {
    private:
        float tonnLast;
    public:
        virtual void lesData(){
            Kjoretoy::lesData();
            tonnLast = lesFloat("Tonn last", 0, 100);
        }
        virtual void skrivData(){
            Kjoretoy::skrivData();
            cout << "Tonn last: " << tonnLast << '\n';
        }
        virtual bool tomt() const { return (tonnLast == 0.0F); }
};

vector <Kjoretoy*> gKjoretoyene;

/**
 * Hovedprogrammet:
*/
int main(){
    Kjoretoy* nyttKjoretoy;
    char type;

    do {
        do {
            type = lesChar("B(il) eller V(ogntog)?");
        } while (type != 'B' && type != 'V');
        if (type == 'B'){ nyttKjoretoy = new Bil;     }
        else            { nyttKjoretoy = new Vogntog; }

        nyttKjoretoy->lesData(); // Leser inn aktuelle data

        gKjoretoyene.push_back(nyttKjoretoy); // Legger inn i vektoren

        type = lesChar("Lese inn nytt kjoretoy?(J/n)");
    } while (type != 'N');

    // Skriver ut ant. kjoretoy
    cout << "Antall kjoretoy: " << gKjoretoyene.size() << '\n';

    // Skriver ut alle kjoretoy
    for (int i = 0; i < gKjoretoyene.size(); i++){ 
        cout << "\nKjoretoy nr." << i+1 << ":  ";
        gKjoretoyene[i]->skrivData(); cout << '\n';
    }

    // Skriver nr. til de tomme:
    cout << "Kjoretoyene som er tomme (for passasjerer eller last):\nNr:";
    for (int i = 0; i < gKjoretoyene.size(); i++){
        if (gKjoretoyene[i]->tomt()) cout << "  " << i+1;
    }

    // Sletter alle kjoretoyene og alle pekerne til dem
    for (int i = 0; i < gKjoretoyene.size(); i++){
        delete gKjoretoyene[i];
    }
    gKjoretoyene.clear();

    cout << "\n\n";

    return 0;
}