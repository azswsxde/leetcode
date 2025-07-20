class Solution {
public:
    void sortColors(vector<int>& nums) {
        short lastindex0 = -1;
        vector<int> nums_temp;
        for (short i = 0; i < nums.size(); i++) {
            switch (nums[i]) {
                case 0:
                    if (lastindex0 == -1) {
                        nums_temp.insert(nums_temp.begin(), 0);
                        lastindex0 = 0;
                    }
                    else {
                        nums_temp.insert(nums_temp.begin(), 0);
                        lastindex0++;
                    }
                    break;
                case 1:
                    if (lastindex0 == -1)
                        nums_temp.insert(nums_temp.begin(), 1);
                    else
                        nums_temp.insert(nums_temp.begin() + lastindex0 + 1, 1);
                    break;
                default:
                    nums_temp.push_back(2);
                    break;
            }
        }

        for (short i = 0; i < nums_temp.size(); i++) {
            nums[i] = nums_temp[i];
        }
    }
};