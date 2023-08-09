vector<int> replaceElements(vector<int> &nums, int mx = -1)
{
    for (int i = nums.size() - 1; i >= 0; --i)
        mx = max(mx, exchange(nums[i], mx));
    return nums;
}
// exchange(x, y).... update x values to y
// eg.   x = 20, y = 30. exchange(x, y). now x becomes 30