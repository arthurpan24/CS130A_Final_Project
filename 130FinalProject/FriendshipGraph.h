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
#include <string>
#include <stdio.h>
#include <vector>

using namespace std;

class FriendshipGraph {
public:

    FriendshipGraph(int size); //The constructor will initialize the adjacencylist table
    
    int hash(std::string str, int seed); 
    void insert(string name, int indexOnDisk);
    void addFriend(std::string target, std::string friendsName, int friendsIndexOnDisk);
    int findPersonsHashValue(std::string str);
    vector<string> findFriendsNames(string target);
    vector<int> findFriendsIndexes(string target);
    
    class AdjacencyListNode {
    public:
        string name;
        int indexOnDisk;
        AdjacencyListNode* next;
        
        AdjacencyListNode(string name, int indexOnDisk) {
            this->name = name;
            this->indexOnDisk = indexOnDisk;
            this->next = NULL;
        }
    };
    
    int tableSize;
    AdjacencyListNode **table;
};

#endif /* FriendshipGraph_h */
