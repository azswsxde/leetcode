class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0, idx = s.length() - 1;
        while(s[idx] == ' ') {
            idx--;
        }

        while(idx > -1 && s[idx] != ' ') {
            idx--;
            length++;
        }

        return length;
    }
};