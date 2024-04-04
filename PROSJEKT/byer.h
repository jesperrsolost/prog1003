#ifndef __BYER_H
#define __BYER_H

#include <map>
#include <string>
#include "by.h"

class By;

class Byer {
    private:
    std::map<std::string, By*> byer;
    
    public:
    Byer();// Constructor
    ~Byer(); // Destructor
    void skrivAlleByer(); // "B A"
    void lesFraFil(); 
    void skrivTilFil();
    void handling(char vlg);
};

#endif