class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        short n = matrix[0].size(), m = matrix.size();
        std::vector<std::pair<short, short>> vec;
        for (short i = 0; i < m; i++) {
            for (short j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    vec.push_back({i, j});
                }
            }
        }

        for (int k = 0; k < vec.size(); k++) {
            for (short i = 0; i < m; i++) {
                matrix[i][vec[k].second] = 0;
            }
            for (short i = 0; i < n; i++) {
                matrix[vec[k].first][i] = 0;
            }
        }
    }
};