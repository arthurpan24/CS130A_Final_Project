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

void printOptions() {
    cout << endl;
    cout << "Choose one of the following options: " << endl;
    cout << "--------------------------------------------------------- " << endl;
    cout << "1. Print information for everyone in the database" << endl;
    cout << "2. Print information for everyone within a range of names" << endl;
    cout << "3. Print information for all the friends of someone" << endl;
    cout << "4. Print all the information pertaining to someone" << endl;
    cout << "5. Add a friendship between two people" << endl;
    cout << "6. Add a person to the database" << endl;
    cout << "7. Display the current B-Tree in memory" << endl;
    cout << "8. Save New Friendship Data to Disk" << endl;
    cout << "9. Quit the program" << endl;
    cout << "--------------------------------------------------------- " << endl;
    
}

int main(int argc, char** argv)
{
    string path = "";
    
    /*
    // Handle Debug Arguements for running the program on our induvidual machines
    if (argc == 1) {
        path = "Generated1.txt";
    } else if (!strcmp(argv[1], "xcode") && !strcmp(argv[2], "arthur")) {
        path = "/Users/arthurpan/Desktop/CS130A_Final_Project/130FinalProject/130FinalProject/Generated1.txt";
    } else if (!strcmp(argv[1], "xcode") && !strcmp(argv[2], "jb")) {
        path = "/Users/JB/Documents/CS130A_Final_Project/130FinalProject/130FinalProject/Generated2.txt";
    } else {
        cout << "wrong arguements" << endl;
        return 1;
    }
    */
    
    cout << "Generate from saved data? (y/n)" << endl;
    
    string input;
    string input2;
    
    cin >> input;
    
    SocialNetworkDB* DB = new SocialNetworkDB;

    
    if (input.compare("y") == 0) {
        DB->initializeFromSavedData("");
    } else {
        cout << "Enter input file name: " << endl;
         cin >> input;
        DB->initializeFromInputData(input);
    }
    
    
    bool done = false;
    while (!done) {
        printOptions();
        cin >> input;
        int x = stoi(input);
        if (!(x > 0 && x < 10)) {
            cout << "invalid input" << endl;
            continue;
        }
        
        switch (x) {
            case 1:
                cout << endl;
                DB->printAll();
                break;
            
            case 2:
                cout << "Enter Lower Bound: ";
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                getline(cin, input);
                cout << "Enter Upper Bound: ";
                getline(cin, input2);
                cout << endl;
                DB->printRange(input, input2);
                break;
            
            case 3:
                cout << "Enter Person in Question: ";
                getline(cin, input);
                cout << endl;
                DB->printInfoOfFriends(input);
                break;
                
            case 4:
                cout << "Enter Person in Question: ";
                getline(cin, input);
                cout << endl;
                DB->printInfo(input);
                break;
                
            case 5:
                cout << "Enter Friend 1: ";
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                getline(cin, input);
                cout << "Enter Friend 2: ";
                getline(cin, input2);
                cout << endl;
                DB->addFriendship(input, input2);
                break;
                
            case 6:
            {
                string name;
                int age;
                string occupation;
                cout << "Input the person's name: " << endl;
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                getline(cin, name);
                cout << "Input the person's age: " << endl;
                cin >> age;
                if (age > 999) {
                    cout << "Error inputting person's age: Value is greater than 3 digits long." << endl;
                    break;
                }
                cout << "Input the person's occupation: " << endl;
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                getline(cin,occupation);
                DB->addPerson(name,age, occupation);
                cout << name << " has been successfully inserted into the DataBase" << endl;
                break;
            }
            case 7:
                DB->displayTree();
                break;
                
            case 8:
                DB->SM->SaveFriendshipGraphToDisk(DB->graph);
                break;
            case 9:
                cout << "The program will now terminate." << endl;
                cout << "Thanks for using our program!" << endl;
                cout << "--------------------------------------------------------- " << endl;
                done = true;
                break;
            default:
                cout << "Invalid input" << endl;
                break;
        }
    }
    

    return 0;
}