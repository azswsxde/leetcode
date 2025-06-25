class Solution {
public:
    int reverse(int x) {
        if (x > -10 && x < 10) {
            return x;
        }
        if (x == INT_MIN || x == INT_MAX)
            return 0;
        else {
            string temp = "";
            bool check = false;
            if (x < 0) {
                x = abs(x);
                check = true;
            }
            while((x / 10) > 0) {
                size_t last = x % 10;
                temp += (char)(last + 48);
                x = x / 10;
            }
            size_t last = x % 10;
            temp += (char)(last + 48);
            if (temp.length() == 10) {
                char test[11] = "2147483647";
                for (size_t i = 0; i < 9; i++) {
                    if (temp[i] > test[i])
                        return 0;
                    else if(temp[i] < test[i])
                        break;
                }
            }
            if (check)
                temp = "-" + temp;
            return atoi(temp.c_str());
        }
    }
};