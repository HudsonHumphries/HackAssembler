#include <fstream>
#include <iostream>
#include <string>
using namespace std;

string changefilename(string filename) {
    int j = 0;
    string finalfile = "";
    while(filename[j] != '.') {
        finalfile += filename[j];
        j++;
    }
    finalfile += ".hack";
    return finalfile;
}

bool emptyLine(string s) {
    for(int i = 0; i < s.size(); i++) {
        if(!(isspace(s[i]))) {
            return false;
        }
    }
    return true;
}

bool isComment(string line) {
    if(line[0] == '/' && line[1] == '/') {
        return true;
    }
    return false;
}
//Function that removes spaces and comments from line
string removeSpacesAndComments(string line) {
    int i = 0;
    string res;
    while(i < line.size()) {
        if((i<line.size()-1) && (line[i] == '/' && line[i+1] == '/')){ //If there is a comment and it doesn't go out of range, will end whileloop
            break;
        }
        else if(line[i] != ' ') {
            res.push_back(line[i]);
        }
        i++;
    }
    return res; 
}

bool isLabel(string label) {
    bool left = false;
    bool right = false;
    for(int i = 0; i < label.size(); i++) {
        if(label[i] == '(') left = true;
        if(label[i] == ')') right = true;
    }
    if(left && right) return true;

    return false;
}

string remove_parentheses(string label) {
    string res="";
    for(int i = 0; i < label.size(); i++) {
        if(label[i] == '(' || label[i] == ')') {
            continue;
        }
        else {
            res.push_back(label[i]);
        }
    }
    cout << res << endl; //<< ":" << res.size() << endl;
    res.pop_back();
    return res;
}

