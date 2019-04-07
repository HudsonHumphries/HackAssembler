#include "cinsHelp.h"
#include <string>
#include <iostream>
using namespace std;


cinsHelp::cinsHelp() {
    dest[""] = "000";
    dest["M"] = "001";
    dest["D"] = "010";
    dest["MD"] = "011";
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
void cinsHelp::split(string instruction) {
    //Test to see which of our strings should be present in the line
    bool equals = false;
    bool semicolon = false;
    for(int i = 0; i < instruction.size(); i++) {
        if(instruction[i] == '=') equals = true;
        if(instruction[i] == ';') semicolon = true;
    }
    //If both are true, then there should be all 3 in the string
    if(equals && semicolon) {
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

        }
    }
    else if(equals && !semicolon) { //There is an equals sigh and no semicolon, meaning there should be no JUMP
        int i = 0;
        while(instruction[i] != '=') {
            deststring += instruction[i];
            i++;
        }
        int j;
        j = i;
        if(instruction[j] == '=') {
            j++;
            //This means that there is a comp feature
            while(instruction[j] != '\0'){
                compstring += instruction[j];
                j++;
            }

        }
    }
    else if(semicolon && !equals) { //There is no equals and a semicolon, so there is no dest only a comp and a JUMP
        int i = 0;
        while(instruction[i] != ';') {
            compstring += instruction[i];
            i++;
        }
        int j;
        j = i;
        if(instruction[j] == ';') {
            j++;
            //This means that there is a comp feature
            while(instruction[j] != '\0'){
                jumpstring += instruction[j];
                j++;
            }

        }
    }
    
}
//need to check between jump or not, if there is no equals then there is only a comp and jump
bool cinsHelp::isCinstruction(string instruction) {
    compstring = "";
    deststring = "";
    jumpstring = "";
    split(instruction);

    if(isspace(compstring[compstring.size()-1])) compstring.pop_back();
    if(isspace(jumpstring[jumpstring.size()-1])) jumpstring.pop_back();
    if(isspace(deststring[deststring.size()-1])) deststring.pop_back();
    /*
    Code was previously needed to trim bad algorithm, will keep here just incase it is needed
    if(jumpstring[0] == ';') {
        for(int i = 0; i < jumpstring.size()-1; i++){
            jumpstring[i] = jumpstring[i+1];
        }
        jumpstring.pop_back();
    } */
    /*cout << "comp: " << compstring << " " << compstring.size() << endl;
    cout << "jump: " << jumpstring << " " << jumpstring.size() << endl;
    cout << "dest: " << deststring << " " << deststring.size() << endl; */

    if(isCompBits(compstring) && isJumpBits(jumpstring) && isDestBits(deststring)) return true;

    return true;
}

string cinsHelp::CinstructionToBits() {
    string res = "111";
    res += comp[compstring];
    res += dest[deststring];
    res += jump[jumpstring];

    return res;
}