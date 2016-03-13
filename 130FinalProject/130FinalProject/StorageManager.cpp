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


vector<string> StorageManager::split(const string& str, const char& ch) {
    string next;
    vector<string> result;
    
    // For each character in the string
    for (string::const_iterator it = str.begin(); it != str.end(); it++) {
        // If we've hit the terminal character
        if (*it == ch) {
            // If we have some characters accumulated
            if (!next.empty()) {
                // Add them to the result vector
                result.push_back(next);
                next.clear();
            }
        } else {
            // Accumulate the next character into the sequence
            next += *it;
        }
    }
    if (!next.empty())
        result.push_back(next);
    return result;
}

StorageManager* StorageManager::get() {
    static StorageManager* instance = new StorageManager();
    return instance;
}

StorageManager::StorageManager() {
    maxIndex = 0;
}


bool StorageManager::populateBTreeFromProfileData(string path, BTree* tree) {
    ifstream f;
    f.open(path.c_str(), ios::in);
    if (!f) {
        cerr << "Profile Data not found." << endl;
        cout << "Exiting Program" << endl;
        exit(0);
        return false;
    }
    else {
        cout << "Populating BTree" << endl;
        int index = 0;
        while(!f.eof()) {
            string line;
            getline(f,line);
            vector<string>names = split(line, '~');
            if (names.size()>0) {
                tree->insert(names[0], index);
            }
            index++;
            this->maxIndex++;
        }
    }
    return true;
}

bool StorageManager::populateFriendshipGraphFromData(string path, FriendshipGraph *graph, BTree* tree) {
    ifstream f;
    f.open(path.c_str(), ios::in);
    if (!f) {
        cerr << "Friendship Data not found." << endl;
        cout << "Exiting Program" << endl;
        exit(0);
        return false;
    }
    else {
        cout << "Populating Friendship Graph" << endl;
        int index = 0;
        while(!f.eof()) {
            string line;
            getline(f,line);
            vector<string>names = split(line, ',');
            if (names.size()>0) {
                graph->insert(names[0], index);
                if (names.size() > 1) {
                    for (int i = 1; i < names.size(); i++) {
                        graph->addFriend(names[0], names[i], tree->find(names[i]));
                    }
                }
            }
            index++;
        }
    }
    return true;

}

bool StorageManager::generateProfileDataFromInputFile(string path) {
    
    ifstream f;
    f.open(path.c_str(), ios::in);
    if(!f) {
        cerr << "Input File not found." << endl;
        cout << "Exiting Program" << endl;
        exit(0);
    } else {
        cout << "Generating Profile Data from Input File" << endl;
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
    if(!f) {
        cerr << "Input File not found." << endl;
        cout << "Exiting Program" << endl;
        exit(0);
        
    } else {
        cout << "Generating Friendship Data from Input File" << endl;
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

Person StorageManager::getPersonAtIndex(int indexOnDisk)
{
    if (indexOnDisk <= maxIndex || indexOnDisk >= 0) {
       // cout << indexOnDisk;
        ifstream f;
        string profileDataPath = "ProfileData.txt";
        
        f.open(profileDataPath.c_str(), ios::in);
        
        
        if (!f){
            cerr << "ProfileData.txt not found." << endl;
            cout << "Exiting Program" << endl;
            exit(0);
        }
        else {
            string line;
            f.seekg(indexOnDisk*54);
            getline(f,line);
            vector<string>words = split(line, '~');
            Person result(words[0], stoi(words[1]), words[2], indexOnDisk);
            return result;
        }
    }

    return Person("No Match Found", -1, "NA" , -1);
}

int StorageManager::savePersonToProfileData(Person p) {
    std::ofstream outfile;
    
    outfile.open("ProfileData.txt", std::ios_base::app);
    
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
    
    
    for (int i=0; i < p.name.length(); i++) {
        name[i] = p.name.at(i);
    }
    
    if (p.age > 999) {
        cerr << "ERROR: Tried saving an age greater than three digits. " << p.name << " failed to save." << endl;
        return -1;
    }

    string ageInput = to_string(p.age);
    for (int j=0; j < ageInput.length(); j++) {
        age[j] = ageInput.at(j);
    }
    
    
    for (int k=0; k < p.occupation.length(); k++) {
        occupation[k] = p.occupation.at(k);
    }

    
    outfile << name << age << occupation << endl;
    int r = maxIndex -1 ;
    maxIndex++;
    return r;
    
}

void StorageManager::SaveFriendshipGraphToDisk(FriendshipGraph* graph) {
    ofstream outputFile;
    outputFile.open("FriendshipData.txt");
    
    int n = 0;
    for (int i = 0; i < graph-> tableSize; i++) {
        if (graph->table[i] != NULL) {
            outputFile << graph->table[i]->name << ",";
            n++;
            for (FriendshipGraph::AdjacencyListNode* p = graph->table[i]->next; p != NULL; p = p->next) {
                outputFile << p->name << ",";
            }
            outputFile << endl;
        }
    }
    cout << "-- Friendship information for " << n << " people saved. --" << endl;
}
