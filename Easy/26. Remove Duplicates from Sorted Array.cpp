class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 1)
            return 1;
        
        int count = 0;
        for (unsigned short i = 0; i < nums.size() - 1;) {
            if (nums[i] == nums[i + 1])
                nums.erase(nums.begin() + i + 1);
            else {
                i++;
                count++;
            }
        }

        if (nums.size() == 1)
            return 1;

        if (nums[nums.size() - 1] != nums[nums.size() - 2])
            count++;
        return count;
    }
};