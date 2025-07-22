class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        short bin_len = nums.size();
        string result = "";
        if (bin_len < 3)
        {
            if (bin_len == 1)
            {
                if (nums[0] == "1")
                    return "0";
                else
                    return "1";
            }
            else
            {
                bool a = false, b = false, c = false, d = false;
                for (short i = 0; i < bin_len; i++) {
                    if (nums[i] == "00")
                        a = true;
                    if (nums[i] == "01")
                        b = true;
                    if (nums[i] == "10")
                        c = true;
                    if (nums[i] == "11")
                        d = true;
                }
                if (!a)
                    return "00";
                if (!b)
                    return "01";
                if (!c)
                    return "10";
                if (!d)
                    return "11";
            }
        }
        short* xor_arr;
        xor_arr = new short[bin_len];
        for (short i = 0; i < bin_len; i++) {
            if (nums[0][i] == '0')
                xor_arr[i] = -1;
            else
                xor_arr[i] = 1;

            for (short j = 1; j < bin_len; j++) {
                if (nums[j][i] == '0')
                    xor_arr[i] -= 1;
                else
                    xor_arr[i] += 1;
            }
            if (xor_arr[i] > 0)
                result += "0";
            else if (xor_arr[i] < 0)
                result += "1";
            else
                result += ((i % (bin_len - 1) & 1) == 0 ? "0" : "1");
        }
        for (short i = 0; i < bin_len; i++) {
            if (nums[i] == result) {
                for (short j = 0; j < (bin_len / 2); j++) {
                    char temp = result[j];
                    result[j] = result[bin_len - j - 1];
                    result[bin_len - j - 1] = temp;
                }
                break;
            }
        }
        delete [] xor_arr;
        return result;
    }
};