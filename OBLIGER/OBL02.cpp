/**
 * Oblig nummer 2
 * 
 * @file OBL02.cpp
 * @author Jesper Ruud Soløst
 * 
 * @date 26.02.2024
*/

#include <iostream>                      // cout, cin
#include <string>                        // string
#include "LesData2.h"                    // Verktøykasse for lesing av div. data

using namespace std;

/**
 * Baseklasse for dyret
*/
class Dyr{
    protected:
        string navn;                            // Dyrets navn
    public:
    Dyr() { }
    virtual void lesData() {
        cout << "Skriv inn navn for dyret: ";
        getline(cin, navn);                     // Leser inn dyrenavn
    }
    virtual void skrivData(){
        cout << "Navn: " << navn << '\n';       // Skriver ut dyrenavn
    }
    Dyr(const string& dyreNavn) : navn(dyreNavn){
        navn = dyreNavn;                        // Oppdaterer dyrenavn
    }
};

/**
 * Subklasse med dyr i luft
*/
class DyrILuft : public Dyr {
    private:
        string omraade;                              // Område dyret lever i
    public:
        DyrILuft() {}
        ~DyrILuft() {}
        void lesData() {
            Dyr::lesData();
            cout << "Skriv inn omraade: ";
            getline(cin, omraade);                   // Leser inn område
        }
        void skrivData(){
            Dyr::skrivData();
            cout << "Omraade: " << omraade << '\n'; // Skriver ut område
        }
};

/**
 * Subklasse med Insekt
*/
class Insekt : public DyrILuft {
    private:
        int bein;                                   // Innsektets antall bein
    public:
        Insekt(){ lesData();}
        void lesData(){
            DyrILuft::lesData();                    // Leser inn data i DyrILuft
            bein = lesInt("Antall bein", 0,1000);   // Leser inn antall bein
        }
        void skrivData(){
            DyrILuft::skrivData();                  // Skriver ut data fra DyrILuft
            cout << "Antall bein: " << bein << '\n';// Skriver ut antall bein
        }
};

/**
 * Subklasse med Fugl
*/
class Fugl : public DyrILuft {
    private:
        int vingespenn;                         // Fuglens vingespenn
    public:
        Fugl(){ lesData();}
        void lesData(){
            DyrILuft::lesData();                // Leser inn data i DyrILuft
            vingespenn = lesInt("Vingespenn i cm", 0,100); // Leser inn vingespenn
        }
        void skrivData(){
            DyrILuft::skrivData();              // Skriver ut data fra DyrILuft
            cout << "Vingespenn: " << vingespenn << '\n'; // Skriver ut vingespenn
        }
};

/**
 * Subklasse med dyr i vann
*/
class DyrIVann : public Dyr {
    private:
        string vannType;                        // Dyrets vanntype
    public:
        DyrIVann() {}
        ~DyrIVann() {}
        void lesData() {
            Dyr::lesData();                     // Leser inn data fra Dyr
            cout << "Skriv inn vanntype (salt/fersk): ";
            getline(cin, vannType);             // Leser inn vanntypen
        }
        void skrivData(){
            Dyr::skrivData();                   // Skriver ut data fra Dyr
            cout << "Vanntype: " << vannType << '\n'; // Skriver ut vanntypen
        }
        DyrIVann(const string& fiskenavn) {     // Dersom fiskenavn er tilsendt
            cout << "Skriv inn vanntype (salt/fersk): ";
            getline(cin, vannType);             // Leser inn vanntype
        }

};

/**
 * Subklasse med fisk
*/
class Fisk : public DyrIVann {
    private:
        int lengde;                         // Fiskens lengde
    public:
        Fisk(){ lesData();}
        void lesData(){
            DyrIVann::lesData();            // Leser inn data fra DyrIVann
            lengde = lesInt("Lengde i cm", 0,100); // Leser inn lengden
        }
        void skrivData(){
            DyrIVann::skrivData();          // Skriver ut data fra DyrIVann
            cout << "Lengde: " << lengde << '\n'; // Skriver ut lengden
        }
        Fisk(const string& fiskenavn) : DyrIVann(fiskenavn){ // Dersom fiskenavn
                                                             // er tilsendt
            navn = fiskenavn;           // oppdaterer navn til Dyr
            lengde = lesInt("Lengde i cm", 0,100); // Leser inn lengde
        }
};
/**
 * Subklasse med skalldyr
*/
class Skalldyr : public DyrIVann {
    private:
        bool spisende;                      // Er skalldyret spisende?
    public:
        Skalldyr(){ lesData();}
        void lesData(){
            DyrIVann::lesData();            // Leser inn data fra DyrIVann
            spisende = lesInt("Spisende?", 0,1); // Spør om dyret er spisende
        }
        void skrivData(){
            DyrIVann::skrivData();          // Skriver ut data fra DyrIVann
            cout << "Spisende: ";       
            if (spisende) {                 //
                cout << "Ja";               // Dersom dyret er spisende skriver
            } else {                        // den ut "ja", ellers "nei".
                cout << "Nei";              //
            }
        }
};

void skrivMeny();                           // Skriver ut meny

/**
 * Hovedprogrammet:
*/
int main(){
    char kommando;                          // Kommando variabel

    skrivMeny();                            // Skriver ut meny
    kommando = lesChar("\nKommando");       // Leser inn kommando

    while (kommando != 'Q') {               // Sålenge brukeren ikke exiter
        Dyr* dyret = nullptr;               // Setter peker til nullptr som standard
        switch (kommando) {
            case 'I': dyret = new Insekt();     break;
            case 'B': dyret = new Fugl();       break;
            case 'F': { // Dersom fisk er valgt, bestemmer den med/uten parameter
                string fiskenavn;
                cout << "Skriv inn fiskenavn: ";
                getline(cin, fiskenavn);
                dyret = (fiskenavn.empty()) ? new Fisk() : new Fisk(fiskenavn);       
            } break;
            case 'S': dyret = new Skalldyr();   break;
        }
        
        cout << '\n';                       // Pustelinje

        dyret->skrivData();                 // Skriver ut info om dyret

        delete dyret;                       // Sletter dyret etter utskrift
        dyret = nullptr;                    // Setter tilbake til nullptr

        kommando = lesChar("\nKommando");   // Spør om ny kommando
    }
    return 0;                               // Avslutter programmet
}

/**
 *  Skriver programmets menyvalg/muligheter p� skjermen.
 */
void skrivMeny() {
    cout << "\nF�lgende kommandoer er tilgjengelig:\n"
         << "\tI - Insekt\n"
         << "\tB - Fugl\n"
         << "\tS - Skalldyr\n"
         << "\tF - Fisk\n"
         << "\tX - Skriv alle\n"
         << "\tQ - Quit / avslutt\n";
}
