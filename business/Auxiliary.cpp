#include "Auxiliary.h"

vector<string> Split(string s, char symbol)
{
    vector<string> elems;
    stringstream ss(s);
    string item = "";
    while (getline(ss, item, symbol))
        elems.push_back(item);
    return elems;
}
