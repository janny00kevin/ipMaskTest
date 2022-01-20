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
    }
    return vInt;
}

vector<int> andOperator(vector<int>& ipVect, vector<int> mask){
    vector<int> v;
    try
    {
        if (ipVect.size() != mask.size())  throw 99;
    }
    catch(int x)
    {
        cerr << "Ip size and mask size doesn't match!\n";
        // return
    }

    for (size_t i = 0; i < mask.size(); i++)
    {
        v.push_back(ipVect.at(i) & mask.at(i));
    }

    return v;
}

bool ipMask(string ipChar1 = "192.168.0.1", string ipChar2 = "192.168.1.2")
{
    string ip1 = ipChar1, ip2 = ipChar2;
    string mask = "255.255.255.0";
    vector<string> vStr1, vStr2, vMaskStr;
    vStr1 = split(ip1, ".");
    vStr2 = split(ip2, ".");
    vMaskStr = split(mask, ".");
    vector<int> ipVect1, ipVect2, maskVect;
    ipVect1 = transStr2Int(vStr1);
    ipVect2 = transStr2Int(vStr2);
    maskVect = transStr2Int(vMaskStr);
    vector<int> v1, v2;
    v1 = andOperator(ipVect1, maskVect);
    v2 = andOperator(ipVect2, maskVect);
    if (v1 == v2)  return 1;
    else  return 0;
}

int main(int argc, char *argv[])
{
    //if (argc == 0)
        if(ipMask())
            cout << "these 2 ips are in the same subnetwork.\n";
        else
            cout << "these 2 ips are NOT in the same subnetwork.\n";

    return 0;
}