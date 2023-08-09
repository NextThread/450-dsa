class Solution
{
public:
    void threeWayPartition(vector<int> &array, int a, int b)
    {
        // Dutch National Flag Algorithm
        int lo = 0, hi = array.size() - 1, mid = 0;
        while (mid <= hi)
        {
            if (array[mid] < a)
            {
                swap(array[lo], array[mid]);
                lo++;
                mid++;
            }
            else if (a <= array[mid] && array[mid] <= b)
            {
                mid++;
            }
            else
            {
                swap(array[mid], array[hi]);
                hi--;
            }
        }
    }
};