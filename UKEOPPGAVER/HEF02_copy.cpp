/**
 * Oppgave 2 i heftet
 * Ferdig: Delvis
 * 
 * @file HEF02.cpp
 * @author Jesper Ruud Soløst
 * 
 * @date 16.01.2024
*/
#include <cstdio>           //  printf, scanf
#include <iomanip>
#include <iostream>

using namespace std;

const int MINTEMP   = -70;   ///<  Absolutt laveste mulige temperatur.
const int MAXTEMP   =  70;   ///<  Absolutt høyeste mulige temperatur.
const int MAXNEDBOR = 200;   ///<  Absolutt høyeste mulige nedbør pr.døgn.
const int MINDAGER  =   2;   ///<  Minimum antall dager i en måned.
const int MAXDAGER  =  31;   ///<  Maksimum antall dager i en måned.

/**
 *  Hovedprogrammet:
 */
int main ()  {
  char svar;                 //  Brukersvar til om vil fortsette eller ei.
  int  antDager,             //  Antall dager i aktuell måned.
       min,                  //  Min.temp EN gitt dag.
       max,                  //  Max.temp EN gitt dag.
       nedbor,               //  Nedbør EN gitt dag.
       totMin,               //  TOTALT min.grader i aktuell måned.
       totMax,               //  TOTALT max.grader i aktuell måned.
       totNedbor,            //  TOTALT nedbør i aktuell måned.
       mestNedbor,           //  REKORD nedbør
       nedborDag;
//  int  alleMin[MAXDAGER],    //  ALLE min.temper i måneden.
//       alleMax[MAXDAGER],    //  ALLE max.temper i måneden.
//       alleNedbor[MAXDAGER]; //  ALL nedbør i måneden.

  cout << "\nLese inn vaerdata for en måned (J/n): ";  //  Kjøre programmet?
  cin >> svar;

  while (svar != 'N'  &&  svar != 'n') { //  Så lenge ønsker (IKKE svart 'N'):
     do {                    //  Leser antall dager i måneden (28-31):
        cout << "Antall dager i maaneden (" << MINDAGER << '-' << MAXDAGER << "): ";
        cin >> antDager;
     } while (antDager < MINDAGER  ||  antDager > MAXDAGER);

     for (int i = 0;  i < antDager;  i++)  { //  Går gjennom HELE måneden:
         cout << "\nDag nr." << i+1 << ": \n";

         do {                             //  Leser korrekt min.temp dag nr.i:
           cout << "\tMinimumstemp (" << MINTEMP << " til " << MAXTEMP << "): ";
           cin >> min;
         } while(min < MINTEMP ||  min > MAXTEMP);
         totMin += min;                //  Lagrer unna innlest verdi.

         do {                             //  Leser korrekt max.temp dag nr.i:
            cout << "\tMaksimumstemp (" << min << " til " << MAXTEMP << "): ";
            cin >> max;
         } while(max < min  ||  max > MAXTEMP);
         totMax += max;                //  Lagrer unna innlest verdi.

         do {                             //  Leser korrekt nedbør dag nr.i:
            cout << "\tNedbor (0 til " << MAXNEDBOR << "): ";
            cin >> nedbor;
         } while(nedbor < 0  ||  nedbor > MAXNEDBOR);
         totNedbor += nedbor;          //  Lagrer unna innlest verdi.

         if (nedbor > mestNedbor){     //  Rekord måned?
            mestNedbor = nedbor;
         }
     }

 	 // totMin = totMax = totNedbor = 0;          //  Nullstiller totalsummer.
    // for (int i = 0;  i < antDager;  i++)  { //  Går gjennom HELE måneden:
    //     totMin    += alleMin[i];            //  Oppsummerer tot.min.
    //     totMax    += alleMax[i];            //  Oppsummerer tot.max.
    //     totNedbor += alleNedbor[i];         //  Oppsummerer tot.nedbør.
    // }
                                    //  Skriver gjennomsnitter og EN totalsum:
    cout << "\t\nGjennomsnittlig min.temp: " << static_cast <float> (totMin)/antDager << " grader C\n"
          << "Gjennomsnittlig max.temp: " << static_cast <float> (totMax)/antDager << " grader C\n"
          << "Gjennnomsnittlig nedbor: " << static_cast <float> (totNedbor)/antDager << " mm\n"
          << "Total nedbor i maaneden: " << totNedbor << " mm\n";
                                             //  Kjøre programmet igjen?
    cout << "\nLese inn vaerdata for en maaned til (J/n): ";
    cin >> svar;
  }
  cout << "\n\nHa en fortsatt god (vaer(syk))dag!\n\n";
  return 0;
}