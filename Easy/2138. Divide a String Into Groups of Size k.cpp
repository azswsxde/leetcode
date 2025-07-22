class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> result;
        int string_len = s.length();
        unsigned short i = 0, count = 0;
        string temp = "";
        if (string_len <= k)
        {
            for (i = 0; i < (k - string_len); i++)    
                s += fill;
            result.push_back(s);
            return result;
        }

        for (i = 0; i < string_len; i++){
            if (k == count) {
                result.push_back(temp);
                temp = "";
                count = 0;
            }
            temp += s[i];
            count++;
        }

        for (i = 0; i < (k - count); i++)    
            temp += fill;
        result.push_back(temp);

        return result;
    }
};