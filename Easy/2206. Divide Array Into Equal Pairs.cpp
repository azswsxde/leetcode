class Solution {
public:
    bool divideArray(vector<int>& nums) {
        map<unsigned short, unsigned short> temp;
        for (unsigned short i = 0; i < nums.size(); i++) {
            temp[nums[i]]++;

        }

        for (map<unsigned short, unsigned short>::iterator it=temp.begin(); it!=temp.end(); ++it)
            if (it->second & 1)
                return false;
        return true;
    }
};