#include <iostream>
#include <string>

class Dyr {
private:
    std::string navn;

public:
    Dyr() {
        lesData();
    }

    virtual ~Dyr() {}

    virtual void lesData() {
        std::cout << "Skriv inn navn for dyret: ";
        std::getline(std::cin, navn);
    }

    virtual void skrivData() const {
        std::cout << "Navn: " << navn << std::endl;
    }
};

class DyrILuft : public Dyr {
private:
    // Legg til eventuelle datamedlemmer

public:
    DyrILuft() {}

    ~DyrILuft() {}

    void lesData() override {
        Dyr::lesData();
        // Les inn data for DyrILuft
    }

    void skrivData() const override {
        Dyr::skrivData();
        // Skriv ut data for DyrILuft
    }
};

class Insekt : public DyrILuft {
private:
    // Legg til eventuelle datamedlemmer

public:
    Insekt() {}

    ~Insekt() {}

    void lesData() override {
        DyrILuft::lesData();
        // Les inn data for Insekt
    }

    void skrivData() const override {
        DyrILuft::skrivData();
        // Skriv ut data for Insekt
    }
};

class Fugl : public DyrILuft {
private:
    // Legg til eventuelle datamedlemmer

public:
    Fugl() {}

    ~Fugl() {}

    void lesData() override {
        DyrILuft::lesData();
        // Les inn data for Fugl
    }

    void skrivData() const override {
        DyrILuft::skrivData();
        // Skriv ut data for Fugl
    }
};

class DyrIVann : public Dyr {
private:
    // Legg til eventuelle datamedlemmer

public:
    DyrIVann() {}

    ~DyrIVann() {}

    void lesData() override {
        Dyr::lesData();
        // Les inn data for DyrIVann
    }

    void skrivData() const override {
        Dyr::skrivData();
        // Skriv ut data for DyrIVann
    }
};

class Fisk : public DyrIVann {
private:
    // Legg til eventuelle datamedlemmer

public:
    Fisk() {}

    Fisk(const std::string& fiskenavn) : DyrIVann(fiskenavn) {}

    ~Fisk() {}

    void lesData() override {
        DyrIVann::lesData();
        // Les inn data for Fisk
    }

    void skrivData() const override {
        DyrIVann::skrivData();
        // Skriv ut data for Fisk
    }
};

class Skalldyr : public DyrIVann {
private:
    // Legg til eventuelle datamedlemmer

public:
    Skalldyr() {}

    ~Skalldyr() {}

    void lesData() override {
        DyrIVann::lesData();
        // Les inn data for Skalldyr
    }

    void skrivData() const override {
        DyrIVann::skrivData();
        // Skriv ut data for Skalldyr
    }
};

int main() {
    char valg;

    do {
        std::cout << "Velg dyreart (I - Insekt, F - Fugl, K - Skalldyr, S - Fisk, X - Avslutt): ";
        std::cin >> valg;
        std::cin.ignore(); // Ignorer newline karakter i input buffer

        Dyr* dyret;

        switch (valg) {
            case 'I':
                dyret = new Insekt();
                break;
            case 'F':
                dyret = new Fugl();
                break;
            case 'K':
                dyret = new Skalldyr();
                break;
            case 'S': {
                std::string fiskenavn;
                std::cout << "Skriv inn fiskenavn (trykk ENTER for ingen navn): ";
                std::getline(std::cin, fiskenavn);
                dyret = (fiskenavn.empty()) ? new Fisk() : new Fisk(fiskenavn);
                break;
            }
            case 'X':
                std::cout << "Avslutter programmet." << std::endl;
                return 0;
            default:
                std::cout << "Ugyldig valg. Prøv igjen." << std::endl;
                continue;
        }

        dyret->.skrivData();

        delete dyret;

    } while (valg != 'X');

    return 0;
}
