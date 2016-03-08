//
//  AdjacencyList.h
//  130FinalProject
//
//  Created by Arthur Pan on 3/7/16.
//  Copyright © 2016 JB Lanier. All rights reserved.
//

#ifndef AdjacencyList_h
#define AdjacencyList_h

#include "Person.h"
#include <stdio.h>

//This class is a table that contains people objects and also contains pointers to the memory stored on disk
class AdjacencyList {
public:
    AdjacencyList(int size);
    
private:
    struct Node {
        Person p; //should just be the name
        //PointerToDisk* ptr;
        Node *next;
    };
};

#endif /* AdjacencyList_h */
