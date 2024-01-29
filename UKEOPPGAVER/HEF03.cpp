/**
 * Oppgave 3 i heftet
 * Ferdig: Ja
 * 
 * @file HEF03.cpp
 * @author Jesper Ruud Soløst
 * 
 * @date 29.01.2024
*/
#include <iostream>                //  cout, cin
#include <iomanip>                 //  setw
#include <cstring>                 //  strcpy
#include "LesData2.h"              //  Verktøykasse for lesing av diverse data

using namespace std;

const int MINTEMP   = -70;   ///<  Absolutt laveste mulige temperatur.
const int MAXTEMP   =  70;   ///<  Absolutt h�yeste mulige temperatur.
const int MAXNEDBOR = 200;   ///<  Absolutt h�yeste mulige nedb�r pr.d�gn.
const int MINDAGER  =  2;   ///<  Minimum antall dager i en m�ned.
const int MAXDAGER  =  31;   ///<  Maksimum antall dager i en m�ned.

int lesTall(const char t[], const int min, const int max);
float gjennomsnitt(const int verdi1, const int verdi2);

/**
 *  Hovedprogrammet:
 */
int main ()  {
  int  svar,                 //  Brukersvar til om vil fortsette eller ei.
       antDager,             //  Antall dager i aktuell måned.
       min,                  //  Min.temp EN gitt dag.
       max,                  //  Max.temp EN gitt dag.
       nedbor,               //  Nedbør EN gitt dag.
       totMin,               //  TOTALT min.grader i aktuell måned.
       totMax,               //  TOTALT max.grader i aktuell måned.
       totNedbor,            //  TOTALT nedbør i aktuell måned.
       mestNedbor,           //  Mest nedbør falt på en dag.
       nedborDag;            //  Dagnummeret med mest nedbør.


  svar = lesTall("\nLese inn vaerdata for en maaned?", 0, 1); // Kjøre program?


  while (svar == 1)  {              //  Når ja
     do {                           //  Leser antall dager i m�neden (28-31):
        antDager = lesTall("Antall dager i maaneden", MINDAGER, MAXDAGER);
     } while (antDager < MINDAGER  ||  antDager > MAXDAGER);

     totMin = totMax = totNedbor = 0;     //  Må huske å nullstille/
     mestNedbor = -1;    nedborDag = 0;   //    initiere variable!

     for (int i = 1;  i <= antDager;  i++)  { //  Går gjennom HELE måneden:
         cout << "\nDag nr." << setw(2) << i << ":\n";

         do {                             //  Leser korrekt min.temp dag nr.i:
            min = lesTall("\tMinimumstemp", MINTEMP, MAXTEMP);
         } while(min < MINTEMP ||  min > MAXTEMP);
         totMin += min;                   //  Summerer totalen.

         do {                             //  Leser korrekt max.temp dag nr.i:
             //cout << "\tMaksimumstemp (" << setw(2) << min
             //     << " til " << setw(2) << MAXTEMP << "):  ";
             //cin >> max;
             max = lesTall("\tMaksimumstemp ", MINTEMP, MAXTEMP);
         } while(max < min  ||  max > MAXTEMP);
         totMax += max;                   //  Summerer totalen.

         do {                             //  Leser korrekt nedbør dag nr.i:
            //cout << "\tNedb�r (0 til " << MAXNEDBOR << "): ";
            //cin >> nedbor;
            nedbor = lesTall("\tNedbor ", 0, MAXNEDBOR);
         } while(nedbor < 0  ||  nedbor > MAXNEDBOR);
         totNedbor += nedbor;             //  Summerer totalen.

         if (nedbor > mestNedbor) {       //  Ny nedbørsrekord?
             mestNedbor = nedbor;         //  Lagrer unna rekorden,
             nedborDag = i;               //    og på hvilken dag.
         }
     }

                                    //  Skriver gjennomsnitter og EN totalsum:
     cout << "\n\nGjennomsnittlig min.temp: " 
          << gjennomsnitt(totMin, antDager) << " grader C\n";
     cout << "Gjennomsnittlig max.temp: "
          << gjennomsnitt(totMax, antDager) << " grader C\n";
     cout << "Gjennomsnittlig nedbor: "
          << gjennomsnitt(totNedbor, antDager) << " mm\n";
     cout << "Total nedb�r i m�neden:   " << totNedbor <<  " mm\n";
     cout << "Det falt mest nedb�r p� dag nr."
          << nedborDag << " med " << mestNedbor << " mm\n";

                                             //  Kjøre programmet igjen?
     svar = lesTall("\nLese inn vaerdata for en ny maaned?", 0, 1);
  }

  cout << "\n\n\nHa en fortsatt god (vaer(syk))dag!\n\n";

  return 0;
}

/**
 * Funksjon som leser inn tall
 * @param t Ledetekst
 * @param min minste aksepterte verdi
 * @param max maksimale aksepterte verdi
*/
int lesTall(const char t[], const int min, const int max){
    int tall;
    do{
        cout << t << "(" << min << "-" << max << "): ";
        cin >> tall;
    } while (tall < min || tall > max);
    return tall;
}

/**
 * Funksjon som regner gjennomsnitt
 * @param verdi1 første verdien 
 * @param verdi2 andre verdien
 * @return Float gjennomsnittet av de to verdiene
*/
float gjennomsnitt(const int verdi1, const int verdi2){
    return static_cast <float> (verdi1 / verdi2);
}