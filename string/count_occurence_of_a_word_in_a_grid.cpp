int xDR[] = {-1, 1, 0, 0};
int yDR[] = {0, 0, -1, 1};
int dfs(string needle, vector<string> &haystack, int x, int y)
{
    int size = needle.size();
    for (int i = 0; i < 4; i++)
    {
        int newX = x + xDR[i];
        int newY = y + yDR[i];
        int j = 1;
        for (j = 1; j < size; j++)
        {
            if (newX < 0 or newY < 0 or newX >= haystack.size() or newY >= haystack[0].size())
                break;
            if (needle[j] != haystack[newX][newY])
                break;
            newX += xDR[i];
            newY += yDR[i];
        }
        if (j == size)
            return true;
    }
    return false;
}
int count(string needle, vector<string> &haystack)
{
    int r = haystack.size();
    int c = haystack[0].size();
    int cnt = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            if (haystack[i][j] == needle[0])
                cnt += dfs(needle, haystack, i, j);
    }
    return cnt;
}