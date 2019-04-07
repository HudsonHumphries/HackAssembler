#include "cinsHelp.h"
#include <string>
#include <iostream>
using namespace std;


cinsHelp::cinsHelp() {
    dest[""] = "000";
    dest["M"] = "010";
    dest["D"] = "011";
    dest["MD"] = "100";
    dest["A"] = "100";
    dest["AM"] = "101";
    dest["AD"] = "110";
    dest["AMD"] = "111";

    comp["0"] = "0101010";
    comp["1"] = "0111111";
    comp["-1"] ="0111010";
    comp["D"] = "0001100";
    comp["A"] = "0110000";
    comp["M"] = "1110000";
    comp["!D"] ="0001101";
    comp["!A"] ="0110001";
    comp["!M"] ="1110001";
    comp["-D"] ="0001111";
    comp["-A"] ="0110011";
    comp["-M"] ="1110011";
    comp["D+1"]="0011111";
    comp["A+1"]="0110111";
    comp["M+1"]="1110111";
    comp["D-1"]="0001110";
    comp["A-1"]="0110010";
    comp["M-1"]="1110010";
    comp["D+A"]="0000010";
    comp["D+M"]="1000010";
    comp["D-A"]="0010011";
    comp["D-M"]="1010011";
    comp["A-D"]="0000111";
    comp["M-D"]="1000111";
    comp["D&A"]="0000000";
    comp["D&M"]="1000000";
    comp["D|A"]="0010101";
    comp["D|M"]="1010101";

    jump[""] =  "000";
    jump["JGT"]="001";
    jump["JEG"]="010";
    jump["JGE"]="011";
    jump["JLT"]="100";
    jump["JNE"]="101";
    jump["JLE"]="110";
    jump["JMP"]="111";

    compstring = "";
    deststring = "";
    jumpstring = "";
}       
bool cinsHelp::isCompBits(string cstring) {
    if(comp.find(cstring) != comp.end()) return true;
    return false;
}
bool cinsHelp::isDestBits(string dstring) {
    if(dest.find(dstring) != dest.end()) return true;
    return false;
}
bool cinsHelp::isJumpBits(string jstring) {
    if(jump.find(jstring) != jump.end()) {
        return true;
    } 
    else {
        return false;
    }
}

bool cinsHelp::isCinstruction(string instruction) {
    compstring = "";
    deststring = "";
    jumpstring = "";
    int i;
    i = 0;
    while(instruction[i] != '=' && instruction[i] != ';') {
        deststring += instruction[i];
        i++;
    }
    int j;
    j = i;
    if(instruction[j] == '=') {
        j++;
        //This means that there is a comp feature
        while(instruction[j] != '\0'){
            if(instruction[j] == ';') {
                break;
            }
            compstring += instruction[j];
            j++;
        }
        if(instruction[j]==';') {
            j++;
            //There is a jump and comp
            while(instruction[j] != '\0') {
                jumpstring += instruction[j];
                j++;
            }

        }
    }
    else if(instruction[j] = ';') {
        //This means that there is only a dest and a jump in the Cinstruction
        j++;
        while(instruction[j] != '\0'){
            jumpstring += instruction[j];
            j++;
        }
    }
    else {
        //This means there is no comp or jump
        return false;

    }
    if(isspace(compstring[compstring.size()-1])) compstring.pop_back();
    if(isspace(jumpstring[jumpstring.size()-1])) jumpstring.pop_back();
    if(isspace(deststring[deststring.size()-1])) deststring.pop_back();

    if(isCompBits(compstring) && isJumpBits(jumpstring) && isDestBits(deststring)) return true;

    return false;
}