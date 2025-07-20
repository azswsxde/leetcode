class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        unsigned short i = 0, j = 0, nums1_len = nums1.size(), nums2_len = nums2.size();
        vector<vector<int>> result;
        while(true) {
            if (i < nums1_len && j < nums2_len) {
                if (nums1[i][0] > nums2[j][0]) {
                    result.push_back(nums2[j]);
                    j++;
                }
                else if (nums1[i][0] < nums2[j][0]) {
                    result.push_back(nums1[i]);
                    i++;
                }
                else {
                    result.push_back({nums2[j][0], (nums2[j][1] + nums1[i][1])});
                    i++; j++;
                }
            }
            if (i == nums1_len) {
                for (;j < nums2_len; j++)
                    result.push_back(nums2[j]);
            }
            if (j == nums2_len && i < nums1_len) {
                for (;i < nums1_len; i++)
                    result.push_back(nums1[i]);
            }
            if (i >= nums1_len && j >= nums2_len)
                break;
        }
        return result;
    }
};