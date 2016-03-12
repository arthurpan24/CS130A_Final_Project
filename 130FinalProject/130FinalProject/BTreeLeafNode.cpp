//
//  BTreeLeafNode.cpp
//  130FinalProject
//
//  Created by John Lanier on 3/12/16.
//  Copyright © 2016 JB Lanier. All rights reserved.
//

#include "BTreeLeafNode.hpp"

int BTreeLeafNode::getMaxChildren() {
    return 3;
}

int BTreeLeafNode::getMinChildren() {
    return isRoot() ? 0 : 2;
}