/*
 * Main.cpp
 *
 *  Created on: Feb 11, 2016
 *      Author: omid
 */

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
    
    cout << path;
    
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
            cout << words.size() << endl;
            // ... TO DO
        }
    }
    return 0;
}