class Solution
{
public:
    bool subArrayExists(int arr[], int n)
    {
        unordered_set<int> st; // use set, map whatever you wish for
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (sum == 0)
                return true;
            if (st.count(sum))
                return true;
            st.insert(sum);
        }
        return false;
    }
};