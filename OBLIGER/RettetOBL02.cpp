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
    
    void lesData();
    void skrivData();
};

/**
 * Subklasse til dyr som lever i luft
*/
class DyrILuft : public Dyr {
    private:
        string opprinnelsesland;            // Dyrets opprinnelsesland
    public:
    DyrILuft(){ lesData(); }                // Constructor u/ parameter
    
    void lesData();                 
    void skrivData();
};

/**
 * Subklasse til insekt
*/
class Insekt : public DyrILuft{
    private:
        int antallBein;                 // Insekts antall bein
    public:
    Insekt(){ lesData(); }              // Constructor u/ parameter

    void lesData();
    void skrivData();
};

/**
 * Subklasse til fugl
*/
class Fugl : public DyrILuft{
    private:
        int vingespenn;               // Fuglens vingespenn
    public:
    Fugl(){ lesData(); }              // Constructor u/ parameter

    void lesData();
    void skrivData();
};

/**
 * Subklasse til dyr som lever i vann
*/
class DyrIVann : public Dyr {
    private:
        string vanntype;                    // Hva slags type vann dyret lever i
    public:
    DyrIVann(){ lesData(); }                          // Constructor u/ parameter
    DyrIVann(const string fiskenvn) : Dyr(fiskenvn){ lesData(); } // m/ parameter

    void lesData();
    void skrivData();
};

/**
 * Subklasse til fisk
*/
class Fisk : public DyrIVann {
    private:
        int vekt;                                     // Fiskens vekt
    public:
    Fisk(){ lesData(); }                              // Constructor u/ parameter

    Fisk(const string fiskenvn) : DyrIVann(fiskenvn){ // Constructor m/parameter
        lesData(); 
    } 

    void lesData();
    void skrivData();
};

/**
 * Subklasse til skalldyr
*/
class Skalldyr : public DyrIVann {
    private:
        bool spisende;            // Er skalldyret spisende?
    public:
    Skalldyr(){ lesData(); }      // Constructor u/ parameter

    void lesData();
    void skrivData();
};

void skrivMeny();                 // Skriver ut meny


// ------------------------------Main loop------------------------------------

/**
 * Hovedprogrammet:
*/
int main(){
    char   kommando;                            // Initierer variabler
    string fiskenavn;                           //

    Insekt*   insekt   = nullptr;               //
    Fugl*     fugl     = nullptr;               // Setter pekere til nullptr 
    Fisk*     fisk     = nullptr;               // som standard
    Skalldyr* skalldyr = nullptr;               //
    
    skrivMeny();                                // Skriver ut meny

    kommando = lesChar("\nKommando");           // Spør etter kommando

    while (kommando != 'Q') {
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

// -----------------------------Funksjoner------------------------------------

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

// --------------------Funksjoner tilhørende klasser--------------------------

/**
 * Funksjon som leser inn data for Dyr klassen
*/
void Dyr::lesData(){
        cout << "Navn: ";
        getline(cin, navn);                     // Leser inn navn
    }

/**
 * Funksjon som skriver ut Dyr sin data
*/
void Dyr::skrivData(){ 
    cout << "Navn: " << navn << '\n';           // Skriver ut navn
} 

/**
 * Funksjoner som leser inn data for DyrILuft
*/
void DyrILuft::lesData(){
    cout << "Opprinnelsesland: ";
    getline(cin, opprinnelsesland);     // Leser inn opprinnelsesland
} 

/**
 * Funksjon som skriver ut DyrILuft sin data
 * 
 * @see Dyr::skrivData()
*/
void DyrILuft::skrivData(){ 
    Dyr::skrivData();           // Kaller Dyr sin skrivData()
                                // Skriver ut opprinnelsesland
    cout << "Opprinnelsesland: " << opprinnelsesland << '\n'; 
}

/**
 * Funksjon som leser inn data for DyrIVann
*/
void DyrIVann::lesData(){
    cout << "Vanntype (fersk/salt): ";           
    getline(cin, vanntype);        // Leser inn vanntype
}

/**
 * Funksjon som skriver ut DyrIVann sin data
 * 
 * @see Dyr::skrivData()
*/
void DyrIVann::skrivData(){
    Dyr::skrivData();                          // Kaller Dyr sin skrivdata() 
    cout << "Vanntype: " << vanntype << '\n';  // Skriver ut vanntype
}

/**
 * Funksjon som leser inn data for Insekt
*/
void Insekt::lesData(){ 
    antallBein = lesInt("Antall bein", 0,1000); 
}

/**
 * Funksjon som skriver ut Insekt sin data
 * 
 * @see DyrILuft::skrivData()
*/
void Insekt::skrivData(){
    DyrILuft::skrivData();                // Kaller DyrILuft sin skrivData() 
    cout << "Antall bein: " << antallBein << '\n'; // Skriver ut antall bein
}

/**
 * Funksjon som leser inn data for Fugl 
*/
void Fugl::lesData(){ 
    vingespenn = lesInt("Vingespenn(cm)", 0,9999); 
}

/**
 * Funksjon som skriver ut Fugl sin data
 * 
 * @see DyrILuft::skrivData()
*/
void Fugl::skrivData(){
    DyrILuft::skrivData();                    // Kaller DyrILuft sin skrivData()
    cout << "Vingespenn(cm): " << vingespenn << '\n';// Skriver ut vingespenn
}

/**
 * Funksjon som leser inn data for Fisk
*/
void Fisk::lesData(){
    vekt = lesInt("Vekt(g)", 0, 9999);            // Leser inn vekt
}

/**
 * Funksjon som skriver ut Fisk sin data
 * 
 * @see DyrIVann::skrivData()
*/
void Fisk::skrivData(){                             
    DyrIVann::skrivData();                // Kaller DyrIVann sin skrivData()
    cout << "Vekt(g): " << vekt << '\n';  // Skriver ut vekt
}

/**
 * Funksjon som leser inn data for Skalldyr
*/
void Skalldyr::lesData(){                 // Spør om skalldyret er spisende
    spisende = lesInt("Spisende?(0/1)", 0, 1);
}

/**
 * Funksjon som skriver ut Skalldyr sin data
 * 
 * @see DyrIVann::skrivData()
*/
void Skalldyr::skrivData(){ 
    DyrIVann::skrivData();      // Kaller DyrIVann sin skrivData()
    cout << "Spisende: ";       //Skriver ut om spisende eller ei
    if (spisende){ cout << "Ja"; } else {cout << "Nei"; }
}