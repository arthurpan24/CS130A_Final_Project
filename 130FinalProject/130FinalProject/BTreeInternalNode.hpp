//
//  BTreeInternalNode.hpp
//  130FinalProject
//
//  Created by John Lanier on 3/12/16.
//  Copyright © 2016 JB Lanier. All rights reserved.
//

#ifndef BTreeInternalNode_hpp
#define BTreeInternalNode_hpp

#include <stdio.h>
#include "BTreeItem.hpp"

class BTreeInternalNode : public BTreeItem {
public:
    vector<string> keys;
    
    virtual int getMaxChildren() override;
     virtual int getMinChildren() override;
};

#endif /* BTreeInternalNode_hpp */
