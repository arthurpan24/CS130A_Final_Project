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
    vector<BTreeItem> children;
    
    virtual void addChild(BTreeItem* item);
    virtual int getMaxChildren();
    virtual int getMinChildren();
    virtual bool isRoot();
    virtual bool insert(BTreeItem* item);
    virtual void restructure();
    
};


#endif /* BTreeItem_hpp */
