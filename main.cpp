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

int main(int argc, char **argv) {
    cout << argv[1] << endl;
    string line;
    ifstream myfile(argv[1]);
    if(myfile.is_open()) {
        while(getline(myfile,line)) {
            if(emptyLine(line) == false && !(line[0] == '/' && line[1] == '/')) {
                cout << line << endl;
            }
            
        }
        myfile.close();
    }
}