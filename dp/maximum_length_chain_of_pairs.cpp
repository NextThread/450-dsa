class Solution
{
public:
    static bool comp(pair<int, int> a, pair<int, int> b)
    {
        return a.second < b.second;
    }

    int maxChainLen(struct val p[], int n)
    {
        vector<pair<int, int>> vp;
        for (int i = 0; i < n; i++)
        {
            vp.push_back({p[i].first, p[i].second});
        }
        sort(vp.begin(), vp.end(), comp);
        int i = 0, j = 1, cnt = 1;
        while (j < n)
        {
            if (vp[i].second < vp[j].first)
            {
                cnt++;
                i = j;
                j++;
            }
            else
                j++;
        }
        return cnt;
    }
};