//
//  SocialNetworkDB.cpp
//  130FinalProject
//
//  Created by John Lanier on 3/10/16.
//  Copyright © 2016 JB Lanier. All rights reserved.
//

#include <string>
#include <iostream>

#include "SocialNetworkDB.h"

SocialNetworkDB::SocialNetworkDB() {
    
    // Initialize a quick reference pointer to the Storage Manager
    SM = StorageManager::get();
    
    // Create Data Stuctures
    graph = new FriendshipGraph(211);
    tree = new BTree();
    
}

void SocialNetworkDB::initializeFromInputData(string path) {
    if (path == "") {
        // Set default value of path if empty string is given
        path = "Generated1.txt";
    }
    
    SM->generateProfileDataFromInputFile(path);
    SM->generateFriendshipDataFromInputFile(path);
    
    initializeFromSavedData(path);
    
    addFriendship("Eli", "Levi");
    printInfoOfFriends("Levi");
    printInfoOfFriends("Eli");
    printInfo("Eli");
}

void SocialNetworkDB::initializeFromSavedData(string path) {
    if (path == "") {
        // Set default value of path if empty string is given
        path = "Generated1.txt";
    }
    
    SM->populateBTreeFromProfileData("ProfileData.txt", tree);
    SM->populateFriendshipGraphFromData("FriendshipData.txt", graph, tree);
    
}

void SocialNetworkDB::printInfoOfFriends(string target) {
    vector<int> x = graph->findFriendsIndexes(target);
    cout << endl << "////////////////////////////////////////" << endl << "Friends of " << target << ":" << endl;
    for (int i = 0; i < x.size(); i++) {
        cout << SM->getPersonAtIndex(x.at(i)).ToString() << endl;
    }
}

void SocialNetworkDB::printAll() {
    vector<int> x = tree->findRange("A", "}");
    cout << endl << "////////////////////////////////////////" << endl << "All People In Data Base:" << endl;
    for (int i = 0; i < x.size(); i++) {
        Person p = SM->getPersonAtIndex(x.at(i));
        cout << p.ToString() << ", ";
        vector<string> c = graph->findFriendsNames(p.name);
        for (int i = 0; i < c.size(); i++) {
            cout << c.at(i) << ", ";
        }
        cout << endl;
    }
}

void SocialNetworkDB::printRange(string lowerBound, string upperBound) {
    vector<int> x = tree->findRange(lowerBound, upperBound);
    cout << endl << "////////////////////////////////////////" << endl << "People from " << lowerBound << " to " << upperBound << ": " << endl;
    for (int i = 0; i < x.size(); i++) {
        Person p = SM->getPersonAtIndex(x.at(i));
        cout << p.ToString() << ", ";
        vector<string> c = graph->findFriendsNames(p.name);
        for (int i = 0; i < c.size(); i++) {
            cout << c.at(i) << ", ";
        }
        cout << endl;
    }
}

void SocialNetworkDB::addPerson(string name, int age, string occupation) {
    Person p(name, age, occupation);
    int index = SM->savePersonToProfileData(p);
    tree->insert(p.name, index);
    graph->insert(p.name, index);
}

void SocialNetworkDB::addFriendship(string target, string newFriend) {
    int friendIndex = tree->find(newFriend);
    int targetIndex = tree->find(target);
    if (friendIndex < 0 || targetIndex < 0) {
        return;
    }

    graph->addFriend(target, newFriend, friendIndex);
    graph->addFriend(newFriend, target, targetIndex);
    
    cout << endl << "-- "<< target << " and " << newFriend << " are now friends. --" << endl;
}

void SocialNetworkDB::printInfo(string name) {
    int index = tree->find(name);
    if (index < 0) {
        return;
    }
    cout << endl << "////////////////////////////////////////" << endl << "Info for " << name << ": " << endl;
    cout << SM->getPersonAtIndex(index).ToString() << ", ";
    vector<string> c = graph->findFriendsNames(name);
    for (int i = 0; i < c.size(); i++) {
        cout << c.at(i) << ", ";
    }
    cout << endl;
}

void SocialNetworkDB::displayTree() {
    tree->printTreeDiagram();
}


