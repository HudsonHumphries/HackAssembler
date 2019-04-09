#ifndef _SYMBOL_TABLE_H_
#define _SYMBOL_TABLE_H_

#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class SymbolTable {
    public:
        SymbolTable();
        bool contains(string symbol);
        void addSymbol(string symbol);
        void addLabel(string symbol, int ROM);
        int getAddress(string symbol);
        bool isAinstruction(string s);
        string int_array_to_string(int *binaryArray);
        string toBinary(int n);
        string transformAinstruction(string s);

    private:
        unordered_map<string,int> symboltable;
        int address;
};

#endif