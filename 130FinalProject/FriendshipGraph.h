//
//  FriendshipGraph.h
//  130FinalProject
//
//  Created by Arthur Pan on 3/7/16.
//  Copyright © 2016 JB Lanier. All rights reserved.
//

//Note: This class will be used to implement both the hash function and the adjacency list
//The hash funciton will point the user to the correct node in the adjacency list
//The adjacency list will contain a lot of pointers to the actual data, stored on the disk

#ifndef FriendshipGraph_h
#define FriendshipGraph_h

#include "Person.h"
#include "AdjacencyList.h"
#include <string>
#include <stdio.h>

class FriendshipGraph {
public:
    FriendshipGraph(int size); //The constructor will initialize the adjacencylist table
    
    int hash(std::string str); //use linear hashing
    void insert(std::string str);
    void addFriend(std::string str);
    int findFriend(std::string str);
    int stringValue(std::string str);

    
private:
    int TABLE_SIZE;
    AdjacencyList *table;
};

#endif /* FriendshipGraph_h */
