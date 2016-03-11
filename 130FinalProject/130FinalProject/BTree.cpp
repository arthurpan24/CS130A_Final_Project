//
//  BTree.cpp
//  130FinalProject
//
//  Created by Arthur Pan on 2/23/16.
//  Copyright © 2016 JB Lanier. All rights reserved.
//

#include <iostream>

#include "BTree.h"

BTree::BTree(int MValue, int LValue) {
    M = MValue;
    L = LValue;
}

bool BTree::insert(string name, int indexOnDisk) {
    //Stub
    std::cout << name << ", " << indexOnDisk << " inserted to BTree" << std::endl;
    return true;
}