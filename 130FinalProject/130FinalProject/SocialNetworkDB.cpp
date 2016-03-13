//
//  SocialNetworkDB.cpp
//  130FinalProject
//
//  Created by John Lanier on 3/10/16.
//  Copyright © 2016 JB Lanier. All rights reserved.
//

#include <string>
#include <iostream>

#include "SocialNetworkDB.h"

SocialNetworkDB::SocialNetworkDB() {
    
    // Initialize a quick reference pointer to the Storage Manager
    SM = StorageManager::get();
    
    // Create Data Stuctures
    graph = new FriendshipGraph(211);
    tree = new BTree();
    
}

void SocialNetworkDB::initializeFromInputData(string path) {
    if (path == "") {
        // Set default value of path if empty string is given
        path = "Generated1.txt";
    }
    
    SM->generateProfileDataFromInputFile(path);
    //contruct b-tree
    SM->generateBTreeFromProfileData("ProfileData.txt", tree);
    //contruct friendship graph
    //SM->generateFriendshipDataFromInputFile(path);
    vector<int> p = tree->findRange("A", "B");
    for (int i = 0; i < p.size(); i++) {
        cout << SM->getPersonAtIndex(p.at(i)).ToString() << endl;
    }
    
}

void SocialNetworkDB::initializeFromSavedData(string path) {
    if (path == "") {
        // Set default value of path if empty string is given
        path = "Generated1.txt";
    }
    
    //contruct b-tree
    //contruct friendship graph
    
}

