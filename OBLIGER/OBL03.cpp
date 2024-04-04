/** 
 *   Obligatorisk oppgave 3
 *
 *   Programmet inneholder en oversikt over studenter og ansatt p� en skole.
 *   Disse er identifisert via sitt UNIKE student-/ansattnummer,
 *   og alle ligger lagret i EN <map>. Brukeren/programmet kan:
 *       - se ALLE personene som er lagret i datastrukturen (map'en)
 *       - legge inn en ny student/ansatt
 *       - endre data om en gitt student/ansatt
 *       - HELE datastrukturen leses fra/skrives til fil
 *
 *   @file    OBL03.cpp
 *   @author  Jesper Ruud Soløst
 * 
 *   @date 11.03.2024
 */


#include <iostream>                //  cout, cin
#include <fstream>                 //  ifstream, ofstream
#include <string>
#include <map>
#include "LesData2.h"              //  Verkt�ykasse for lesing av diverse data
using namespace std;


/**
 *  Person (med navn).
 */
class Person {
  private:
      string navn;
  public:
      Person()  {  navn = "";  }
      Person(ifstream & inn);
      virtual void endreData() = 0;
      virtual void lesData();
      virtual void skrivData() const;
      virtual void skrivTilFil(ofstream & ut) const;
};


/**
 *  Student (med studieprogram/klasse og antall studiepoeng).
 */
class Student : public Person {
  private:
      string studieprogram;
      float  stp;
  public:
      Student()  {  studieprogram = "";  stp = 0.0F;  }
      Student(ifstream & inn);
      virtual void endreData();
      virtual void lesData();
      virtual void skrivData() const;
      virtual void skrivTilFil(ofstream & ut) const;
};


/**
 *  Ansatt (med rom-/kontornummer og �rsl�nn).
 */
class Ansatt : public Person {
  private:
      string rom;
      int    lonn;
  public:
      Ansatt()  {  rom = "";  lonn = 0;  }
      Ansatt(ifstream & inn);
      virtual void endreData();
      virtual void lesData();
      virtual void skrivData() const;
      virtual void skrivTilFil(ofstream & ut) const;
};


void endreEnPerson();
void lesFraFil();
void nyPerson();
void skrivAllePersoner();
void skrivMeny();
void skrivTilFil();


map <int, Person*> gPersoner;      ///<  Datastrukturen med alle personene.


/**
 *  Hovedprogrammet:
 */
int main(void)  {
    char kommando;

    lesFraFil();

    skrivMeny();
    kommando = lesChar("Kommando");

    while (kommando != 'Q') {
        switch (kommando) {
          case 'N':  nyPerson();               break;
          case 'A':  skrivAllePersoner();      break;
          case 'E':  endreEnPerson();          break;
          default:   skrivMeny();              break;
        }
        kommando = lesChar("Kommando");
    }

    skrivTilFil();

   return 0;
}


// ---------------------------------------------------------------------------
//                       DEFINISJON AV KLASSE-FUNKSJONER:
// ---------------------------------------------------------------------------

/**
 *  Leser navnet fra fil.
 *
 *  @param   inn  - Filobjektet egne data leses inn fra
 */
Person::Person(ifstream & inn) {
    //  LAG INNMATEN
}


/**
 *  Leser navnet fra brukeren/tastaturet.
 */
void Person::lesData() {
    //  LAG INNMATEN
}


/**
 *  Skriver ut navnet til/p� skjermen. 
 */
void Person::skrivData() const {
    //  LAG INNMATEN
}


/**
 *  Skriver ut navnet til fil.
 *
 *  @param   ut  - Filobjektet egne data skrives ut til
 */
void Person::skrivTilFil(ofstream & ut) const {
    //  LAG INNMATEN
}


// ---------------------------------------------------------------------------

/**
 *  Leser studiepoeng og studieprogram/klasse fra fil.
 *
 *  @param   inn  - Filobjektet egne data leses inn fra
 */
Student::Student(ifstream & inn) : Person(inn) {
    //  LAG INNMATEN
}


/**
 *  Tilbyr brukren � endre p� alle egne data.
 *
 *  @see  skrivData()
 */
void Student::endreData() {
    //  LAG INNMATEN
}


/**
 *  Leser baseklassens data, studieproram/klasse og studiepoeng fra brukeren.
 *
 *  @see   Person::lesData()
 */
void Student::lesData() {
    //  LAG INNMATEN
}


/**
 *  Skriver baseklassens data, studieproram/klasse og studiepoeng til skjerm.
 *
 *  @see  Person::skrivData()
 */
void Student::skrivData() const {
    //  LAG INNMATEN
}


/**
 *  Skriver 'S', baseklassens data, studiepoeng og studieprogram til fil.
 *
 *  @param   ut  - Filobjektet egne data skrives ut til
 *  @see     Person::skrivTilTil(...)
 */
void Student::skrivTilFil(ofstream & ut) const {
    //  LAG INNMATEN
}


// ---------------------------------------------------------------------------

/**
 *  Leser �rsl�nn og rom/kontor fra fil. 
 *
 *  @param   inn  - Filobjektet egne data leses inn fra
 */
Ansatt::Ansatt(ifstream & inn) : Person(inn) {
    //  LAG INNMATEN
}


/**
 *  Tilbyr brukren � endre p� alle egne data.
 *
 *  @see  skrivData()
 */
void Ansatt::endreData() {
    //  LAG INNMATEN
}


/**
 *  Leser baseklassens data, rom/kontor og �rsl�nn fra brukeren.
 *
 *  @see   Person::lesData()
 */
void Ansatt::lesData() {
    //  LAG INNMATEN
}


/**
 *  Skriver baseklassens data, rom/kontor og �rsl�nn til/p� skjermen.
 *
 *  @see  Person::skrivData()
 */
void Ansatt::skrivData() const {
    //  LAG INNMATEN
}


/**
 *  Skriver 'A', baseklassens data, �rsl�nn og rom/kontor.
 *
 *  @param   ut  - Filobjektet egne data skrives ut til
 *  @see     Person::skrivTilTil(...)
 */
void Ansatt::skrivTilFil(ofstream & ut) const {
    //  LAG INNMATEN
}


// ---------------------------------------------------------------------------
//                       DEFINISJON AV ANDRE FUNKSJONER:
// ---------------------------------------------------------------------------

/**
 *  Lar brukeren (om mulig) endre dataene for et avledet objekt (subklasse).
 *
 *  @see   virtual Person::endreData()
 */
void endreEnPerson() {
    //  LAG INNMATEN
}


/**
 *  Leser ALLE personer inn fra fil, og legger de inn i 'gPersoner'.
 */
void lesFraFil() {
    ifstream Innfil;
    Innfil.open("OBL03.dta");
    
}


/**
 *  Legger inn (om mulig) en ny person.
 *
 *  @see   virtual Person::lesData()
 */
void nyPerson() {
    //  LAG INNMATEN
}


/**
 *  Skriver alle dataene om alle personene ut p� skjermen.
 *
 *  @see   virtual Person::skrivData()
 */
void skrivAllePersoner() {
    //  LAG INNMATEN
}


/**
 *  Skriver programmets menyvalg/muligheter p� skjermen.
 */
void skrivMeny() {
    cout << "\nF�lgende kommandoer er tilgjengelig:\n"
         << "\tN - Ny person (student eller ansatt)\n"
         << "\tA - skriv Alle personer\n"
         << "\tE - Endre EN gitt person\n"
         << "\tQ - Quit / avslutt\n\n";
}


/**
 *  Skriver hele datastrukturen til fil.
 *
 *  @see   virtual Person::skrivTilFil(...)
 */
void skrivTilFil() {
    //  LAG INNMATEN
}