/**
 * Reinnlevering Oblig nummer 2
 * 
 * @file RettetOBL02.cpp
 * @author Jesper Ruud Soløst
 * 
 * @date 29.02.2024
*/

#include <iostream>                     // cout, cin
#include <string>                       // string, empty()
#include "LesData2.h"                   // Verktøykasse for lesing av div. data

using namespace std;

/**
 * Baseklasse for dyret
*/
class Dyr{
    private:
        string navn;                    // Dyrets navn
    public:
    Dyr() { lesData(); }                // Constructor u/ parameter

    Dyr(const string fiskenvn){         // Constructor m/ parameter
        navn = fiskenvn;                // Setter navn til tilsendt fiskenavn
    }
    
    void lesData(){
        cout << "Navn: ";
        getline(cin, navn);                               // Leser inn navn
    }

    void skrivData(){ cout << "Navn: " << navn << '\n'; } // Skriver ut navn
};

/**
 * Subklasse til dyr som lever i luft
*/
class DyrILuft : public Dyr {
    private:
        string opprinnelsesland;        // Dyrets opprinnelsesland
    public:
    DyrILuft(){ lesData(); }            // Constructor u/ parameter
    
    void lesData(){
        cout << "Opprinnelsesland: ";
        getline(cin, opprinnelsesland);     // Leser inn opprinnelsesland
    }                   
                                            // Skriver ut opprinnelsesland
    void skrivData(){ cout << "Opprinnelsesland: " << opprinnelsesland << '\n'; }
};

/**
 * Subklasse til insekt
*/
class Insekt : public DyrILuft{
    private:
        int antallBein;                 // Insekts antall bein
    public:
    Insekt(){ lesData(); }              // Constructor u/ parameter

                                        // Leser inn antall bein
    void lesData(){ antallBein = lesInt("Antall bein", 0,1000); }
    
    void skrivData(){
        Dyr::skrivData();                               //
        DyrILuft::skrivData();                          // Skriver ut all data
        cout << "Antall bein: " << antallBein << '\n';  //
    }
};

/**
 * Subklasse til fugl
*/
class Fugl : public DyrILuft{
    private:
        int vingespenn;               // Fuglens vingespenn
    public:
    Fugl(){ lesData(); }              // Constructor u/ parameter

                                      // Constructor m/ parameter
    void lesData(){ vingespenn = lesInt("Vingespenn(cm)", 0,9999); }
    
    void skrivData(){
        Dyr::skrivData();                                 //
        DyrILuft::skrivData();                            // Skriver ut all data
        cout << "Vingespenn(cm): " << vingespenn << '\n'; //
    }
};

/**
 * Subklasse til dyr som lever i vann
*/
class DyrIVann : public Dyr {
    private:
        string vanntype;               // Hva slags type vann dyret lever i
    public:
    DyrIVann(){ lesData(); }                          // Constructor u/ parameter
    DyrIVann(const string fiskenvn) : Dyr(fiskenvn){ lesData(); } // m/ parameter

    void lesData(){
        cout << "Vanntype (fersk/salt): ";           
        getline(cin, vanntype);        // Leser inn vanntype
    }
                                       // Skriver ut vanntype
    void skrivData(){ cout << "Vanntype: " << vanntype << '\n'; }
};

/**
 * Subklasse til fisk
*/
class Fisk : public DyrIVann {
    private:
        int vekt;                             // Fiskens vekt
    public:
    Fisk(){ lesData(); }                      // Constructor u/ parameter

    Fisk(const string fiskenvn) : DyrIVann(fiskenvn){ // Constructor m/parameter
        lesData(); 
        } 

    void lesData(){
        vekt = lesInt("Vekt(g)", 0, 9999);            // Leser inn vekt
    }

    void skrivData(){ 
        Dyr::skrivData();                             //
        DyrIVann::skrivData();                        // Skriver ut all data
        cout << "Vekt(g): " << vekt << '\n';          //
    }
};

/**
 * Subklasse til skalldyr
*/
class Skalldyr : public DyrIVann {
    private:
        bool spisende;              // Er skalldyret spisende?
    public:
    Skalldyr(){ lesData(); }        // Constructor u/ parameter

    void lesData(){                 // Spør om skalldyret er spisende
        spisende = lesInt("Spisende?(0/1)", 0, 1);
    }

    void skrivData(){ 
        Dyr::skrivData();           //
        DyrIVann::skrivData();      // Skriver ut all data
        cout << "Spisende: ";       //
        if (spisende){ cout << "Ja"; } else {cout << "Nei"; }
    }
};

void skrivMeny();                   // Skriver ut meny


// --------------------------------------------------------------------------

/**
 * Hovedprogrammet:
*/
int main(){
    char   kommando;                            // Initierer variabler
    string fiskenavn;                           //

    skrivMeny();                                // Skriver ut meny

    kommando = lesChar("\nKommando");           // Spør etter kommando

    while (kommando != 'Q') {
        Insekt*   insekt   = nullptr;           //
        Fugl*     fugl     = nullptr;           // Setter pekere til nullptr 
        Fisk*     fisk     = nullptr;           // som standard
        Skalldyr* skalldyr = nullptr;           //

        switch (kommando) {
            case 'I': {
                insekt = new Insekt(); insekt->skrivData();       // Leser/skriver ut 
                delete insekt; insekt = nullptr; break;           // Sletter insekt
            }
            case 'B': { 
                fugl = new Fugl(); fugl->skrivData();             // Leser/skriver ut  
                delete fugl; fugl = nullptr; break;               // Sletter fugl
            }
            case 'F': {
                // Veksler med/uten fiskenavn som parameter og leser inn deretter
                cout << "Fiskenavn(enter for u/ parameter): ";
                getline(cin, fiskenavn);
                fisk = (fiskenavn.empty()) ? new Fisk() : new Fisk(fiskenavn);
                
                fisk->skrivData();                                // Skriver ut                               
                delete fisk; fisk = nullptr; break;               // Sletter fisk
            }
            case 'S': {
                skalldyr = new Skalldyr(); skalldyr->skrivData(); // Leser/skriver ut 
                delete skalldyr; skalldyr = nullptr; break;       // Sletter skalldyr
            }
        }

        kommando = lesChar("\nKommando");           // Spør etter ny kommando
    }

    return 0;                                       // Avslutter programmet
}

// --------------------------------------------------------------------------

/**
* Skriver programmets menyvalg/muligheter p� skjermen.
*/
void skrivMeny() {
cout << "\nF�lgende kommandoer er tilgjengelig:\n"
<< "\tI - Insekt\n"
<< "\tB - Fugl\n"
<< "\tS - Skalldyr\n"
<< "\tF - Fisk\n"
<< "\tQ - Quit / avslutt\n";
}