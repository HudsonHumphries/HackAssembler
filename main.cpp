#include <fstream>
#include <iostream>
#include <string>
#include "helper.h"
using namespace std;

int main(int argc, char **argv) {
    cout << argv[1] << endl;
    string line;
    ifstream myfile(argv[1]);
    ofstream myfile2("middle.asm");
    if(myfile.is_open()) {
        while(getline(myfile,line)) {
            if(emptyLine(line) == false && !(line[0] == '/' && line[1] == '/')) {
                myfile2 << line << endl;
                //Add to file?
            }
            else {
                //if label, symboltable
            }
            
        }
        myfile.close();
        myfile2.close();
    }
}