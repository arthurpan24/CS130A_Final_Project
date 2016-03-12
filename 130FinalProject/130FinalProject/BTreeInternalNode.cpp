//
//  BTreeInternalNode.cpp
//  130FinalProject
//
//  Created by John Lanier on 3/12/16.
//  Copyright © 2016 JB Lanier. All rights reserved.
//

#include "BTreeInternalNode.hpp"

int BTreeInternalNode::getMaxChildren() {
    return 5;
}

int BTreeInternalNode::getMinChildren() {
    return isRoot() ? 2 : 3;
}

