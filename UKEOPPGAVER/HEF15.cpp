/**
 * Oppgave 15 i heftet
 * 
 * Ferdig: Nei
 * 
 * @file HEF15.cpp
 * @author Jesper Ruud Soløst
 * 
 * @date 06.03.2024
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Klasse Kjoretoy med regNr.
*/
class Kjoretoy {
    private:
        string registreringsNr;
    public:
        virtual void lesData(){

        }
};

/**
 * Subklasse Bil med antall passasjerer
*/
class Bil : public Kjoretoy {
    private:
        int antPassasjerer;
    public:
        virtual void lesData(){
            
        }
};

/**
 * Subklasse Vogntog med tonn last
*/
class Vogntog : public Kjoretoy {
    private:
        float tonnLast;
    public:
        virtual void lesData(){
            
        }
};

vector <Kjoretoy*> gKjoretoy;

/**
 * Hovedprogrammet:
*/
int main(){
    char svar;

    do {
        cout << "";
    } while (svar != 'N');
    return 0;
}