class Solution {
public:
    void getvalue(vector<string>& result) {

        return;
    }
    vector<string> letterCombinations(string digits) {
        vector<string> key = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> result;
        unsigned short digits_len = digits.length(), i, j;
        vector<unsigned short> count, len, key_idx;
        string s_temp, ss_temp;
        if (digits_len == 0)
            return result;
        
        if (digits_len == 1) {
            key_idx.push_back((unsigned short)(digits[i]-'2'));
            for (i = 0; i < key[key_idx[0]].length(); i++) {
                s_temp = key[key_idx[0]][i];
                result.push_back(s_temp);
            }
            return result;
        }            

        for (i = 0; i < digits_len; i++) {
            key_idx.push_back((unsigned short)(digits[i]-'2'));
            count.push_back(0);
            len.push_back(key[key_idx[i]].length());
        }

        while (count[0] < len[0]) {
            s_temp = "";
            for (i = 0; i < digits_len; i++) {
                s_temp += key[key_idx[i]][count[i]];
            }

            result.push_back(s_temp);
            count[digits_len - 1]++;
            for (i = (digits_len - 1); i > 0; i--) {
                if (count[i] == len[i]) {
                    count[i - 1]++;
                    count[i] = 0;
                }
            }
        }
        return result;
    }
};