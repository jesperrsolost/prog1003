/**
 * Oppgave 13 i heftet
 * 
 * Ferdig: Nei
 * 
 * @file HEF13.cpp
 * @author Jesper Ruud Soløst
 * 
 * @date 05.03.2024
*/

#include <iostream>
#include <string>
#include "LesData2.h"

using namespace std;

/**
 * Klasse med publikasjoner
*/
class Publikasjon{
    private:
        string navn;
        int aar;
    public:
    void lesData(){
        cout << "Navn: "; getline(cin, navn);
        aar = lesInt("Aar", 0, 999);
    }
    void skrivData(){
        cout << "Navn: " << navn << '\n';
        cout << "Aar : " << aar  << '\n';
    }
};

/**
 * Subklasse med bok, avledet fra klassen publikasjon
*/
class Bok : public Publikasjon {
    private:
        string forfatter,
               ISBN;
        float pris;
    public:
    void lesData(){
        Publikasjon::lesData();
        cout << "Forfatter: "; getline(cin, forfatter);
        cout << "ISBN     : "; getline(cin, ISBN);
        pris = lesFloat("Pris     ", 0, 9999);
    }

    void skrivData(){
        Publikasjon::skrivData(); // Kaller forelder sin skrivData()
        cout << "Forfatter: " << forfatter << '\n'; //
        cout << "ISBN     : " << forfatter << '\n'; // Skriver ut data
        cout << "Pris     : " << forfatter << '\n'; //
    }
};

/**
 * Subklasse med blad, avledet fra klassen Publikasjon
*/
class Blad : public Publikasjon {
    private:
        int nummer,          // Bladets nummer
            ukeNr,           // Bladets utgivelsesuke
            aarsAbonnement;  // Vet ikke helt
    public:
    void lesData(){
        Publikasjon::lesData();
        nummer         = lesInt("Nummer        ", 1, 9999); //
        ukeNr          = lesInt("UkeNr         ", 1, 52  ); // Leser inn dataen
        aarsAbonnement = lesInt("Aarsabonnement", 0, 99  ); //
    }
    void skrivData(){
        Publikasjon::skrivData();
        cout << "Nummer        : " << nummer         << '\n';
        cout << "UkeNr         : " << ukeNr          << '\n';
        cout << "aarsAbonnement: " << aarsAbonnement << '\n';
    }
};

/**
 * Hovedprogrammet:
*/
int main(){
    Bok*  boka   = nullptr;           // Setter boka til nullptr som standard
    Blad* bladet = nullptr;           // Setter bladet til nullptr som standard

    char svar;                        // Svar fra bruker

    do{
        svar = lesChar("Les inn\n1. Bok\n2. Blad\nKommando"); // Spør om kommando
        switch (svar){
            case '1' : {
                boka = new Bok(); boka->skrivData();      // Lager og skriver ut
                delete boka; boka = nullptr; break;       // Sletter boka
            }
            case '2' : {
                bladet = new Blad(); bladet->skrivData(); // Lager og skriver ut
                delete bladet; bladet = nullptr; break;   // Sletter bladet
            }
        }

        svar = lesChar("Lese inn ny bok/blad? (J/n): ");  // Ny innlesing?
    } while (svar != 'N');
    
    return 0;
}