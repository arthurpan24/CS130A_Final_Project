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
    
};

#endif /* BTreeDataItem_hpp */
