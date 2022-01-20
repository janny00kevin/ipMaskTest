#include "string_split.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main(){
    string s = "192.168.0.1";
    int tmp;
    vector<string> vStr = split(s, "s");
    vector<int> vInt;
    stringstream ss;
    for (size_t i = 0; i < s.size(); i++)
    {
        ss << vStr.at(i);
        ss >> tmp;
        vInt.push_back(tmp);
    } 
    
    

}