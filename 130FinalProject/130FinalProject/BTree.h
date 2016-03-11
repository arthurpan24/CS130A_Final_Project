//
//  BTree.h
//  130FinalProject
//
//  Created by Arthur Pan on 2/23/16.
//  Copyright © 2016 JB Lanier. All rights reserved.
//

//A B-tree (in memory) on the name attribute of the Profile File. The B-tree needs to support insert and range search queries (deletion is not required). Recall name is unique.

#ifndef BTree_h
#define BTree_h

#include <stdio.h>
#include <string>

using namespace::std;

class BTree {
    public:
    BTree(int MValue, int LValue);
    bool insert(string name, int indexOnDisk);
    
    private:
    int M;
    int L;
};

#endif /* BTree_h */
