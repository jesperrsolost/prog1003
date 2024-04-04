#include <iostream>
#include "by.h"

using namespace std;

/**
 * Parameterløs constructor
*/
By::By(){  }

/**
 * Destructor
*/
By::~By(){  }

/**
 * Funksjon som skriver tilhørende land og antall attraksjoner
*/
void By::skrivAlle(){
    cout << land << attraksjoner.size() << " attraksjoner.";
}