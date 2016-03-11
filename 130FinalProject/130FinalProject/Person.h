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

using namespace std;

class Person {
public:
    string name;
    int age;
    string occupation;
    
    int indexOnDisk;
    
    bool saveToDisk;
    string ToString();
    
    Person(string name, int age, string occupation);
   
};

#endif /* Person_h */
