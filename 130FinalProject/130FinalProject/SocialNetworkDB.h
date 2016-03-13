//
//  SocialNetworkDB.h
//  130FinalProject
//
//  Created by John Lanier on 3/10/16.
//  Copyright © 2016 JB Lanier. All rights reserved.
//

#ifndef SocialNetworkDB_h
#define SocialNetworkDB_h

#include <stdio.h>
#include <string.h>

#include "StorageManager.h"
#include "FriendshipGraph.h"
#include "BTree.h"

using namespace std;

class SocialNetworkDB {
    
public:
    SocialNetworkDB();
    
    void initializeFromInputData(string path);
    void initializeFromSavedData(string path);
    
    StorageManager* SM;
    
    // Queries
    void printInfoOfFriends(string target);
    void printAll();
    void printRange(string lowerBound, string upperBound);
    void addPerson(string name, int age, string occupation);
    void addFriendship(string target, string newFriend);
    void printInfo(string name);
    void displayTree();
    
    
    
    FriendshipGraph* graph;
    BTree* tree;
};

#endif /* SocialNetworkDB_h */
