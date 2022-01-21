#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "string_split.h"

using namespace std;

vector<int> transStr2Int(vector<string>& vStr)
{
    int tmp;
    vector<int> vInt;
    stringstream ss;
    for (size_t i = 0; i < vStr.size(); i++)
    {
        ss << vStr.at(i);
        ss >> tmp;
        vInt.push_back(tmp);

        ss.str("");
        ss.clear();
    }
    return vInt;
}

vector<int> andOp4vect(vector<int>& ipVect, vector<int> mask){
    vector<int> v;
    try
    {
        if (ipVect.size() != mask.size())  throw 99;
    }
    catch(int x)
    {
        cerr << "Ip size and mask size doesn't match!\n";
        return v;
    }

    for (size_t i = 0; i < mask.size(); i++)
    {
        v.push_back(ipVect.at(i) & mask.at(i));
    }

    return v;
}

bool ipMaskCompare(string ipChar1 = "192.168.0.1", string ipChar2 = "192.168.1.2", string mask = "255.255.255.0")
{
    string ip1 = ipChar1, ip2 = ipChar2;
    ;
    vector<string> vStr1, vStr2, vMaskStr;
    vStr1 = split(ip1, ".");
    vStr2 = split(ip2, ".");
    vMaskStr = split(mask, ".");
    vector<int> ipVect1, ipVect2, maskVect;
    ipVect1 = transStr2Int(vStr1);
    ipVect2 = transStr2Int(vStr2);
    maskVect = transStr2Int(vMaskStr);
    vector<int> v1, v2;
    v1 = andOp4vect(ipVect1, maskVect);
    v2 = andOp4vect(ipVect2, maskVect);
    // for (size_t i = 0; i < vStr1.size(); i++)
    // {
    //     cout << "v1: " << ipVect1.at(i) << ", v2: " << ipVect2.at(i) << endl;
    // }
    
    if (v1 == v2)  return 1;
    else  return 0;
}

int main(int argc, char *argv[])
{
    // cout << argv[0];
    // if (argc == 1)
    //     if (ipMaskCompare())
    //         cout << "these 2 ips are in the same subnetwork.\n";
    //     else
    //         cout << "these 2 ips are NOT in the same subnetwork.\n";
    // else if(argc == 3)
        if (ipMaskCompare(argv[1], argv[2], argv[3]))
            cout << "these 2 ips are in the same subnetwork.\n";
        else
            cout << "these 2 ips are NOT in the same subnetwork.\n";

        
        
        

    return 0;
}