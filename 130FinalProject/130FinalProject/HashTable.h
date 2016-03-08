//
//  HashTable.h
//  130FinalProject
//
//  Created by Arthur Pan on 2/23/16.
//  Copyright © 2016 JB Lanier. All rights reserved.
//

#ifndef HashTable_h
#define HashTable_h

#include "Person.h"
#include <stdio.h>


//Some instruction details
//For collisions you can use linear probing. Furthermore, note we are not asking you to support the delete operation or the rehash. You can assume that the system will have at most 100 users, so, your adjacency list/hash table should be of size 201 (the smallest prime just bigger than 2 * 100, which ensures that the hash table is half full for better overall performance).

class HashTable {
    public:
        HashTable();
        bool insert(Person::Person person); //should return true if successful, false if not successful
    
    private:
        int table_size;
        int key;
};
#endif /* HashTable_h */
