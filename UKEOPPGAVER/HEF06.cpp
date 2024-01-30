/**
 * Oppgave 6 i heftet
 * 
 * Ferdig: Ja
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
    
    cout << "Skriv ETT ord: ";
    cin >> tekst2;
    cin.ignore();

    cout << "Skriv flere ord: ";
    getline(cin, tekst5);
    cout << tekst5 << "\n\n";

    if (tekst4 == tekst5)      cout << "'tekst4' er lik 'tekst5'";
    else if (tekst4 < tekst5)  cout << "'tekst4' er storre enn 'tekst5'";
    else                       cout << "'tekst4' er ikke storre enn 'tekst5'";
    
    if (tekst3 == "Storhamar") cout << "'tekst3 er lik 'Storhamar'\n\n";
    if (tekst1 != tekst)       cout << "'tekst1 er ikke lik 'tekst'";

    tekst5 = tekst1 + " PLUSS " + tekst2 + " OG ENDA " + tekst4 + 'X';
    cout << tekst5 << "\n\n";

    tekst4 += ".......";
    tekst4 += tekst5;
    cout << tekst4 << "\n\n";

    cout << "'tekst5' sin size er   : " << tekst5.size() << "\n\n"
         << "'tekst5' sin lengde er :"  << tekst5.length() << "\n\n";

    return 0;
}