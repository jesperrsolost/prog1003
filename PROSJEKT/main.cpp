

/* KJØR PROGRAM:
cd "c:\Users\Admin\Documents\GitHub\prog1003\PROSJEKT\" ; if ($?) { g++ *.cpp -o main } ; if ($?) { .\main }
*/

/**
 *   Hovedprogrammet for OOP-prosjektet V24 med turoperatører, byer,
 *   attraksjoner i byene og N dagers ulike reiseopplegg for turoperatørene.
 *
 *   @file     MAINV24.CPP
 *   @author   Frode Haug, NTNU
 */


#include <iostream>
#include "turoperatorer.h"
#include "byer.h"
#include "opplegg.h"
#include "funksjoner.h"
#include "LesData3.h"
using namespace std;


//Turoperatorer gOperatorBase; ///<  Globalt container-objekt med ALLE turoperatørene.
Byer gByerBase;              ///<  Globalt container-objekt med ALLE byene.

//  Kode som legges innledningsvis i de .cpp-filene som trenger å bruke
//  en eller begge det to globale objektene definert ovenfor:
//         extern Turoperatorer gOperatorBase;
//         extern Byer gByerBase;


/**
 *  Hovedprogram.
 */
int main()  {
    char valg;


    //gOperatorBase.lesFraFil();
    gByerBase.lesFraFil();

    skrivMeny();
    valg = lesChar("\nKommando");

    while (valg != 'Q')  {
        switch(valg)  {
        //case 'T':               gOperatorBase.handling(valg);      break;
        case 'B':  case 'A':    gByerBase.handling(valg);          break;
        default:                skrivMeny();                       break;
        }
        valg = lesChar("\nKommando");
    }

    //gOperatorBase.skrivTilFil();
    gByerBase.skrivTilFil();

    cout << "\n\n";
    return 0;
}