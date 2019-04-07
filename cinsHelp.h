#ifndef _CINS_HELP_H_
#define _CINS_HELP_H_

#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class cinsHelp {
    public:
        cinsHelp();
        bool isCompBits(string cstring);
        bool isDestBits(string dstring);
        bool isJumpBits(string jstring);
        bool isCinstruction(string instruction);

    private:
        unordered_map<string,string> dest;
        unordered_map<string,string> comp;
        unordered_map<string,string> jump;
        string deststring;
        string compstring;
        string jumpstring;
};

#endif