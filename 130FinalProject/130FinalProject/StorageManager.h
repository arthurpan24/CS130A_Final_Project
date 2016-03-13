//
//  StorageManager.h
//  130FinalProject
//
//  Created by John Lanier on 3/10/16.
//  Copyright © 2016 JB Lanier. All rights reserved.
//

#ifndef StorageManager_h
#define StorageManager_h

#include <stdio.h>
#include <vector>
#include <string>

#include "Person.h"
#include "BTree.h"
#include "FriendshipGraph.h"

using namespace std;

class StorageManager {
    
public:
    static StorageManager* get();
    bool generateProfileDataFromInputFile(string path);
    bool generateFriendshipDataFromInputFile(string path);
    
    bool populateBTreeFromProfileData(string path, BTree* tree);
    bool populateFriendshipGraphFromData(string path, FriendshipGraph *graph, BTree* tree);
    
    Person getPersonAtIndex(int indexOnDisk);
private:
    StorageManager();
    vector<string> split(const string& str, const char& ch);
    int maxIndex;
  
};
#endif /* StorageManager_h */
