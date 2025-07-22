class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        unsigned short n = matrix[0].size();
        int *max = new int[n];
        vector<vector<int>> marked_idx;
        for(int i = 0; i < matrix.size(); i++)
            for(int j = 0; j < n; j++){
                if (i == 0) {
                    max[j] = matrix[i][j];
                }
                else {
                    if (matrix[i][j] > max[j])
                        max[j] = matrix[i][j];
                }
                if (matrix[i][j] == -1)
                    marked_idx.push_back({i, j});
            }
        for (vector<int> idx : marked_idx)
            matrix[idx[0]][idx[1]] = max[idx[1]];
        return matrix;
    }
};