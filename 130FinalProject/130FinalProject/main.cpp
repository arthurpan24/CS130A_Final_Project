/*
 * Main.cpp
 *
 *  Created on: Feb 11, 2016
 *      Author: omid
 */

#include "HashTable.h"
#include "Person.h"
#include "BTree.h"
#include "Graph.h"

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
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
    //Note: Currently, there are 3 different test cases
    //Make sure to use Generated1.txt, Generated2.txt, and Generated3.txt to test
    string path;
    if (argc == 1) {
        path = "Generated1.txt";
    } else if (!strcmp(argv[1], "xcode") && !strcmp(argv[2], "arthur")) {
     path = "/Users/arthurpan/Desktop/CS130A_Final_Project/130FinalProject/130FinalProject/Generated1.txt";
    } else if (!strcmp(argv[1], "xcode") && !strcmp(argv[2], "jb")) {
        path = "/Users/JB/Developement/CS130A_Final_Project/130FinalProject/130FinalProject/Generated1.txt";
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
        while(!f.eof())
        {
            string line;
            std::getline(f, line);
            vector<string> words = split(line, ',');
  
            for (int i = 0; i <words.size(); i++) {
                cout << words[i] << ",";
            }
            //We can assume that the inputs are of currect format, so we can assume that there will be at least 3 inputs
            //words[0] will be the name of the person
            //words[1] will be the age of the person
            //words[2] will be the occupation/desciption
            //Create an object with these parameters, and then add friends in through other means
            
            
            //Also should support taking in printall function
        }
        
        
    }
    return 0;
}