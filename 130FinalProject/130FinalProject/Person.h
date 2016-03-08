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


//TURNS OUT that this class will only be used to 
class Person {
public:
    Person(std::string name, int age, std::string occupation);
    Person();
    //Implementation decision: I have decided to use getters and setters
    //                         instead of keeping the variables public
    
    //Getters
    std::string getName();
    int getAge();
    std::string getOccupation();
    
    //Setters
    void setName(std::string name);
    void setAge(int age);
    void setOccupation(std::string occupation);
    
private:
    std::string name;
    int age;
    std::string occupation;
};

#endif /* Person_h */
