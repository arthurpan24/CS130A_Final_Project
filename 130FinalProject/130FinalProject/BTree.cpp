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
#include "BTreeInternalNode.hpp"
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

int BTree::find(string name) {
    return -1;
}

int BTree::recursiveFindHelper(BTreeItem* node, string name) {
    
    // Case: Node in question is a data item (at the tip of a leave node)
    BTreeDataItem* d = dynamic_cast<BTreeDataItem*>(node);
    if (d != NULL) {
        return d->indexOnDisk;
    }
    
    // CASE: Node in question is a internal node
    BTreeInternalNode* e = dynamic_cast<BTreeInternalNode*>(node);
    if (e != NULL) {
        cout << "DYNAMIC CAST TO INTERNAL NODE WORKED";
        for (int i = 0; i < e->children.size(); i++) {
            if (i == 0 && (name.compare(e->keys.at(0)) < 0)) {
                return recursiveFindHelper(e->children.at(0), name);
            }
            if (i >= e->children.size()-1) {
                return recursiveFindHelper(e->children.at(e->children.size()-1), name);
            }
            if ((name.compare(e->keys.at(i)) < 0) && (name.compare(e->keys.at(i-1)) > 0) ) {
                return recursiveFindHelper(e->children.at(i), name);
            }
        }
        
    }
    
    //Case: Node is a leaf node
    for (int i = 0; i < node->children.size(); i++) {
        if (name == node->children.at(i)->key) {
            return recursiveFindHelper(node->children.at(i), name);
        }
    }
    
    return -1;
}