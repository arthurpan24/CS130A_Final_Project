//
//  BTreeLeafNode.cpp
//  130FinalProject
//
//  Created by John Lanier on 3/12/16.
//  Copyright © 2016 JB Lanier. All rights reserved.
//

#include "BTreeLeafNode.hpp"
#include <iostream>

using namespace std;

BTreeLeafNode::BTreeLeafNode() {
    this->parent = NULL;
    updateKey();
}

BTreeLeafNode::BTreeLeafNode(vector<BTreeItem*> children) {
    BTreeLeafNode();
    this->children = children;
}

int BTreeLeafNode::getMaxChildren() {
    return 3;
}

int BTreeLeafNode::getMinChildren() {
    return isRoot() ? 0 : 2;
}

void BTreeLeafNode::insert(BTreeItem* item){
    addChild(item);
    restructure();
    updateKey();
}

BTreeItem* BTreeLeafNode::copyWithChildren(vector<BTreeItem*> children) {
    return new BTreeLeafNode(children);
}

void BTreeLeafNode::printNode() {
    cout << "Leaf Node: ";
    BTreeItem::printNode();
}
