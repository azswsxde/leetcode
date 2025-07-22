class Solution {
public:
    int reverseBits(int n) {
        int temp = 0;
        for(unsigned short i = 0; i < 32; i++){
            cout << (n & 1);
            temp = (temp << 1) + (n & 1);
            n = (n >> 1);
        }

        return temp;
    }
};