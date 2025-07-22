class Solution {
public:
    int scoreOfString(string s) {
        int result = 0;
        for (unsigned short i = 0; i < s.length() - 1; i++) {
            result += abs(s[i] - s[i + 1]);
        }
        return result;
    }
};  