class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        else if (x < 10)
            return true;
        else {
            string temp = to_string(x);
            size_t len = temp.length();
            for (size_t i = 0; i < (len/2) ; i++)
            {
                if (temp[i] != temp[len - 1 -i])
                    return false;
            }
            return true;
        }
    }
};