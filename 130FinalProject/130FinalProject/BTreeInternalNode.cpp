//
//  BTreeInternalNode.cpp
//  130FinalProject
//
//  Created by John Lanier on 3/12/16.
//  Copyright © 2016 JB Lanier. All rights reserved.
//

#include "BTreeInternalNode.hpp"
#include <iostream>
#include "BTreeItem.hpp"

using namespace std;

BTreeInternalNode::BTreeInternalNode() {
    this->parent = NULL;
    updateKey();
}

BTreeInternalNode::BTreeInternalNode(vector<BTreeItem*> children) {
    BTreeInternalNode();
    this->children = children;
}

int BTreeInternalNode::getMaxChildren() {
    return 5;
}

int BTreeInternalNode::getMinChildren() {
    return isRoot() ? 2 : 3;
}

void BTreeInternalNode::insert(BTreeItem* item){
    
    int i = 0;
    if ((item->key.compare(children.at(i)->key) > 0) ? true : false) {
        
        while (i < children.size()) {
            if ((item->key.compare(children.at(i)->key) > 0) ? true : false) {
                
                if (i == children.size()-1 || (item->key.compare(children.at(i+1)->key) < 0) ? true : false) {
                    cout << item->key << " > " << children.at(i)->key << endl;
                    break;
                }
            }
            i++;
        }

    }
        cout << "Index to insert item at: " << i << endl;
    cout << "size of index about to be inserted into: " << children.size() << endl;
    children.at(i)->insert(item);
    restructure();
    updateKey();
}

BTreeItem* BTreeInternalNode::copyWithChildren(vector<BTreeItem*> children) {
    return new BTreeInternalNode(children);
}

void BTreeInternalNode::printNode() {
    cout << "Internal Node: ";
    BTreeItem::printNode();
}

void BTreeInternalNode::updateKey()  {
    BTreeItem::updateKey();
    if (children.size() != 0) {
        keys.resize(children.size()-1);
        for (int i = 1; i < children.size(); i++) {
            keys[i-1] = children.at(i)->key;
        }
    }
}

  