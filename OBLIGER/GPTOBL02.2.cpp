#include <iostream>
#include <string>

using namespace std;

class Dyr {
protected:
    string navn;

public:
    Dyr() {
        lesData();
    }

    virtual void lesData() {
        cout << "Skriv inn navn for dyret: ";
        cin >> navn;
    }

    void skrivData() {
        cout << "Dyreart: " << "tttttt" << endl;
        cout << "Navn: " << navn << endl;
    }
};

class DyrILuft : public Dyr {
private:
    string luftArt;

public:
    void lesData() override {
        Dyr::lesData();
        cout << "Skriv inn luftarten for dyret: ";
        cin >> luftArt;
    }

    void skrivData() {
        Dyr::skrivData();
        cout << "Luftart: " << luftArt << endl;
    }
};

class Insekt : public DyrILuft {
private:
    string insektType;

public:
    void lesData() override {
        DyrILuft::lesData();
        cout << "Skriv inn type insekt: ";
        cin >> insektType;
    }

    void skrivData() {
        DyrILuft::skrivData();
        cout << "Insekttype: " << insektType << endl;
    }
};

class Fugl : public DyrILuft {
private:
    string fuglType;

public:
    void lesData() override {
        DyrILuft::lesData();
        cout << "Skriv inn type fugl: ";
        cin >> fuglType;
    }

    void skrivData() {
        DyrILuft::skrivData();
        cout << "Fugltype: " << fuglType << endl;
    }
};

class DyrIVann : public Dyr {
private:
    string vannArt;

public:
    void lesData() override {
        Dyr::lesData();
        cout << "Skriv inn vannarten for dyret: ";
        cin >> vannArt;
    }

    void skrivData() {
        Dyr::skrivData();
        cout << "Vannart: " << vannArt << endl;
    }
};

class Fisk : public DyrIVann {
private:
    string fiskType;

public:
    void lesData() override {
        DyrIVann::lesData();
        cout << "Skriv inn type fisk: ";
        cin >> fiskType;
    }

    void skrivData() {
        DyrIVann::skrivData();
        cout << "Fisketype: " << fiskType << endl;
    }
};

class Skalldyr : public DyrIVann {
private:
    string skalldyrType;

public:
    void lesData() override {
        DyrIVann::lesData();
        cout << "Skriv inn type skalldyr: ";
        cin >> skalldyrType;
    }

    void skrivData() {
        DyrIVann::skrivData();
        cout << "Skalldyrtype: " << skalldyrType << endl;
    }
};

int main() {
    char valg;

    do {
        cout << "Velg dyreart (I - Insekt, F - Fugl, S - Fisk, K - Skalldyr, Q - Avslutt): ";
        cin >> valg;

        Dyr *dyr;

        switch (valg) {
            case 'I':
                dyr = new Insekt();
                break;
            case 'F':
                dyr = new Fugl();
                break;
            case 'S':
                dyr = new Fisk();
                break;
            case 'K':
                dyr = new Skalldyr();
                break;
            case 'Q':
                cout << "Avslutter programmet." << endl;
                return 0;
            default:
                cout << "Ugyldig valg. Prøv igjen." << endl;
                continue;
        }

        dyr->skrivData();
        delete dyr;

    } while (true);

    return 0;
}
