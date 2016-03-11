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


Person::Person(string name, int age, string occupation)
{
    this->name = name;
    this->age = age;
    this->occupation = occupation;
}

