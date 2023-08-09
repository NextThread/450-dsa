class Solution
{
public:
    vector<int> nextPermutation(int N, vector<int> arr)
    {
        next_permutation(arr.begin(), arr.end());
        vector<int> res = arr;
        return res;
    }
};
