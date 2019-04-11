#include "SymbolTable.h"
#include <string>
#include <iostream>
using namespace std;

SymbolTable::SymbolTable() {
    symboltable["SP"] = 0;
    symboltable["LCL"] = 1;
    symboltable["ARG"] = 2;
    symboltable["THIS"] = 3;
    symboltable["THAT"] = 4;
    symboltable["R0"] = 0;
    symboltable["R1"] = 1;
    symboltable["R2"] = 2;
    symboltable["R3"] = 3;
    symboltable["R4"] = 4;
    symboltable["R5"] = 5;
    symboltable["R6"] = 6;
    symboltable["R7"] = 7;
    symboltable["R8"] = 8;
    symboltable["R9"] = 9;
    symboltable["R10"] = 10;
    symboltable["R11"] = 11;
    symboltable["R12"] = 12;
    symboltable["R13"] = 13;
    symboltable["R14"] = 14;
    symboltable["R15"] = 15;
    symboltable["SCREEN"] = 16384;
    symboltable["KBD"] = 24576;
    address = 16;
}
bool SymbolTable::contains(string symbol) {
    if(symboltable.find(symbol) != symboltable.end()) return true;
    return false;
}
void SymbolTable::addSymbol(string symbol) {
    symboltable[symbol] = address;
    address++;
}
void SymbolTable::addLabel(string label, int ROM) {
    symboltable[label] = ROM;
}
int SymbolTable::getAddress(string symbol) {
    return symboltable[symbol];
}
//Maniplufating A instructions
bool SymbolTable::isAinstruction(string s) {
    if(s[0] == '@') {
        return true;
    }

    return false;
}
string SymbolTable::int_array_to_string(int *binaryArray) {
    string binarystring = "";
    int temp = 15;
    for(int x =temp; x>=0; x--) {
        binarystring += to_string(binaryArray[x]);
    }
    //cout << binarystring << endl;;
    //cout << binarystring.size() << endl;
    //binarystring.push_back('\n');
    return binarystring;
}
string SymbolTable::toBinary(int n) {
    int num = n;
    // array to store binary number 
    int binaryNum[16]; 
    // counter for binary array 
    int i = 0; 
    while (num > 0) { 
        // storing remainder in binary array 
        binaryNum[i] = num % 2; 
        num = num / 2; 
        i++; 
    } 
    for(int j = 15; j > i-1; j--) {
        binaryNum[j] = 0;
    }
    return int_array_to_string(binaryNum);
}   
string SymbolTable::transformAinstruction(string s) {
    string ainstruct=s.substr(1,s.size());
    //cout << ainstruct << endl;
    ainstruct.pop_back();
    if(isdigit(s[1])) { //If @<#>
        string binarynum = s.substr(1,s.size());
        int binary = stoi(binarynum);
        return toBinary(binary);  
    }
    else if(contains(ainstruct)) { //@Label or @Symbol that is already in the table
        int address = getAddress(ainstruct);
        //cout << address << endl;
        return toBinary(address);
    }
    else {//add symbol to symboltable
        //cout << s << endl;
        addSymbol(ainstruct);
        int address2 = getAddress(ainstruct);
        return toBinary(address2);
    }  
}