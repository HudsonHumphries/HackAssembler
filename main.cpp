#include <fstream>
#include <iostream>
#include <string>
#include "fileHelp.h"
#include "ainsHelp.h"
#include "cinsHelp.h"
using namespace std;

int main(int argc, char **argv) {
    string line;
    ifstream myfile(argv[1]);
    ofstream middlefile("middle.asm");
    if(myfile.is_open()) {
        while(getline(myfile,line)) {
            if(emptyLine(line) == false && !(isComment(line))) {
                middlefile << line << endl;
                //Add to file?
            }
            else {
                //if label, symboltable
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
            string binaryTransform;
            if(isAinstruction(line2)) {
                binaryTransform = transformAinstruction(line2);
                outfile << binaryTransform << "\n";
            }
            else if(c.isCinstruction(line2)){
                cout << "CINSTRUCTION" << endl;
            }
            else {
                cout << "NOTCORA" << endl;
            }
        }
    }
}