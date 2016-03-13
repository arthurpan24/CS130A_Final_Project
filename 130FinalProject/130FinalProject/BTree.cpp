//
//  BTree.cpp
//  130FinalProject
//
//  Created by Arthur Pan on 2/23/16.
//  Copyright © 2016 JB Lanier. All rights reserved.
//

#include <iostream>

#include "BTree.h"
#include "BTreeLeafNode.hpp"
#include "BTreeDataItem.hpp"

using namespace std;

BTree::BTree() {
    this->root = new BTreeLeafNode();
}

bool BTree::insert(string name, int indexOnDisk) {
    root->insert(new BTreeDataItem(name, indexOnDisk));
    if (root->parent != NULL) {
        root = root->parent;
    }
    cout << "/////////////////////////////////////////////////////////////////////////////////////////" << endl;
    std::cout << "----------------" << name << ", " << indexOnDisk << " INSERTED!" << "----------------" << std::endl;
    cout << "/////////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "COTENTS OF NEW TREE: " << endl;
    root->printNode();
    cout << "/////////////////////////////////////////////////////////////////////////////////////////" << endl;
    return true;
}
