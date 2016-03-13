//
//  BTree.cpp
//  130FinalProject
//
//  Created by Arthur Pan on 2/23/16.
//  Copyright © 2016 JB Lanier. All rights reserved.
//

#include <iostream>

#include "BTree.h"
#include "BTreeLeafNode.hpp"
#include "BTreeInternalNode.hpp"
#include "BTreeDataItem.hpp"

using namespace std;

BTree::BTree() {
    this->root = new BTreeLeafNode();
}

void BTree::printTreeDiagram() {
    cout << "/////////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "This is what the B-Tree looks like right now" << endl;
    cout << "/////////////////////////////////////////////////////////////////////////////////////////" << endl;
    BTreeItem* node = root;
    queue<BTreeItem *> currentLevel, nextLevel;
    if (node == NULL)
        return;
    
    currentLevel.push(node);
    while (!currentLevel.empty()) {
        BTreeItem* temp = currentLevel.front();
        currentLevel.pop();
        if (temp) {
            printCurrentNode(temp);
            for (int i=0; i <temp->children.size(); i++) {
                nextLevel.push(temp->children.at(i));
            }
        }
        cout << "\t\t";
        
        if (currentLevel.empty()) {
            cout << endl << endl;
            swap(currentLevel, nextLevel);
        }
    }
    
}
void BTree::printCurrentNode(BTreeItem *node) {
    for (int i=0; i < node->children.size(); i++) {
        cout << node->children.at(i)->key << ",";
    }
}


bool BTree::insert(string name, int indexOnDisk) {
    root->insert(new BTreeDataItem(name, indexOnDisk));
    if (root->parent != NULL) {
        root = root->parent;
    }
   // cout << "/////////////////////////////////////////////////////////////////////////////////////////" << endl;
  //  std::cout << "----------------" << name << ", " << indexOnDisk << " INSERTED!" << "----------------" << std::endl;
   // cout << "/////////////////////////////////////////////////////////////////////////////////////////" << endl;
   // cout << "COTENTS OF NEW TREE: " << endl;
   // root->printNode();
   // cout << "/////////////////////////////////////////////////////////////////////////////////////////" << endl;
    return true;
}

int BTree::find(string name) {
    return recursiveFindHelper(root, name);
}

int BTree::recursiveFindHelper(BTreeItem* node, string name) {
    
    // Case: Node in question is a data item (at the tip of a leave node)
    BTreeDataItem* d = dynamic_cast<BTreeDataItem*>(node);
    if (d != NULL) {
        return d->indexOnDisk;
    }
    
    // CASE: Node in question is a internal node
    BTreeInternalNode* e = dynamic_cast<BTreeInternalNode*>(node);
    if (e != NULL) {
        for (int i = 0; i < e->children.size(); i++) {
            if (i == 0 && (name.compare(e->keys.at(0)) < 0)) {
                return recursiveFindHelper(e->children.at(0), name);
            }
            if (i >= e->children.size()-1) {
                return recursiveFindHelper(e->children.at(e->children.size()-1), name);
            }
            if ((name.compare(e->keys.at(i)) < 0) && (name.compare(e->keys.at(i-1)) >= 0) ) {
                return recursiveFindHelper(e->children.at(i), name);
            }
        }
        
    }
    
    //Case: Node is a leaf node
    for (int i = 0; i < node->children.size(); i++) {
        cout << node->children.at(i)->key << endl;
        if (name == node->children.at(i)->key) {
            return recursiveFindHelper(node->children.at(i), name);
        }
    }
    
    return -3;
}

vector<int> BTree::findRange(string lowerBound, string upperBound) {
    vector<int> results;
    recursiveFindRangeHelper(root, lowerBound, upperBound, results);
    return results;
}

void BTree::recursiveFindRangeHelper(BTreeItem *node, string lowerBound, string upperBound, vector<int> &matches) {
    // Case: Node in question is a data item (at the tip of a leave node)
    BTreeDataItem* d = dynamic_cast<BTreeDataItem*>(node);
    if (d != NULL) {
        matches.push_back(d->indexOnDisk);
        return;
    }
    
    // CASE: Node in question is a internal node
    BTreeInternalNode* e = dynamic_cast<BTreeInternalNode*>(node);
    if (e != NULL) {
        
        int startingIndex = 0;
        while (startingIndex < e->keys.size()) {
            if (lowerBound.compare(e->keys.at(startingIndex)) < 0) {
                break;
            }
            
            startingIndex++;
        }
        
        int i = startingIndex;
        
        while (i < e->children.size()) {
        
            recursiveFindRangeHelper(e->children.at(i), lowerBound, upperBound, matches);
            
            if (i >= e->keys.size() || upperBound.compare(e->keys.at(i)) < 0) {
                break;
            }
            
            
            i++;
        }

        return;
    }
    
    //Case: Node is a leaf node
    for (int i = 0; i < node->children.size(); i++) {
        if (node->children.at(i)->key.compare(lowerBound) >= 0 && node->children.at(i)->key.compare(upperBound) <= 0 ) {
            recursiveFindRangeHelper(node->children.at(i), lowerBound, upperBound, matches);
        }
    }
    return;
}