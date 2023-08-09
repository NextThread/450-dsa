class Solution
{
public:
    void f(string &S)
    {
        if (S.size() == 1)
        {
            return;
        }

        char ch = S[S.size() - 1];
        S.pop_back();
        f(S);
        if (S[S.size() - 1] != ch)
        {
            S.push_back(ch);
        }
        return;
    }

    string removeConsecutiveCharacter(string S)
    {
        /*  Using Prefix Array  */
        // string res = "";
        // res += S[0];
        // for(int i = 1 ; i < S.length() ; i++)
        // {
        //     if(res.back() != S[i]) res += S[i];
        // }
        // return res;

        f(S);
        return S;
    }
};