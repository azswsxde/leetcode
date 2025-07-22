class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result;
        if (n == 0) {
            result.push_back(0);
            return result;
        }
        if (n == 1) {
            result.push_back(0);
            result.push_back(1);
            return result;
        }
        result.push_back(0);
        result.push_back(1);
        int check_point = 2, point_de_count = 2;
        for (int i = 2; i <= n; i++) {
            result.push_back(1 + result[check_point - point_de_count]);
            point_de_count--;
            if (point_de_count == 0){
                check_point *= 2;
                point_de_count = check_point;
            }
        }
        return result;
    }
};