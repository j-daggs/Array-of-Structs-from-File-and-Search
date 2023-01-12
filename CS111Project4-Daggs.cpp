// CS111Project4-Daggs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>

#include "BoatStruct.h"

//preconditions: --
//postconditions: writes content of array of Structs bounded by size in the following order: boatname, 
//                ownerName, size
void printBoatData(BoatArray boatData, int size);

//preconditions:  array of Structs has been initialized
//postconditions: Structs are filled with data from data.tx. 
//                File format is: owner name, boat size, boat name
 //               The parameter size is the number of lines in the file
//Notes: assumes a single string for owner name or boat name. Woods 320 Privacy is valid,
//       Tiger Woods 320 Privacy is not valid (line has three strings)
//       all file operations--opening, checking, reading, closing--must occur in readData(...)
//       It is possible that size may be one more than the number of data lines depending on
//       how the EOF character is represented.
void readData(BoatArray boatData, int& size);

//preconditions:  array of Structs has valid data
//postconditions: prints data associated with target (boat owner); 
//                if not found, print Owner target not found
void findDataByOwnerName(BoatArray boatData, int size, std::string target);

int main(void)
{
    BoatArray BoatData;
    int Size = 0;
    readData(BoatData, Size);
    std::cout << "Number of lines read: " << Size << std::endl;

      std::string target;
      if (!(!Size)) {
          std::cout << "Enter name of owner: ";
          std::cin >> target;
          findDataByOwnerName(BoatData, Size, target);
      }
      std::cout << std::endl;

    printBoatData(BoatData, Size);
    
}


void readData(BoatArray boatData, int& size) {
    std::ifstream inFile;

    inFile.open("Data.txt");
    if (inFile.fail()) {
        std::cout << "Couldnt open data file\n";
        return;
    }

    std::string name = " ";
    std::string boatName = " ";
    int boatSize = -1;

    while (inFile >> name && size < MAX) {
        inFile >> boatSize;
        inFile >> boatName;
        boatData[size].boatOwnerName = name;
        boatData[size].boatSize = boatSize;
        boatData[size].boatName = boatName;
        size++;
    }
    if (!inFile.eof() && size == MAX)
    {
        std::cout << "Some file contents may not have been read. \n";
    }
    inFile.close();
}

void findDataByOwnerName(BoatArray boatData, int size, std::string target) {
    for (int j = 0; j < size; j++)
    {
        if (boatData[j].boatOwnerName == target) {
            boatData[j].print();
            return;
        }

    }
    std::cout << "Owner's name not found in the array." << std::endl;
}

void printBoatData(BoatArray boatData, int size) {
    if (!size) {
        std::cout << "file was empty\n";
    }
    for (int i = 0; i < size; i++) {
        boatData[i].print();
    }
    std::cout << "\n";
}

