class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        for (unsigned short i = 0; i < nums.size();) {
            if (nums[i] == val)
                nums.erase(nums.begin() + i);
            else {
                i++;
                count++;
            }
        }
        return count;
    }
};