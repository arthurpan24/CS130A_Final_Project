//
//  Person.cpp
//  130FinalProject
//
//  Created by Arthur Pan on 2/23/16.
//  Copyright © 2016 JB Lanier. All rights reserved.
//

#include "Person.h"
#include <iostream>
#include <fstream>
using namespace std;

void Person::addPersonToProfileData(std::string name, int age, std::string occupation)
{
    ofstream outputFile;
    outputFile.open("ProfileData.txt");
    
    string helloWorld = "hello world";
    outputFile << helloWorld;
    
    outputFile.close();
    return;
}

