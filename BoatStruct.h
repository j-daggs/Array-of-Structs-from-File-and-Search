#ifndef BoatStruct_h
#define Boatstruct_h

#include <iostream>
#include <string>
#include <fstream>

const int MAX = 10;

struct BoatStruct {
    std::string boatOwnerName;
    std::string boatName;
    double boatSize;
    BoatStruct();
    BoatStruct(std::string oName, std::string boatName, double size);
    void print();
};

typedef BoatStruct BoatArray[MAX];

#endif