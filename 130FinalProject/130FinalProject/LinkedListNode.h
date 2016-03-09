//
//  LinkedListNode.h
//  130FinalProject
//
//  Created by Arthur Pan on 3/8/16.
//  Copyright © 2016 JB Lanier. All rights reserved.
//

#ifndef LinkedListNode_h
#define LinkedListNode_h

#include <string>
#include <stdio.h>

class LinkedListNode {
public:
    LinkedListNode(std::string name);
    
    std::string name;
    LinkedListNode *next;
};

#endif /* LinkedListNode_h */
