#include <fstream>
#include <iostream>
#include <string>
using namespace std;

bool emptyLine(string s) {
    for(int i = 0; i < s.size(); i++) {
        if(!(isspace(s[i]))) {
            return false;
        }
    }
    return true;
}