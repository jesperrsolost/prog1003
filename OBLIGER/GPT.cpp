/**
 * Oblig nummer 2
 * 
 * @file OBL02.cpp
 * @author Jesper Ruud Soløst
 * 
 * @date 21.02.2024
*/

#include <iostream>
#include <vector>
#include <string>
#include "LesData2.h"

using namespace std;

// ... (Eksisterende kode)

/**
 * Baseklasse for dyr med navn
 */
class Dyr {
protected:
    string navn;

public:
    // Legg til denne konstruktoren
    Dyr(const string& dyreNavn) : navn(dyreNavn) {}

    Dyr() {
        lesData();
    }

    virtual void lesData() {
        cout << "Skriv inn navn for dyret: ";
        getline(cin, navn);
    }

    virtual void skrivData() {
        cout << "Navn: " << navn << '\n';
    }
};

/**
 * Subklasse med dyr i luft
*/
class DyrILuft : public Dyr {
private:
    string omraade;

public:
    DyrILuft() {}

    ~DyrILuft() {}

    void lesData() override {
        Dyr::lesData();
        cout << "Skriv inn omraade: ";
        getline(cin, omraade);
    }

    void skrivData() override {
        Dyr::skrivData();
        cout << "Omraade: " << omraade << '\n';
    }
};

/**
 * Subklasse med Insekt
*/
class Insekt : public DyrILuft {
private:
    int bein;

public:
    Insekt() {
        lesData();
    }

    void lesData() override {
        DyrILuft::lesData();
        bein = lesInt("Antall bein", 0, 1000);
    }

    void skrivData() override {
        DyrILuft::skrivData();
        cout << "Antall bein: " << bein << '\n';
    }
};

/**
 * Subklasse med Fugl
*/
class Fugl : public DyrILuft {
private:
    int vingespenn;

public:
    Fugl() {
        lesData();
    }

    void lesData() override {
        DyrILuft::lesData();
        vingespenn = lesInt("Vingespenn i cm", 0, 100);
    }

    void skrivData() override {
        DyrILuft::skrivData();
        cout << "Vingespenn: " << vingespenn << '\n';
    }
};

/**
 * Subklasse med dyr i vann
 */
class DyrIVann : public Dyr {
private:
    string vannType;

public:
    DyrIVann() {
        lesData();
    }

    // Legg til denne konstruktoren
    DyrIVann(const string& dyreNavn) : Dyr(dyreNavn) {
        lesData();
    }

    ~DyrIVann() {}

    void lesData() override {
        Dyr::lesData();
        cout << "Skriv inn vanntype (salt/fersk): ";
        getline(cin, vannType);
    }

    void skrivData() override {
        Dyr::skrivData();
        cout << "Vanntype: " << vannType << '\n';
    }
};

/**
 * Subklasse med fisk
 */
class Fisk : public DyrIVann {
private:
    int lengde;

public:
    Fisk() : DyrIVann(), lengde(0) {
        // Les fiske-spesifikke data
        lesLengde();
    }

    Fisk(const string& fiskenavn) : DyrIVann(fiskenavn), lengde(0) {
        // Ingen lesing av data her, da DyrIVann constructor allerede tar seg av det.
        lesLengde();
    }

    void lesData() override {
        // Kall kun DyrIVann::lesData() hvis navn ikke er satt
        if (navn.empty()) {
            DyrIVann::lesData();
        }
        // Kall lesLengde() uansett
        lesLengde();
    }

    void lesLengde() {
        lengde = lesInt("Lengde i cm", 0, 100);
    }

    void skrivData() override {
        DyrIVann::skrivData();
        cout << "Lengde: " << lengde << '\n';
    }
};







/**
 * Subklasse med skalldyr
*/
class Skalldyr : public DyrIVann {
private:
    bool spisende;

public:
    Skalldyr() {
        lesData();
    }

    void lesData() override {
        DyrIVann::lesData();
        spisende = lesInt("Spisende?", 0, 1);
    }

    void skrivData() override {
        DyrIVann::skrivData();
        cout << "Spisende: ";
        if (spisende) {
            cout << "Ja";
        } else {
            cout << "Nei";
        }
        cout << '\n';
    }
};

// ... (Eksisterende kode)

void skrivMeny();

/**
 * Hovedprogrammet:
 */
int main() {
    char kommando;

    skrivMeny();
    kommando = lesChar("\nKommando");

    while (kommando != 'Q') {
        Dyr* dyret = nullptr;
        switch (kommando) {
            case 'I':
                dyret = new Insekt();
                break;
            case 'B':
                dyret = new Fugl();
                break;
            case 'F':
                {
                    string fiskenavn;
                    cout << "Skriv inn fiskenavn (trykk enter for parameterløs constructor): ";
                    getline(cin, fiskenavn);
                    dyret = (fiskenavn.empty()) ? new Fisk() : new Fisk(fiskenavn);
                }
                break;
            case 'S':
                dyret = new Skalldyr();
                break;
        }

        cout << '\n';

        dyret->skrivData();

        delete dyret;
        dyret = nullptr;

        kommando = lesChar("\nKommando");
    }
    return 0;
}

/**
 * Skriver programmets menyvalg/muligheter p� skjermen.
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
