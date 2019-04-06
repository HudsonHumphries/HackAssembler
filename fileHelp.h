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