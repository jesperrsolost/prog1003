/**
 * Oblig nummer 1
 * Ferdig: Nei
 * 
 * @file OBL01.cpp
 * @author Jesper Ruud Soløst
 * 
 * @date 30.01.2024
*/

using namespace std;

#include <iostream>
#include <iomanip>
#include <vector>
#include "LesData2.h"

void nyRestaurant();
void restaurantLesData(Restaurant & restaurant);
void restaurantSkrivData(const Restaurant* restaurant);
void skrivAlleRestauranter();
void skrivMeny();
void slettAlt();

struct Restaurant {
 string navn,
 adresse,                       // Gateadresse i en og samme by
 type,                          // Indisk, japansk, thai, italiensk, gresk, ....
 omtale;                        // Lengre evaluering/bekrivelse/vurdering
 int terningkast;               // Verdien 1 - 6
};

vector <Restaurant*> gRestauranter;

/**
 * Hovedprogrammet:
*/
int main(){

    return 0;
}

/**
 * 
*/
void nyRestaurant(){

}

/**
 * 
*/
void restaurantLesData(Restaurant & restaurant){

}

/**
 * 
*/
void restaurantSkrivData(const Restaurant* restaurant){

}

/**
 * 
*/
void skrivAlleRestauranter(){

}

/**
 * 
*/
void skrivMeny(){

}

/**
 * 
*/
void slettAlt(){

}