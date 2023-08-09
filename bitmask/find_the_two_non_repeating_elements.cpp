class Solution
{
public:
    vector<int> singleNumber(vector<int> nums)
    {
        int xorr = 0;
        for (auto it : nums)
            xorr ^= it;
        // xorr contains the xor of the two single element
        int setbit = xorr & ~(xorr - 1); // Find the right most one bit position using (xorSum & ~(xorSum-1))
        int a = 0, b = 0;                // two variables a and b which will strore the two non repeating elements
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] & setbit) // Traverse the array and if an element's AND with set_bit is 1, xor it with a else with b
                a ^= nums[i];
            else
                b ^= nums[i];
        }
        // a and b will finally hold the the two non repeating elements respectively
        if (a > b)
            swap(a, b);
        nums.clear();
        nums.push_back(a);
        nums.push_back(b);
        return nums;
    }
};
