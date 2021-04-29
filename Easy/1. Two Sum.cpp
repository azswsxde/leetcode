class Solution
{
    public:
        vector<int> twoSum(vector<int>& nums, int target)
        {
            int ichecknum = 0;
            int ipos_1 = 0, ipos_2 = 0;
            bool done = false;
     
            // like selection sort algorithm to find val 
            // val = target - nums[ipos_1] 
            while (ipos_1 < nums.size())
            {
                ichecknum = target - nums[ipos_1];
                for (int i = ipos_1 + 1; i < nums.size(); i++)
                {
                    if (ichecknum == nums[i])
                    {
                        ipos_2 = i;
                        done = true;
                        break;
                    }
                }
                if (done)
                {
                    break;
                }
                ipos_1++;
            }
     
            //create a vector return as answer 
            vector<int> result;
            result.push_back(ipos_1);
            result.push_back(ipos_2);
            return result;
        }
};
 
// i thought can use binary search algorithm to optimize it
