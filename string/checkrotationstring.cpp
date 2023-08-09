#include<bits/stdc++.h>
using namespace std;
bool isrotation(string s1, string s2)
{
    s2 += s2;
    if(s2.find(s1) != string::npos) return true;
    return false;
}