//
//  BTreeItem.cpp
//  130FinalProject
//
//  Created by John Lanier on 3/12/16.
//  Copyright © 2016 JB Lanier. All rights reserved.
//

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


void BTreeItem::addChild(BTreeItem* item){
    return;
}

int BTreeItem::getMaxChildren(){
    return -1;
}

int BTreeItem::getMinChildren(){
    return -1;
}

bool BTreeItem::isRoot(){
    return false;
}

bool BTreeItem::insert(BTreeItem* item){
    return false;
}

void BTreeItem::restructure(){
    return;
}