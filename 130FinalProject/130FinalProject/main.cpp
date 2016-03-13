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
  //  DB->tree->printTreeDiagram();
    return 0;
}