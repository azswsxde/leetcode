class Solution {
public:
    bool isBalanced(string num) {
        int sum = 0;
        for (int i = 0; i < num.length(); i++) {
            if (i & 1) 
                sum -= (num[i] - 48);
            else {
                sum += (num[i] - 48);
            }
        }

        return (sum == 0);
    }
};