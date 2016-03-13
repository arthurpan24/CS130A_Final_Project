//
//  BTreeInternalNode.cpp
//  130FinalProject
//
//  Created by John Lanier on 3/12/16.
//  Copyright © 2016 JB Lanier. All rights reserved.
//

#include "BTreeInternalNode.hpp"
#include "BTreeItem.cpp"

int BTreeInternalNode::getMaxChildren() {
    return 5;
}

int BTreeInternalNode::getMinChildren() {
    return isRoot() ? 2 : 3;
}

bool BTreeInternalNode::insert(BTreeItem* item){
    
    int i = findIndexToInsertItemAt(item, children);
    children.at(i)->insert(item);
    return true;
}

void BTreeInternalNode::restructure(){
    
    return;
}