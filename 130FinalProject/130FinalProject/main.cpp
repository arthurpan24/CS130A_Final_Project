/*
 * Main.cpp
 *
 *  Created on: Feb 11, 2016
 *      Author: omid
 */

#include "Person.h"
#include "BTree.h"
#include "FriendshipGraph.h"

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>

#include "SocialNetworkDB.h"

using namespace std;

vector<string> split(string str, char delimiter)
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

int main(int argc, char** argv)
{
    SocialNetworkDB* DB = new SocialNetworkDB;
    
    
    string path = "";
    
    // Handle Debug Arguements for running the program on our induvidual machines
    if (argc == 1) {
        path = "Generated1.txt";
    } else if (!strcmp(argv[1], "xcode") && !strcmp(argv[2], "arthur")) {
        path = "/Users/arthurpan/Desktop/CS130A_Final_Project/130FinalProject/130FinalProject/Generated1.txt";
    } else if (!strcmp(argv[1], "xcode") && !strcmp(argv[2], "jb")) {
        path = "/Users/JB/Documents/CS130A_Final_Project/130FinalProject/130FinalProject/Generated1.txt";
    } else {
        cout << "wrong arguements" << endl;
        return 1;
    }

    
    DB->initializeFromInputData(path);
    
    /*
     
     
    //Note: Currently, there are 3 different test cases
    //Make sure to use Generated1.txt, Generated2.txt, and Generated3.txt to test
    string path;
    if (argc == 1) {
        path = "Generated1.txt";
    } else if (!strcmp(argv[1], "xcode") && !strcmp(argv[2], "arthur")) {
     path = "/Users/arthurpan/Desktop/CS130A_Final_Project/130FinalProject/130FinalProject/Generated1.txt";
    } else if (!strcmp(argv[1], "xcode") && !strcmp(argv[2], "jb")) {
        path = "/Users/JB/Documents/CS130A_Final_Project/130FinalProject/130FinalProject/Generated1.txt";
    } else {
        cout << "wrong arguements" << endl;
        return 1;
    }
    
    //cout << path;
    
    ifstream f;
    f.open(path.c_str(), ios::in);
    if(!f) cerr << "File not found." << endl;
    else
    {
        FriendshipGraph *graph = new FriendshipGraph(201);
        ofstream outputFile;
        outputFile.open("ProfileData.txt");
        
        while(!f.eof())
        {
            string line;
            std::getline(f, line);
            vector<string> words = split(line, ',');
            
            for (int i = 0; i <words.size(); i++) {
               // cout << words[i] << ",";
            }
            //cout << endl;

            //Add the name of the person into the adjacency list
            if (words.size()>0) {
                graph->insert(words[0]);
                
                //Create linked list of friend names inside hash table element
                int j =3;
                while (j <= words.size()-1){
                    graph->addFriend(words[0], words[j]);
                    j++;
                }
                
                ///////////////////
                //THIS DOES NOT WORK YET: CAN'T FIND THE BUG FOR THIS THOUGH
                ///////////////////
                
                //Add the name(words[0]), age(words[1]), and occupation(words[2]) of person to disk in Person.cpp
                //Format: char[20] name, char[3] age, char[30]occupation
                //NOTE: Use ~ as a buffer until the end of the word
                char* name = new char[20];
                char* age = new char[3];
                char* occupation = new char[30];
                
                for (int i=0; i < words[0].length(); i++) {
                    name[i] = words[0].at(i);
                    cout << name[i];
                }
                cout << name; //WTF this is different
                for (int j=0; j < words[1].length(); j++) {
                    age[j] = words[1].at(j);
                }
                for (int k=0; k < words[2].length(); k++) {
                    occupation[k] = words[2].at(k);
                }
                cout<< "TEST: " << words[0] << " " << words[1] << " " << words[2] << endl;
                
                //test 2 is not working, and it seems like the people without friends are having issues haha
                cout << "TEST2: " << name << " " << age << " "<< occupation << endl;
                //Add ~ for buffer spaces
                //cout << (int)words[0].length() << " " << (int)words[1].length() << " " << (int)words[2].length() << endl;
                for (int i = (int)words[0].length(); i < 20; i++) {
                    name[i] = '~';
                }
                for (int i = (int)words[1].length(); i < 3; i++) {
                    age[i] = '~';
                }
                for (int i = (int)words[2].length(); i < 30; i++) {
                    occupation[i] = '~';
                }
                
               // cout << name << age << occupation << endl;
                outputFile << name << age << occupation << "\n"; //quite possibly won't be using a new line manually like this
            }
        
        }
     
        //graph->printAllList();
        
        outputFile.close();
    }
     
     
     */
    return 0;
}