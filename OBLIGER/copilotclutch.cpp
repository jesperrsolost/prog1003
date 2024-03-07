#include <iostream>
#include <string>

class Dyr {
protected:
    std::string navn;

public:
    Dyr() {
        lesData();
    }

    virtual void lesData() {
        std::cout << "Skriv inn navnet på dyret: ";
        std::cin >> navn;
    }

    void skrivData() {
        std::cout << "Dyrets navn: " << navn << std::endl;
    }
};

class DyrILuft : public Dyr {
    // Legg til datamedlemmer for DyrILuft
};

class DyrIVann : public Dyr {
    // Legg til datamedlemmer for DyrIVann
};

class Insekt : public DyrILuft {
    // Legg til datamedlemmer for Insekt
};

class Fugl : public DyrILuft {
    // Legg til datamedlemmer for Fugl
};

class Fisk : public DyrIVann {
public:
    Fisk(std::string fiskenavn) {
        navn = fiskenavn;
    }
};

class Skalldyr : public DyrIVann {
    // Legg til datamedlemmer for Skalldyr
};

int main() {
    char valg;
    while (true) {
        std::cout << "Velg dyreart (i/f/s): ";
        std::cin >> valg;

        if (valg == 'i') {
            Insekt insekt;
            insekt.skrivData();
        } else if (valg == 'f') {
            std::string fiskenavn;
            std::cout << "Skriv inn fiskenavnet (trykk ENTER for å bruke standardnavn): ";
            std::cin.ignore(); // Ignorer newline fra forrige input
            std::getline(std::cin, fiskenavn);

            Fisk fisk(fiskenavn);
            fisk.skrivData();
        } else if (valg == 's') {
            // Implementer for skalldyr
        } else {
            std::cout << "Ugyldig valg. Avslutter programmet." << std::endl;
            break;
        }
    }

    return 0;
}
