class Solution
{
    public:
        int searchInsert(vector<int>& nums, int target)
        {
        	// start from index 0 check if target less or equal then nums[i]
        	// return index as answer
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] >= target)
                {
                    return i;
                }
            }
            // if target large then all numbers in vector
            // return nums.size()
            return nums.size();
        }
};
// i thought can use binary search algorithm to optimize it
