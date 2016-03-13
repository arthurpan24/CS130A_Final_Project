//
//  StorageManager.cpp
//  130FinalProject
//
//  Created by John Lanier on 3/10/16.
//  Copyright © 2016 JB Lanier. All rights reserved.
//

#include "StorageManager.h"
#include "BTree.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

vector<string> StorageManager::split(string str, char delimiter)
{
    vector<string> internal;
    stringstream ss(str);       // turn the string into a stream.
    string tok;
    
    while(getline(ss, tok, delimiter))
    {
        internal.push_back(tok);
    }
    
    return internal;
}




StorageManager* StorageManager::get() {
    static StorageManager* instance = new StorageManager();
    return instance;
}

bool StorageManager::generateBTreeFromProfileData(string path, BTree* tree) {
    ifstream f;
    f.open(path.c_str(), ios::in);
    if (!f) {
        cerr << "ProfileData.txt not found." << endl;
        return false;
    }
    else {
        int index = 0;
        while(!f.eof()) {
            string line;
            getline(f,line);
            vector<string>names = split(line, '~');
            if (names.size()>0) {
                tree->insert(names[0], index);
            }
            index++;
        }
    }
    return true;
}
bool StorageManager::generateProfileDataFromInputFile(string path) {
    
    ifstream f;
    f.open(path.c_str(), ios::in);
    if(!f) cerr << "Input data not found." << endl;
    else {
        ofstream outputFile;
        outputFile.open("ProfileData.txt");
        
        while(!f.eof())
        {
            string line;
            getline(f,line);
            vector<string>words = split(line, ',');
            
            if (words.size()>0) {
                char* name = new char[20];
                char* age = new char[3];
                char* occupation = new char[30];
                
                for (int i = 0; i < 20; i++) {
                    name[i] = '~';
                }
                name[20] = '\0';
                
                for (int i = 0; i < 3; i++) {
                    age[i] = '~';
                }
                age[3] = '\0';
                
                for (int i = 0; i < 30; i++) {
                    occupation[i] = '~';
                }
                occupation[30] = '\0';
                
                
                for (int i=0; i < words[0].length(); i++) {
                    name[i] = words[0].at(i);
                }
                for (int j=0; j < words[1].length(); j++) {
                    age[j] = words[1].at(j);
                }
                for (int k=0; k < words[2].length(); k++) {
                    occupation[k] = words[2].at(k);
                }
                
               // cout << name << age << occupation << endl;
                
                outputFile << name << age << occupation << "\n";
            }
        }
        
        outputFile.close();
    }
    return true;
}

bool StorageManager::generateFriendshipDataFromInputFile(string path) {
    ifstream f;
    f.open(path.c_str(), ios::in);
    if(!f) cerr << "File not found." << endl;
    else {
        ofstream outputFile;
        outputFile.open("FriendshipData.txt");
        
        while(!f.eof())
        {
            string line;
            getline(f,line);
            vector<string>words = split(line, ',');
            
            if (words.size()>0) {
                string adjacencyList = "";
                adjacencyList = adjacencyList + words[0] + ",";
                if (words.size()>3) {
                    for (int i=3; i < words.size(); i++) {
                        adjacencyList = adjacencyList + words[i] + ",";
                    }
                }
                outputFile << adjacencyList << "\n";
            }
        }
        
        outputFile.close();
    }

    
    return true;
}



