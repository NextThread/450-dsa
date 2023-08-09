class Solution
{
public:
    bool ispalindrome(string s)
    {
        string rev = s;
        reverse(rev.begin(), rev.end());
        return rev == s;
    }

    string longestPalindrome(string s)
    {
        int best_len = 0;
        string best_str = "";
        int n = s.length();
        for (int L = 0; L < n; L++)
        {
            for (int R = L; R < n; R++)
            {
                int len = R - L + 1;
                string curr = s.substr(L, len);
                if (ispalindrome(curr) and best_len < len)
                {
                    best_str = curr;
                    best_len = len;
                }
            }
        }
        return best_str;
    }
};

/* optimized more */

class Solution
{
public:
    bool ispalindrome(const string &s)
    {
        int L = 0, R = s.length() - 1;
        while (L <= R)
        {
            if (s[L] != s[R])
                return false;
            L++;
            R--;
        }
        return true;
    }

    string longestPalindrome(string s)
    {
        int best_len = 0;
        string best_str = "";
        int n = s.length();
        for (int L = 0; L < n; L++)
        {
            for (int R = L; R < n; R++)
            {
                int len = R - L + 1;
                string curr = s.substr(L, len);
                if (ispalindrome(curr) and best_len < len)
                {
                    best_str = curr;
                    best_len = len;
                }
            }
        }
        return best_str;
    }
};

// /* more optimized    ----using binary search*/  accepted

class Solution
{
public:
    bool ispalindrome(const string &s)
    {
        int L = 0, R = s.length() - 1;
        while (L <= R)
        {
            if (s[L] != s[R])
                return false;
            L++;
            R--;
        }
        return true;
    }

    int good(int x, string s)
    {
        for (int L = 0; L + x <= s.length(); L++)
        {
            if (ispalindrome(s.substr(L, x)))
                return L;
        }
        return -1;
    }

    string longestPalindrome(string s)
    {
        int best_len = 0;
        string best_str = "";
        int n = s.length();
        for (int parity : {0, 1})
        {
            int lo = 1, hi = n;
            if (lo % 2 != parity)
                lo++;
            if (hi % 2 != parity)
                hi--;
            while (lo <= hi)
            {
                int mid = (lo + hi) >> 1;
                if (mid % 2 != parity)
                    mid++;
                if (mid > hi)
                    break;
                int temp = good(mid, s);
                if (temp != -1)
                {
                    if (mid > best_len)
                    {
                        best_len = mid;
                        best_str = s.substr(temp, mid);
                    }
                    lo = mid + 2;
                }
                else
                {
                    hi = mid - 2;
                }
            }
        }
        return best_str;
    }
};

// /* most optimized solution*/ accepted


class Solution
{
public:
    string longestPalindrome(string s)
    {
        int best_len = 0;
        string best_str = "";
        int n = s.length();
        for (int mid = 0; mid < n; mid++)
        {
            for (int x = 0; mid - x >= 0 and mid + x < n; ++x)
            {
                if (s[mid - x] != s[mid + x])
                    break;
                int len = 2 * x + 1;
                if (len > best_len)
                {
                    best_len = len;
                    best_str = s.substr(mid - x, len);
                }
            }
        }
        for (int mid = 0; mid < n - 1; mid++)
        {
            for (int x = 1; mid - x + 1 >= 0 and mid + x < n; x++)
            {
                if (s[mid - x + 1] != s[mid + x])
                    break;
                int len = 2 * x;
                if (len > best_len)
                {
                    best_len = len;
                    best_str = s.substr(mid - x + 1, len);
                }
            }
        }
        return best_str;
    }
};