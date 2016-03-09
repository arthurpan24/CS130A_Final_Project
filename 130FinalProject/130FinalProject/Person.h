//
//  Person.h
//  130FinalProject
//
//  Created by Arthur Pan on 2/23/16.
//  Copyright © 2016 JB Lanier. All rights reserved.
//

#ifndef Person_h
#define Person_h

#include <stdio.h>
#include <string>


//TURNS OUT that this class will only be used to write to the Profile Data text file
class Person {
public:
    void addPersonToProfileData(std::string name, int age, std::string occupation);
};

#endif /* Person_h */
