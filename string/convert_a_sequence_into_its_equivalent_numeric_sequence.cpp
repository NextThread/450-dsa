#include <bits/stdc++.h>
using namespace std;

string keypad(string &s, string nums[], string &res)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ') // means entered space
            res += '0';
        else
        {
            int ind = s[i] - 'A';
            res += nums[ind];
        }
    }
    return res;
}

int main()
{
    string s;
    cin >> s;
    string res = "";
    string nums[] = {"2", "22", "222", "3", "33", "333", "4",
                     "44", "444", "5", "55", "555", "6", "66",
                     "666", "7", "77", "777", "7777", "8", "88",
                     "888", "9", "99", "999", "9999"};
    cout << keypad(s, nums, res);
}