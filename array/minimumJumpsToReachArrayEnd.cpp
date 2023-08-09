class Solution
{
public:
    int minJumps(int arr[], int n)
    {
        int far = 0, curr = 0, jump = 0;
        for (int i = 0; i < n - 1; i++)
        {
            far = max(far, i + arr[i]); // the max jump that we can from curr index
            if (i == curr)
            {
                jump++;     // if we did the maximum length jump
                curr = far; // set our curr to max jump length
            }
        }
        if (curr < n - 1)
            return -1; // we're unable to reach the end
        return jump;
    }
};