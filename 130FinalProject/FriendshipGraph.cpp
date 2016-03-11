//
//  FriendshipGraph.cpp
//  130FinalProject
//
//  Created by Arthur Pan on 3/7/16.
//  Copyright © 2016 JB Lanier. All rights reserved.
//

#include "FriendshipGraph.h"

#include <iostream>

FriendshipGraph::FriendshipGraph (int size)
{
    this->tableSize = size;
    this->table = new AdjacencyListNode*[tableSize];
    
    for (int i=0; i<tableSize; i++) {
        table[i] = NULL;
    }
}

int FriendshipGraph::hash(std::string str, int seed=0)
{
    int hash = seed;
    for (int i=0; i<str.length(); i++) {
        hash = hash *101 + str[i];
    }
    return hash % tableSize;
}

void FriendshipGraph::insert(std::string name, int indexOnDisk)
{
    int hashValue = hash(name);
    while (table[hashValue] != NULL){
        hashValue++;
    }
    table[hashValue] = new AdjacencyListNode(name, indexOnDisk);
    return;
}

int FriendshipGraph::findPerson(std::string str)
{
    int hashValue = hash(str);
    int originalHashValue = hashValue;
    while (this->table[hashValue]->name.compare(str)){
        hashValue = (hashValue + 1)%tableSize;
        if (hashValue == originalHashValue) {
            return -1;
        }
    }
    return hashValue;
}

void FriendshipGraph::addFriend(std::string target, std::string friendsName, int friendsIndexOnDisk)
{
    int hashValue = findPerson(target);
    
    if (hashValue == -1) {
        return;
    }
    
    AdjacencyListNode* insertNode = new AdjacencyListNode(friendsName, friendsIndexOnDisk);
    
    AdjacencyListNode* p = this->table[hashValue];
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = insertNode;
    
    return;
}

vector<string> FriendshipGraph::findFriends(string target)
{
    vector<string> listOfFriends = vector<string>();
    int hashValue = findPerson(target);
    
    if (hashValue == -1) {
        return listOfFriends;
    }
    
    for (AdjacencyListNode* p = this->table[hashValue]->next; p != NULL; p = p->next) {
        listOfFriends.push_back(p->name);
    }
    return listOfFriends;
}


