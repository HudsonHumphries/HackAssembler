#include <fstream>
#include <iostream>
#include <string>
#include "fileHelp.h"
#include "cinsHelp.h"
#include "SymbolTable.h"
using namespace std;

int main(int argc, char **argv) {
    string line;
    int ROM = 0;
    SymbolTable s;
    ifstream myfile(argv[1]);
    ofstream middlefile("middle.asm");
    if(myfile.is_open()) {
        while(getline(myfile,line)) {
            string myString = removeSpacesAndComments(line);
            if(isLabel(myString)) {
                //Add label to symboltable with ROM value
                string label = remove_parentheses(myString);
                s.addLabel(label,ROM);  //Adds label with the line value that it was at already
            }
            else if(!emptyLine(myString)){
                //Not a label, so moves on to intermediate file
                middlefile << myString << endl;
                cout << myString << endl;
                ROM++; //ROM address only updates when the line is a A or C instruction
            }
        }
        myfile.close();
        middlefile.close();
    }
    cinsHelp c;
    ifstream middlefile2("middle.asm");
    string finalfile = changefilename(argv[1]);
    ofstream outfile(finalfile);
    string line2;
    if(middlefile2.is_open()) {
        while(getline(middlefile2,line2)) {
            if(s.isAinstruction(line2)) {
                
                outfile << s.transformAinstruction(line2) << endl;
            }
            else if(c.isCinstruction(line2)){
                outfile << c.CinstructionToBits() << endl;
                cout << c.CinstructionToBits() << endl;
            }
            else {
                cerr << "A line was not a A or C instruction" << endl;
            }
        }
    }
}