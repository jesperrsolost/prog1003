/**
 *   L�sningsforslag til oppgave nr 3.
 *
 *   Modifisert utgave av l�sningen til oppgave nr 2: med bruk av funksjoner.
 *
 *   @file    OPPG_03.CPP
 *   @author  Frode Haug, NTNU
 */


#include <iostream>          //  cout, cin
#include <iomanip>           //  setw
using namespace std;


const int MINTEMP   = -70;   ///<  Absolutt laveste mulige temperatur.
const int MAXTEMP   =  70;   ///<  Absolutt h�yeste mulige temperatur.
const int MAXNEDBOR = 200;   ///<  Absolutt h�yeste mulige nedb�r pr.d�gn.
const int MINDAGER  =  2;   ///<  Minimum antall dager i en m�ned.
const int MAXDAGER  =  31;   ///<  Maksimum antall dager i en m�ned.


float gjennomsnitt(const int verdi1, const int verdi2);
int lesTall(const char t[], const int min, const int max);


/**
 *  Hovedprogrammet:
 */
int main ()  {
  int svar,                 //  Brukersvar til om vil fortsette eller ei.
      antDager,             //  Antall dager i aktuell m�ned.
      min,                  //  Min.temp EN gitt dag.
      nedbor,               //  Nedb�r EN gitt dag.
      totMin,               //  TOTALT min.grader i aktuell m�ned.
      totMax,               //  TOTALT max.grader i aktuell m�ned.
      totNedbor,            //  TOTALT nedb�r i aktuell m�ned.
      mestNedbor,           //  Mest nedb�r falt p� en dag.
      nedborDag;            //  Dagnummeret med mest nedb�r.

  svar = lesTall("\nLese inn v�rdata for en m�ned", 0, 1);   //  Kj�re programmet?

  while (svar == 1)  {       //  Enn� IKKE svart '0':
                             //  Leser antall dager i m�neden (28-31):
     antDager = lesTall("Antall dager i m�neden", MINDAGER, MAXDAGER);

     totMin = totMax = totNedbor = 0;     //  M� huske � nullstille/
     mestNedbor = -1;    nedborDag = 0;   //    initiere variable!

     for (int i = 1;  i <= antDager;  i++)  { //  G�r gjennom HELE m�neden:
         cout << "\nDag nr." << setw(2) << i << ":\n";
                                          //  Leser korrekt min.temp dag nr.i:
         min = lesTall("Minimumstemp", MINTEMP, MAXTEMP);
         totMin += min;                   //  Summerer totalen.
                                          //  Leser korrekt max.temp dag nr.i:
         totMax += lesTall("Maksimumstemp", min, MAXTEMP); //Summerer totalen.
                                          //  Leser korrekt nedb�r dag nr.i:
         nedbor = lesTall("Nedb�r", 0, MAXNEDBOR);
         totNedbor += nedbor;             //  Summerer totalen.

         if (nedbor > mestNedbor) {       //  Ny nedb�rsrekord?
             mestNedbor = nedbor;         //  Lagrer unna rekorden,
             nedborDag = i;               //    og p� hvilken dag.
         }
     }
                                    //  Skriver gjennomsnitter og EN totalsum:
     cout << "\n\nGjennomsnittlig min.temp: "
          << gjennomsnitt(totMin, antDager) << " grader C\n";
     cout << "Gjennomsnittlig max.temp: "
          << gjennomsnitt(totMax, antDager) << " grader C\n";
     cout << "Gjennomsnittlig nedb�r:   "
          << gjennomsnitt(totNedbor, antDager) << " mm\n";
     cout << "Total nedb�r i m�neden:   " << totNedbor <<  " mm\n";
     cout << "Det falt mest nedb�r p� dag nr."
          << nedborDag << " med " << mestNedbor << " mm\n";
                                             //  Kj�re programmet igjen?
     svar = lesTall("\nLese inn v�rdata for en m�ned til", 0, 1);
  }

  cout << "\n\n\nHa en fortsatt god (v�r(syk))dag!\n\n";

  return 0;
}


/**
 *  Funksjon som beregner float-gjennomsnittet av to int-verdier.
 *
 *  @param     verdi1  - int-verdien over br�kstreken
 *  @param     verdi2  - int-verdien under br�kstreken
 *  @return    float-verdien av   verdi1 / verdi2
 */
float gjennomsnitt(const int verdi1, const int verdi2) {
    return(static_cast <float> (verdi1) / verdi2);
}


/**
*  Leser og returnerer et heltall mellom to gitte grenser.
*
*  @param   t    - Ledetekst til brukeren n�r ber om input/et tall
*  @param   min  - Minimum for innlest og godtatt tallverdi
*  @param   max  - Maksimum for innlest og godtatt tallverdi
*  @return  Godtatt verdi i intervallet 'min' - 'max'
*/
int lesTall(const char t[], const int min, const int max)  {
    int tall;
    do {
       cout << t << " (" << min << " - " << max << "):  ";
       cin >> tall;
    } while (tall < min || tall > max);
    return tall;
}
