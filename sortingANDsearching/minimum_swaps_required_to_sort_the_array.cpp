class Solution
{
public:
    int minSwaps(vector<int> &nums)
    {
        vector<int> n = nums;
        sort(n.begin(), n.end());
        unordered_map<int, int> umap;
        for (int i = 0; i < n.size(); i++)
            umap[n[i]] = i;
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (umap[nums[i]] == i)
                continue;
            else
            {
                count++;
                swap(nums[i], nums[umap[nums[i]]]);
                i--;
            }
        }
        return count;
    }
};