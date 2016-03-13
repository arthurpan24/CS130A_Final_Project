//
//  BTreeItem.cpp
//  130FinalProject
//
//  Created by John Lanier on 3/12/16.
//  Copyright © 2016 JB Lanier. All rights reserved.
//

#include <iostream>

#include "BTreeItem.hpp"

bool operator==(const BTreeItem& lhs, const BTreeItem& rhs) {
    return !lhs.key.compare(rhs.key);
}

bool operator >(const BTreeItem& lhs, const BTreeItem& rhs) {
    return (lhs.key.compare(rhs.key) > 0) ? true : false;
}

bool operator >=(const BTreeItem& lhs, const BTreeItem& rhs) {
    return (lhs > rhs) || (lhs == rhs);
}

bool operator <(const BTreeItem& lhs, const BTreeItem& rhs) {
    return !(lhs >= rhs);
}

bool operator <=(const BTreeItem& lhs, const BTreeItem& rhs) {
    return (lhs < rhs) || (lhs == rhs);
}

bool BTreeItem::isRoot(){
    if (parent == NULL){
        return true;
    }
    return false;
}

void BTreeItem::addChild(BTreeItem* item){
    
    std::cout << "Sorting Vector. Orig: ";
    for (int i = 0;  i < children.size(); i++) {
        std::cout << children.at(i)->key << ",";
    }
    std::cout << std::endl;
    
    //add child to children vector
    int i;
    
    bool hasInserted = false;
    
    while (i < children.size()) {
        if (*item < *(children.at(i)) ) {
            children.insert(children.begin()+i, item);
            hasInserted = true;
            break;
        }
        i++;
    }
    
    if (!hasInserted) {
         children.insert(children.begin()+i, item);
         hasInserted = true;
    }
    
    std::cout << "New: ";
    for (int i = 0;  i < children.size(); i++) {
        std::cout << children.at(i)->key << ",";
    }
    std::cout << std::endl;
}


int BTreeItem::getMaxChildren(){
    return -1;
}

int BTreeItem::getMinChildren(){
    return -1;
}

bool BTreeItem::insert(BTreeItem* item){
    return false;
}

void BTreeItem::restructure(){
    return;
}
