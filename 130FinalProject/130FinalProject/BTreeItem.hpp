//
//  BTreeItem.hpp
//  130FinalProject
//
//  Created by John Lanier on 3/12/16.
//  Copyright © 2016 JB Lanier. All rights reserved.
//

#ifndef BTreeItem_hpp
#define BTreeItem_hpp

#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class BTreeItem {
public:
    string key;
    vector<BTreeItem*> children;
    BTreeItem* parent;
    
    virtual bool isRoot();
    virtual void addChild(BTreeItem* item);
    virtual void insert(BTreeItem* item);
    
    virtual void restructure();
    virtual int getMaxChildren();
    virtual int getMinChildren();
    
    virtual void updateKey();
    
    virtual BTreeItem* copyWithChildren(vector<BTreeItem*> children);
    
    virtual void printNode();
    
    int findIndexToInsertItemAt(BTreeItem *item, vector<BTreeItem*> v);
    
    void recursiveSetParent(BTreeItem* r);

};



#endif /* BTreeItem_hpp */
