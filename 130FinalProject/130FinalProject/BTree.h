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
#include "BTreeItem.hpp"

using namespace::std;

class BTree {
    public:
    BTree();
    
    bool insert(string name, int indexOnDisk);
    
    int find(string name);
    int recursiveFindHelper(BTreeItem* node, string name);
    BTreeItem* root;

};

#endif /* BTree_h */
