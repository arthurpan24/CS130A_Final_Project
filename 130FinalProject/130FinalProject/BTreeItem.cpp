//
//  BTreeItem.cpp
//  130FinalProject
//
//  Created by John Lanier on 3/12/16.
//  Copyright © 2016 JB Lanier. All rights reserved.
//

#include <iostream>

#include "BTreeItem.hpp"
#include "BTreeInternalNode.hpp"

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
    
    ////Debug///////////////////////////////////
    std::cout << "Sorting Vector. Orig: ";
    for (int i = 0;  i < children.size(); i++) {
        std::cout << children.at(i)->key << ",";
    }
    std::cout << std::endl;
    ////////////////////////////////////////////
    
    item->updateKey();
    for (int i = 0; i < children.size(); i++) {
        children.at(i)->updateKey();
    }
    int i = findIndexToInsertItemAt(item, children);
    cout << "size of index about to be inserted into: " << children.size() << endl;
    children.insert(children.begin()+i, item);
    item->parent = this;
    item->updateKey();
    updateKey();

    
    ////Debug///////////////////////////////////
    std::cout << "New: ";
    for (int i = 0;  i < children.size(); i++) {
        std::cout << children.at(i)->key << ",";
    }
    std::cout << std::endl;
    ////////////////////////////////////////////
}

void BTreeItem::updateKey() {
    if (children.size() > 0) {
        key = children.at(0)->key;
    } else {
        key = "NO_KEY";
    }
}

void BTreeItem::insert(BTreeItem* item){
    return;
}

void BTreeItem::restructure(){
    if (children.size() <= getMaxChildren()) {
        return;
    }
    
    if (isRoot()) {
        this->parent = new BTreeInternalNode();
        this->parent->addChild(this);
    }
    
    
    unsigned long halfSize = children.size()/2;
    vector<BTreeItem*> newNodesChildren(children.begin() + halfSize, children.end());
    children.resize(halfSize);
    this->parent->addChild(copyWithChildren(newNodesChildren));
}

int BTreeItem::getMaxChildren(){
    return -1;
}

int BTreeItem::getMinChildren(){
    return -1;
}

BTreeItem* BTreeItem::copyWithChildren(vector<BTreeItem*> children) {
    return NULL;
}

int BTreeItem::findIndexToInsertItemAt(BTreeItem *item, vector<BTreeItem*> v) {
    
    int i = 0;
    while (i < v.size()) {
        if (*item < *(v.at(i)) ) {
            cout << item->key << " < " << v.at(i)->key << endl;
            break;
        }
        i++;
    }
    cout << "Index to insert item at: " << i << endl;
    return i;
}

void BTreeItem::printNode() {
    for (int i = 0; i< children.size(); i++) {
        cout << children.at(i)->key << ", ";
    }
    cout << endl;
    
    for (int i = 0; i< children.size(); i++) {
        children.at(i)->printNode();
    }
}

