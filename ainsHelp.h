#include <fstream>
#include <iostream>
#include <string>
using namespace std;

bool isAinstruction(string s) {
    if(s[0] == '@') {
        return true;
    }

    return false;
}
string int_array_to_string(int *binaryArray) {
    string binarystring = "";
    int temp = 15;
    for(int x =temp; x>=0; x--) {
        binarystring += to_string(binaryArray[x]);
    }
    cout << binarystring << endl;;
    return binarystring;
}

string toBinary(int n) {
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

string transformAinstruction(string s) {
    string binarynum = s.substr(1,s.size());
    int binary = stoi(binarynum);
    return toBinary(binary);  
}