/**
 * Oppgave 2 i heftet
 * Ferdig: Nei
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
const int MINDAGER  =   5;   ///<  Minimum antall dager i en måned.
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
       totNedbor;            //  TOTALT nedbør i aktuell måned.
  int  alleMin[MAXDAGER],    //  ALLE min.temper i måneden.
       alleMax[MAXDAGER],    //  ALLE max.temper i måneden.
       alleNedbor[MAXDAGER]; //  ALL nedbør i måneden.

  cout << "\nLese inn vaerdata for en måned (J/n): ";  //  Kjøre programmet?
  cin >> svar;

  while (svar != 'N'  &&  svar != 'n') { //  Så lenge ønsker (IKKE svart 'N'):
     do {                    //  Leser antall dager i måneden (28-31):
        cout << "Antall dager i maaneden (" << MINDAGER << '-' << MAXDAGER << "): ";
        cin >> antDager;
     } while (antDager < MINDAGER  ||  antDager > MAXDAGER);

     for (int i = 0;  i < antDager;  i++)  { //  Går gjennom HELE måneden:
         cout << "\nDag nr." << i+1 << ": ";

         do {                             //  Leser korrekt min.temp dag nr.i:
           cout << "\tMinimumstemp (" << MINTEMP << " til " << MAXTEMP << "): ";
           cin >> min;
         } while(min < MINTEMP ||  min > MAXTEMP);
         alleMin[i] = min;                //  Lagrer unna innlest verdi.

         do {                             //  Leser korrekt max.temp dag nr.i:
            cout << "\tMaksimumstemp (" << min << " til " << MAXTEMP << "): ";
            cin >> max;
         } while(max < min  ||  max > MAXTEMP);
         alleMax[i] = max;                //  Lagrer unna innlest verdi.

         do {                             //  Leser korrekt nedbør dag nr.i:
            cout << "\tNedbor (0 til " << MAXNEDBOR << "): ";
            cin >> nedbor;
         } while(nedbor < 0  ||  nedbor > MAXNEDBOR);
         alleNedbor[i] = nedbor;          //  Lagrer unna innlest verdi.
     }

 	 totMin = totMax = totNedbor = 0;          //  Nullstiller totalsummer.
     for (int i = 0;  i < antDager;  i++)  { //  Går gjennom HELE måneden:
         totMin    += alleMin[i];            //  Oppsummerer tot.min.
         totMax    += alleMax[i];            //  Oppsummerer tot.max.
         totNedbor += alleNedbor[i];         //  Oppsummerer tot.nedbør.
     }
                                    //  Skriver gjennomsnitter og EN totalsum:
     // printf("\n\nGjennomsnittlig min.temp: %.2f grader C\n",
                                                     // (float)totMin/antDager);
  // printf("Gjennomsnittlig max.temp: %.2f grader C\n",(float)totMax/antDager);
  //   printf("Gjennomsnittlig nedbør:   %.2f mm\n", (float)totNedbor/antDager);
  //   printf("Total nedbør i måneden:   %i mm\n", totNedbor);
     cout << "\t\nGjennomsnittlig min.temp: " << static_cast <float> (totMin)/antDager << " grader C\n"
          << "Gjennomsnittlig max.temp: " << static_cast <float> (totMax)/antDager << " grader C\n"
          << "Gjennnomsnittlig nedbor: " << static_cast <float> (totNedbor)/antDager << " mm\n"
          << "Total nedbor i maaneden: " << totNedbor << " mm\n";
                                             //  Kjøre programmet igjen?
     cout << "\nLese inn vaerdata for en maaned til (J/n): ";
    // printf("\nLese inn værdata for en måned til (J/n): ");
    cin >> svar;
    // scanf(" %c", &svar);
  }
  cout << "\n\nHa en fortsatt god (vaer(syk))dag!\n\n";
  // printf("\n\n\nHa en fortsatt god (vær(syk))dag!\n\n");

  return 0;
}