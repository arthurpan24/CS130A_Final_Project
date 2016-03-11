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
#include "Person.h"

using namespace std;

class StorageManager {
    
public:
    static StorageManager* get();
    bool generateProfileDataFromInputFile(string path);
    
    bool generateFriendshipDataFromInputFile(string path);
    
private:
    vector<string> split(string str, char delimiter);
  
};
#endif /* StorageManager_h */
