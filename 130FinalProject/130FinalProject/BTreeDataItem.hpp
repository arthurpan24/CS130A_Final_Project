//
//  BTreeDataItem.hpp
//  130FinalProject
//
//  Created by John Lanier on 3/12/16.
//  Copyright © 2016 JB Lanier. All rights reserved.
//

#ifndef BTreeDataItem_hpp
#define BTreeDataItem_hpp

#include <stdio.h>
#include "BTreeItem.hpp"

class BTreeDataItem : public BTreeItem {
public:
    int indexOnDisk;
    
    virtual void addChild(BTreeItem* item) override;
    virtual bool insert(BTreeItem* item) override;
    virtual void restructure() override;
    virtual int getMaxChildren() override;
    virtual int getMinChildren() override;
};

#endif /* BTreeDataItem_hpp */
