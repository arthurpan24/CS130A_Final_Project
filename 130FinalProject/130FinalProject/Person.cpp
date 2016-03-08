//
//  Person.cpp
//  130FinalProject
//
//  Created by Arthur Pan on 2/23/16.
//  Copyright © 2016 JB Lanier. All rights reserved.
//

#include "Person.h"

//Constructors
Person::Person()
{
    this->name = "";
    this->age = -1;
    this->occupation = "";
}

Person::Person(std::string name, int age, std::string occupation)
{
    this->name = name;
    this->age = age;
    this->occupation = occupation;
}


//Getters
std::string Person::getName()
{
    return this->name;
}
int Person::getAge()
{
    return this->age;
}
std::string Person::getOccupation()
{
    return this->occupation;
}


//Setters
void Person::setName(std::string name)
{
    this->name = name;
    return;
}
void Person::setAge(int age)
{
    this->age = age;
    return;
}
void Person::setOccupation(std::string occupation)
{
    this->occupation = occupation;
    return;
}

