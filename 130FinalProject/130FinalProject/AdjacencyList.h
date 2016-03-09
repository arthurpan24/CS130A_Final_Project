//
//  AdjacencyList.h
//  130FinalProject
//
//  Created by Arthur Pan on 3/7/16.
//  Copyright © 2016 JB Lanier. All rights reserved.
//

#ifndef AdjacencyList_h
#define AdjacencyList_h

#include "LinkedListNode.h"
#include "Person.h"
#include <stdio.h>

//This class is a table that contains people objects and also contains pointers to the memory stored on disk
class AdjacencyList {
public:
    AdjacencyList();
    
    std::string name;
    bool empty;
    LinkedListNode* head;
    LinkedListNode* tail;
};

#endif /* AdjacencyList_h */
