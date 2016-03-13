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
    
    int i = findIndexToInsertItemAt(item, children);
    children.insert(children.begin()+i, item);
    
    std::cout << "New: ";
    for (int i = 0;  i < children.size(); i++) {
        std::cout << children.at(i)->key << ",";
    }
    std::cout << std::endl;
}

bool BTreeItem::insert(BTreeItem* item){
    
    return false;
}

void BTreeItem::restructure(){
    return;
}

int BTreeItem::getMaxChildren(){
    return -1;
}

int BTreeItem::getMinChildren(){
    return -1;
}

int BTreeItem::findIndexToInsertItemAt(BTreeItem *item, vector<BTreeItem*> v) {
    
    int i;
    while (i < v.size()) {
        if (*item < *(v.at(i)) ) {
            break;
        }
        i++;
    }
    return i;
}


