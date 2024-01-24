/**
 *   L�sningsforslag til oppgave nr 2 (basert p� eksempel nr 17 i PROG1001).
 *
 *   @file    OPPG_02.CPP
 *   @author  Frode Haug, NTNU
 */


#include <iostream>          //  cout, cin
#include <iomanip>           //  setw
#include <cctype>            //  toupper
using namespace std;


const int MINTEMP   = -70;   ///<  Absolutt laveste mulige temperatur.
const int MAXTEMP   =  70;   ///<  Absolutt h�yeste mulige temperatur.
const int MAXNEDBOR = 200;   ///<  Absolutt h�yeste mulige nedb�r pr.d�gn.
const int MINDAGER  =  2;   ///<  Minimum antall dager i en m�ned.
const int MAXDAGER  =  31;   ///<  Maksimum antall dager i en m�ned.


/**
 *  Hovedprogrammet:
 */
int main ()  {
  char svar;                 //  Brukersvar til om vil fortsette eller ei.
  int  antDager,             //  Antall dager i aktuell m�ned.
       min,                  //  Min.temp EN gitt dag.
       max,                  //  Max.temp EN gitt dag.
       nedbor,               //  Nedb�r EN gitt dag.
       totMin,               //  TOTALT min.grader i aktuell m�ned.
       totMax,               //  TOTALT max.grader i aktuell m�ned.
       totNedbor,            //  TOTALT nedb�r i aktuell m�ned.
       mestNedbor,           //  Mest nedb�r falt p� en dag.
       nedborDag;            //  Dagnummeret med mest nedb�r.

  cout << "\nLese inn v�rdata for en m�ned (J/n): ";   //  Kj�re programmet?
  cin >> svar;   svar = toupper(svar);


  while (svar != 'N')  {     //  Enn� IKKE svart 'N':
     do {                    //  Leser antall dager i m�neden (28-31):
        cout << "Antall dager i m�neden ("
             << MINDAGER << '-' << MAXDAGER << "):  ";
        cin >> antDager;
     } while (antDager < MINDAGER  ||  antDager > MAXDAGER);

     totMin = totMax = totNedbor = 0;     //  M� huske � nullstille/
     mestNedbor = -1;    nedborDag = 0;   //    initiere variable!

     for (int i = 1;  i <= antDager;  i++)  { //  G�r gjennom HELE m�neden:
         cout << "\nDag nr." << setw(2) << i << ":\n";

         do {                             //  Leser korrekt min.temp dag nr.i:
             cout << "\tMinimumstemp (" << setw(2) << MINTEMP
                  << " til " << setw(2) << MAXTEMP << "):  ";
             cin >> min;
         } while(min < MINTEMP ||  min > MAXTEMP);
         totMin += min;                   //  Summerer totalen.

         do {                             //  Leser korrekt max.temp dag nr.i:
             cout << "\tMaksimumstemp (" << setw(2) << min
                  << " til " << setw(2) << MAXTEMP << "):  ";
             cin >> max;
         } while(max < min  ||  max > MAXTEMP);
         totMax += max;                   //  Summerer totalen.

         do {                             //  Leser korrekt nedb�r dag nr.i:
            cout << "\tNedb�r (0 til " << MAXNEDBOR << "): ";
            cin >> nedbor;
         } while(nedbor < 0  ||  nedbor > MAXNEDBOR);
         totNedbor += nedbor;             //  Summerer totalen.

         if (nedbor > mestNedbor) {       //  Ny nedb�rsrekord?
             mestNedbor = nedbor;         //  Lagrer unna rekorden,
             nedborDag = i;               //    og p� hvilken dag.
         }
     }

                                    //  Skriver gjennomsnitter og EN totalsum:
     cout << "\n\nGjennomsnittlig min.temp: "
          << static_cast <float> (totMin) / antDager << " grader C\n";
     cout << "Gjennomsnittlig max.temp: "
          << static_cast <float> (totMax) / antDager << " grader C\n";
     cout << "Gjennomsnittlig nedb�r:   "
          << static_cast <float> (totNedbor) / antDager << " mm\n";
     cout << "Total nedb�r i m�neden:   " << totNedbor <<  " mm\n";
     cout << "Det falt mest nedb�r p� dag nr."
          << nedborDag << " med " << mestNedbor << " mm\n";

                                             //  Kj�re programmet igjen?
     cout << "\nLese inn v�rdata for en m�ned til (J/n): ";
     cin >> svar;   svar = toupper(svar);
  }

  cout << "\n\n\nHa en fortsatt god (v�r(syk))dag!\n\n";

  return 0;
}