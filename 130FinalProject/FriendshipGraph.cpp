//
//  FriendshipGraph.cpp
//  130FinalProject
//
//  Created by Arthur Pan on 3/7/16.
//  Copyright © 2016 JB Lanier. All rights reserved.
//

#include "FriendshipGraph.h"

FriendshipGraph::FriendshipGraph (int size)
{
    this->TABLE_SIZE = size;
    this->table = new AdjacencyList[TABLE_SIZE];
    for (int i =0; i < TABLE_SIZE; i++){
        this->table[i].name = "";
        this->table[i].node = nullptr;
    }
}

//For this hash funciton, we will be adding up the total ASCII values of the names and modding it with the table size
//collisions will be solved by linear probing
int FriendshipGraph::hash(std::string str)
{
    int value = stringValue(str);
    return value%TABLE_SIZE;
}

//helper function for hash function
int FriendshipGraph::stringValue(std::string str)
{
    int sum = 0;
    for (int i =0; i < str.size(); i++){
        int j = str[0];
        sum += j;
    }
    return sum;
}

void FriendshipGraph::insert(std::string str)
{
    int hashValue = hash(str);
    while (this->table[hashValue].name.compare("")){
        hashValue++; //linear probing
    }
    this->table[hashValue].name = str;
    return;
}

int FriendshipGraph::findFriend(std::string str)
{
    int hashValue = hash(str);
    while (this->table[hashValue].name.compare(str)){
        hashValue++; //linear probing
    }
    return hashValue;
}

void FriendshipGraph::addFriend(std::string str)
{
    int hashValue = findFriend(str);
    this->table[hashValue].node->name = str;
    this->table[hashValue].node->next = nullptr;
    return;
}