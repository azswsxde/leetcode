class Solution {
public:
    int hammingWeight(int n) {
        switch (n) {
            case 3:
            case 5:
            case 6:
                return 2;
            case 1:
            case 2:
            case 4:
                return 1;
            case 0:
                return 0;
            default:
                break;
        }
        unsigned short count = 0;
        while (n > 0) {
            if ((n & 1))
                count++;
            n = n >> 1;
            switch (n) {
                case 3:
                case 5:
                case 6:
                    return (count + 2);
                case 1:
                case 2:
                case 4:
                    return (count + 1);
                case 0:
                    return count;
                default:
                    break;
            }
        }
        return count;
    }
};