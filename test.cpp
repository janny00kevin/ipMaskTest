#include "string_split.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string s = "192.168.0.1";
    vector<string> v = split(s, "s");
    for(auto& i : v){
        cout << i << endl;
    }
}