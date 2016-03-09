//
//  FriendshipGraph.cpp
//  130FinalProject
//
//  Created by Arthur Pan on 3/7/16.
//  Copyright © 2016 JB Lanier. All rights reserved.
//

#include "FriendshipGraph.h"
#include "AdjacencyList.h"

#include <iostream>

FriendshipGraph::FriendshipGraph (int size)
{
    this->TABLE_SIZE = size;
    this->table = new AdjacencyList[TABLE_SIZE];
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
    while (!table[hashValue].empty){
        hashValue++; //linear probing
    }
    this->table[hashValue].name = str;
    this->table[hashValue].empty = false;
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

void FriendshipGraph::addFriend(std::string original, std::string buddy)
{
    int hashValue = findFriend(original);
    
    LinkedListNode* insertNode = new LinkedListNode(buddy);
    
    //if empty linked list, put at beggining
    if (this->table[hashValue].head == NULL) {
        this->table[hashValue].head = insertNode;
        this->table[hashValue].tail = insertNode;

    }
    else {
        this->table[hashValue].tail->next = insertNode;
        this->table[hashValue].tail = insertNode;
    }
   
    return;
}

//TEST FUNCTION
void FriendshipGraph::printAllList()
{
    for (int i=0; i <TABLE_SIZE; i++) {
        if (!table[i].empty) {
            std::cout << "Person: " << table[i].name << ": ";
            while (table[i].head  != NULL){
                std::cout << table[i].head->name << ",";
                table[i].head = table[i].head->next;
            }
            std::cout << std::endl;
        }
    }
}






