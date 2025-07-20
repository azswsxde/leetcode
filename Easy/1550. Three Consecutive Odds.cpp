class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        if (arr.size() < 3)
            return false;
        bool three_consecutive_odds = false;
        unsigned short count = 0;
        for (unsigned short i = 0; i < arr.size(); i++) {
            if (arr[i] & 1)
                count++;
            else
                count = 0;
            if (count == 3) {
                three_consecutive_odds = true;
                break;
            }
        }
        return three_consecutive_odds;
    }
};