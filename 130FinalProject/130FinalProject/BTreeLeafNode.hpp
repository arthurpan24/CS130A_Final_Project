//
//  BTreeLeafNode.hpp
//  130FinalProject
//
//  Created by John Lanier on 3/12/16.
//  Copyright © 2016 JB Lanier. All rights reserved.
//

#ifndef BTreeLeafNode_hpp
#define BTreeLeafNode_hpp

#include <stdio.h>
#include "BTreeItem.hpp"

class BTreeLeafNode: public BTreeItem {
public:

    BTreeLeafNode();
    BTreeLeafNode(vector<BTreeItem*> children);
    
    virtual int getMaxChildren() override;
    virtual int getMinChildren() override;
    virtual void insert(BTreeItem* item) override;
    virtual BTreeItem* copyWithChildren(vector<BTreeItem*> children) override;
};

#endif /* BTreeLeafNode_hpp */
