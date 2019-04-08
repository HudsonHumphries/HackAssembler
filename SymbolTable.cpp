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
void SymbolTable::addLabel(string label,int ROM) {
    symboltable[label] = ROM;
}
int SymbolTable::getAddress(string symbol) {
    return symboltable[symbol];
}