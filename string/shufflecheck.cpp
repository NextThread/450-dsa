bool yes(string a, string b, string c)
{
    if(a.length() != b.length()+c.length()) return false;
    string bc = b+c;
    sort(bc.begin(), bc.end());
    sort(begin(a), end(a));
    return a == bc;
}