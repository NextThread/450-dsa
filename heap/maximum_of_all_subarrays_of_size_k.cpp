class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> res;
        deque<int> dq;
        for (int itr = 0; itr < nums.size(); itr++)
        {
            // removing the index which is going out of our window
            if (!dq.empty() && dq.front() == itr - k)
                dq.pop_front();
            // pop till the coming element is greater
            while (!dq.empty() && nums[dq.back()] < nums[itr]) // we need max of each subarray, so keep popping the minimums
            {
                dq.pop_back();
            }
            dq.push_back(itr);
            // since we are iterating from 0th index that's why this if condition
            if (itr >= k - 1)
                res.push_back(nums[dq.front()]);
        }
        return res;
    }
};