/**
 * Oppgave 6 i heftet
 * 
 * Ferdig: Nei
 * 
 * @file HEF06.cpp
 * @author Jesper Ruud Soløst
 * 
 * @date 30.01.2024
*/

#include <iostream>                         // cout, cin
#include <string>                           // string
using namespace std;

/**
 * Hovedprogrammet:
*/
int main(){
    char tekst[]  = "Dette er en tekst";
    string tekst1 = "Dette er tekst nr.1";
    string tekst2("Dette er tekst nr.2");
    string tekst3(tekst);
    string tekst4(tekst1);
    string tekst5(10, '*');

    cout << "tekst  = -" << tekst << "-\n"
         << "tekst1 = -" << tekst1 << "-\n"
         << "tekst2 = -" << tekst2 << "-\n"
         << "tekst3 = -" << tekst3 << "-\n"
         << "tekst4 = -" << tekst4 << "-\n"
         << "tekst5 = -" << tekst5 << "-\n\n"; 

    tekst3 = "Dette er en ny tekst...";
    tekst4 = tekst5;

    cout << "tekst3 = -" << tekst3 << "-\n"
         << "tekst4 = -" << tekst4 << "-\n\n";
    return 0;
}