//
//  BTreeInternalNode.cpp
//  130FinalProject
//
//  Created by John Lanier on 3/12/16.
//  Copyright © 2016 JB Lanier. All rights reserved.
//

#include "BTreeInternalNode.hpp"


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
    
    int i = findIndexToInsertItemAt(item, children);
    children.at(i)->insert(item);
    restructure();
    updateKey();
}

BTreeItem* BTreeInternalNode::copyWithChildren(vector<BTreeItem*> children) {
    return new BTreeInternalNode(children);
}

  