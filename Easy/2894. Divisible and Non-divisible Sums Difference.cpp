class Solution {
public:
    int differenceOfSums(int n, int m) {
        int result = (n * (1 + n) / 2);
        unsigned short high = n / m;
        return (result - 2 * (high * (m + m * high) / 2));
    }
};