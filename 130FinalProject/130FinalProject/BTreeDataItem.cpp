//
//  BTreeDataItem.cpp
//  130FinalProject
//
//  Created by John Lanier on 3/12/16.
//  Copyright © 2016 JB Lanier. All rights reserved.
//

#include "BTreeDataItem.hpp"

BTreeDataItem::BTreeDataItem(string key, int indexOnDisk) {
    this->parent = NULL;
    this->key = key;
    this->indexOnDisk = indexOnDisk;
}

void BTreeDataItem::addChild(BTreeItem* item){
    return;
}

void BTreeDataItem::insert(BTreeItem* item){
    return;
}

void BTreeDataItem::restructure(){
    return;
}

int BTreeDataItem::getMaxChildren(){
    return -1;
}

int BTreeDataItem::getMinChildren(){
    return -1;
}

void BTreeDataItem::updateKey() {
    return;
}