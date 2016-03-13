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
    SM->generateFriendshipDataFromInputFile(path);
    
    initializeFromSavedData(path);
}

void SocialNetworkDB::initializeFromSavedData(string path) {
    if (path == "") {
        // Set default value of path if empty string is given
        path = "Generated1.txt";
    }
    
    SM->populateBTreeFromProfileData("ProfileData.txt", tree);
    SM->populateFriendshipGraphFromData("FriendshipData.txt", graph, tree);
    
    vector<int> x = graph->findFriendsIndexes("Wyatt");
    for (int i = 0; i < x.size(); i++) {
        cout << x.at(i) << ", ";
    }
    cout << endl;
}

